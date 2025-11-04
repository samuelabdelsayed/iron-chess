//! # Iron Chess - Medieval 3D Chess Experience
//!
//! A cinematic chess game built with Rust and Bevy, featuring:
//! - Photorealistic medieval environment
//! - Battle animations every 3 captures
//! - 10-level AI opponent
//! - Endgame replay cinematics

use bevy::prelude::*;
use bevy::window::PrimaryWindow;
use bevy::input::mouse::MouseMotion;
use core_logic::{self, GameState, Position, ChessMove, Piece};

// Type alias to avoid confusion with Bevy's Color
type ChessColor = core_logic::Color;

// Helper trait for linear interpolation
trait Lerp {
    fn lerp(&self, other: Self, t: f32) -> Self;
}

impl Lerp for f32 {
    fn lerp(&self, other: Self, t: f32) -> Self {
        self + (other - self) * t
    }
}

fn main() {
    App::new()
        .add_plugins(DefaultPlugins.set(WindowPlugin {
            primary_window: Some(Window {
                title: "Iron Chess - Medieval Battlefield".to_string(),
                resolution: (1920.0, 1080.0).into(),
                ..default()
            }),
            ..default()
        }))
        // Game state management
        .init_state::<AppState>()
        .insert_resource(ChessGameState::new())
        .insert_resource(BattleCounter::default())
        .insert_resource(BattleAnimationState::default())
        .insert_resource(AIDifficulty(5))
        .insert_resource(CameraState::default())
        .insert_resource(MenuSelection::default())
        .insert_resource(PiecesSpawned::default())
        .insert_resource(SceneSpawned::default())
        .insert_resource(AIMoveTimer {
            timer: Timer::from_seconds(1.5, TimerMode::Once),
            pending_move: None,
        })
        // Startup systems
        .add_systems(Startup, (
            setup_camera,
            setup_lights,
        ))
        .add_systems(OnEnter(AppState::MainMenu), setup_main_menu)
        .add_systems(Update, handle_menu_interaction.run_if(in_state(AppState::MainMenu)))
        .add_systems(OnExit(AppState::MainMenu), cleanup_menu)
        .add_systems(OnEnter(AppState::PlayerTurn), (
            // setup_scene only once (SceneSpawned guards internally)
            setup_scene,
            // spawn pieces only if not already spawned
            spawn_chess_pieces,
            // Update camera to player's perspective
            update_camera_for_player,
        ))
        .add_systems(OnEnter(AppState::AIThinking), (
            update_camera_for_player,
        ))
        // Update systems based on state
        .add_systems(Update, (
            handle_mouse_click,
            update_piece_positions,
            update_highlights,
            check_for_ai_turn,
        ).run_if(in_state(AppState::PlayerTurn)))
        .add_systems(Update, camera_controls.run_if(in_state(AppState::PlayerTurn)))
        .add_systems(Update, handle_undo_input.run_if(in_state(AppState::PlayerTurn)))
        .add_systems(Update, (
            ai_thinking_system,
            ai_move_delay_system,
        ).run_if(in_state(AppState::AIThinking)))
        .add_systems(Update, (
            animate_battle_sequence,
        ).run_if(in_state(AppState::BattleAnimation)))
        .add_systems(Update, (
            replay_director_system,
        ).run_if(in_state(AppState::Replay)))
        .add_systems(OnEnter(AppState::Checkmate), setup_game_over_screen)
        .add_systems(Update, handle_game_over_input.run_if(in_state(AppState::Checkmate)))
        .run();
}

/// Main application states
#[derive(States, Default, Debug, Clone, PartialEq, Eq, Hash)]
#[allow(dead_code)] // Some states not yet implemented
enum AppState {
    #[default]
    MainMenu,
    ColorSelect,
    DifficultySelect,
    PlayerTurn,
    PieceAnimating,
    AIThinking,
    BattleAnimation,
    Replay,
    Checkmate,
}

/// Resource holding the current chess game state
#[derive(Resource)]
struct ChessGameState {
    game: GameState,
    selected_piece: Option<Position>,
    valid_moves: Vec<ChessMove>,
    player_color: ChessColor,
    white_captured_count: usize,
    black_captured_count: usize,
}

impl ChessGameState {
    fn new() -> Self {
        Self {
            game: GameState::new(),
            selected_piece: None,
            valid_moves: Vec::new(),
            player_color: ChessColor::White,
            white_captured_count: 0,
            black_captured_count: 0,
        }
    }
}

/// Tracks battle animations triggered every 3 captures
#[derive(Resource)]
struct BattleCounter {
    total_captures: u32,
    pending_battle: Option<BattleInfo>,
}

impl Default for BattleCounter {
    fn default() -> Self {
        Self {
            total_captures: 0,
            pending_battle: None,
        }
    }
}

/// Information about a pending battle animation
#[derive(Clone)]
struct BattleInfo {
    attacker_type: core_logic::PieceType,
    attacker_color: ChessColor,
    attacker_position: Position,
    defender_type: core_logic::PieceType,
    defender_color: ChessColor,
    defender_position: Position,
    chess_move: ChessMove,  // Store the move to execute after battle
}

/// Resource for battle animation state
#[derive(Resource)]
struct BattleAnimationState {
    timer: Timer,
    phase: BattlePhase,
}

impl Default for BattleAnimationState {
    fn default() -> Self {
        Self {
            timer: Timer::from_seconds(9.0, TimerMode::Once),
            phase: BattlePhase::Introduction,
        }
    }
}

#[derive(PartialEq)]
enum BattlePhase {
    Introduction,
    Approach,
    Combat,
    Conclusion,
}

impl BattleCounter {
    fn should_trigger_battle(&self) -> bool {
        self.total_captures > 0 && self.total_captures % 3 == 0
    }
}

/// AI difficulty level (1-10)
#[derive(Resource)]
struct AIDifficulty(u8);

/// Resource to add delay before AI moves for visibility
#[derive(Resource)]
struct AIMoveTimer {
    timer: Timer,
    pending_move: Option<ChessMove>,
}

/// Camera control state
#[derive(Resource)]
struct CameraState {
    rotation_angle: f32,
    distance: f32,
    height: f32,
}

impl Default for CameraState {
    fn default() -> Self {
        Self {
            rotation_angle: 0.0,
            distance: 12.0,
            height: 12.0,
        }
    }
}

/// Tracks whether the 3D scene (board + pieces) has been spawned
#[derive(Resource, Default)]
struct SceneSpawned {
    spawned: bool,
}

/// Resource to track if pieces have been spawned (prevent duplication)
#[derive(Resource, Default)]
#[allow(dead_code)] // Field used internally by spawn system
struct PiecesSpawned {
    spawned: bool,
}

/// Component for pieces participating in battle animation
#[derive(Component)]
struct BattleParticipant {
    role: BattleRole,
    initial_position: Vec3,
    initial_scale: Vec3,
    sword_entity: Option<Entity>, // Entity of the sword mesh
    shield_entity: Option<Entity>, // Entity of the shield mesh
}

#[derive(PartialEq)]
enum BattleRole {
    Attacker,
    Defender,
}

/// Component marking battle accessories (swords, shields)
#[derive(Component)]
struct BattleAccessory;

/// Component marking a piece as captured
#[derive(Component)]
struct CapturedPiece {
    capture_index: usize, // Index for positioning in captured pieces display
}

/// Component marking chess pieces with their position and type
#[derive(Component)]
#[allow(dead_code)] // Fields are component data
struct ChessPiece {
    position: Position,
    color: ChessColor,
    piece_type: core_logic::PieceType,
}

/// Component for animating piece movement
#[derive(Component)]
struct PieceAnimation {
    from: Vec3,
    to: Vec3,
    progress: f32,
    duration: f32,
}

/// Component marking selectable pieces
#[derive(Component)]
struct Selectable;

/// Component for highlighting valid move squares
#[derive(Component)]
#[allow(dead_code)] // Field is component data
struct MoveHighlight {
    position: Position,
}

/// Component marking a board square entity
#[derive(Component)]
struct BoardSquare {
    position: Position,
}

/// Sets up the medieval battlefield scene
fn setup_scene(
    mut commands: Commands,
    mut meshes: ResMut<Assets<Mesh>>,
    mut materials: ResMut<Assets<StandardMaterial>>,
    mut scene_spawned: ResMut<SceneSpawned>,
) {
    // Only spawn the scene once
    if scene_spawned.spawned {
        return;
    }
    info!("🏰 Setting up medieval battlefield scene");

    // Create chessboard
    for file in 0..8 {
        for rank in 0..8 {
            let is_light_square = (file + rank) % 2 == 0;
            let color = if is_light_square {
                Color::srgb(0.9, 0.85, 0.75) // Warm stone
            } else {
                Color::srgb(0.3, 0.25, 0.2) // Dark stone
            };

            commands.spawn((
                PbrBundle {
                    mesh: meshes.add(Cuboid::new(1.0, 0.1, 1.0)),
                    material: materials.add(StandardMaterial {
                        base_color: color,
                        perceptual_roughness: 0.8,
                        metallic: 0.0,
                        ..default()
                    }),
                    transform: Transform::from_xyz(
                        file as f32 - 3.5,
                        0.0,
                        rank as f32 - 3.5,
                    ),
                    ..default()
                },
                BoardSquare {
                    position: Position::new(file, rank),
                },
            ));
        }
    }

    // Add atmospheric fog (note: fog is per-camera in Bevy 0.14)
    commands.insert_resource(AmbientLight {
        color: Color::srgb(0.3, 0.3, 0.35),
        brightness: 100.0,
    });

    scene_spawned.spawned = true;
}

/// Sets up the cinematic camera system
fn setup_camera(mut commands: Commands, camera_state: Res<CameraState>) {
    info!("📷 Setting up cinematic camera");

    let angle = camera_state.rotation_angle;
    let distance = camera_state.distance;
    let height = camera_state.height;
    
    let x = angle.sin() * distance;
    let z = angle.cos() * distance;

    commands.spawn(Camera3dBundle {
        transform: Transform::from_xyz(x, height, z)
            .looking_at(Vec3::ZERO, Vec3::Y),
        ..default()
    });
}

/// Sets up dramatic medieval lighting
fn setup_lights(mut commands: Commands) {
    info!("🔥 Setting up medieval torchlight");

    // Main directional light (moonlight)
    commands.spawn(DirectionalLightBundle {
        directional_light: DirectionalLight {
            color: Color::srgb(0.8, 0.85, 1.0),
            illuminance: 5000.0,
            shadows_enabled: true,
            ..default()
        },
        transform: Transform::from_rotation(Quat::from_euler(
            EulerRot::XYZ,
            -std::f32::consts::PI / 4.0,
            std::f32::consts::PI / 4.0,
            0.0,
        )),
        ..default()
    });

    // Ambient light
    commands.insert_resource(AmbientLight {
        color: Color::srgb(0.4, 0.35, 0.3),
        brightness: 200.0,
    });

    // Point lights (torches) at corners
    let torch_positions = [
        Vec3::new(-5.0, 2.0, -5.0),
        Vec3::new(5.0, 2.0, -5.0),
        Vec3::new(-5.0, 2.0, 5.0),
        Vec3::new(5.0, 2.0, 5.0),
    ];

    for pos in torch_positions {
        commands.spawn(PointLightBundle {
            point_light: PointLight {
                color: Color::srgb(1.0, 0.7, 0.3),
                intensity: 500_000.0,
                range: 10.0,
                shadows_enabled: true,
                ..default()
            },
            transform: Transform::from_translation(pos),
            ..default()
        });
    }
}

/// Spawns 3D chess pieces in starting position
fn spawn_chess_pieces(
    mut commands: Commands,
    mut meshes: ResMut<Assets<Mesh>>,
    mut materials: ResMut<Assets<StandardMaterial>>,
    game_state: Res<ChessGameState>,
    pieces_spawned: Res<PiecesSpawned>,
) {
    // Only spawn once
    if pieces_spawned.spawned {
        return;
    }
    
    info!("♟️ Spawning medieval chess pieces");

    // Create a parent entity to hold all piece entities so they can be managed together
    let parent = commands.spawn((
        SpatialBundle::default(),
        Name::new("PiecesParent"),
    )).id();

    let white_material = materials.add(StandardMaterial {
        base_color: Color::srgb(0.95, 0.95, 0.9),
        perceptual_roughness: 0.3,
        metallic: 0.2,
        ..default()
    });

    let black_material = materials.add(StandardMaterial {
        base_color: Color::srgb(0.1, 0.1, 0.15),
        perceptual_roughness: 0.3,
        metallic: 0.2,
        ..default()
    });

    // Knights use same materials as other pieces for consistency

    // Iterate through board and spawn pieces
    for file in 0..8 {
        for rank in 0..8 {
            let pos = Position::new(file, rank);
            if let Some(piece) = game_state.game.board.get_piece(&pos) {
                let mesh = create_piece_mesh(&mut meshes, piece.piece_type);
                
                // All pieces use standard materials
                let material = if piece.color == ChessColor::White {
                    white_material.clone()
                } else {
                    black_material.clone()
                };

                let world_pos = board_to_world_position(&pos);
                
                // All pieces use consistent scale
                let scale = Vec3::splat(0.4);

                commands.spawn((
                    PbrBundle {
                        mesh,
                        material,
                        transform: Transform::from_translation(world_pos)
                            .with_scale(scale),
                        ..default()
                    },
                    ChessPiece {
                        position: pos,
                        color: piece.color,
                        piece_type: piece.piece_type,
                    },
                    Selectable,
                    Name::new(format!("piece_{:?}_{:?}", pos.file, pos.rank)),
                )).set_parent(parent);
            }
        }
    }

    // Mark pieces spawned resource
    commands.insert_resource(PiecesSpawned { spawned: true });
}

/// Helper to create smooth cylinder vertices with proper normals
fn create_cylinder_vertices(radius: f32, height: f32, segments: u32) -> (Vec<[f32; 3]>, Vec<[f32; 3]>, Vec<u32>) {
    let mut vertices = Vec::new();
    let mut normals = Vec::new();
    let mut indices = Vec::new();
    
    // Bottom cap center
    vertices.push([0.0, 0.0, 0.0]);
    normals.push([0.0, -1.0, 0.0]);
    
    // Bottom cap edge
    for i in 0..segments {
        let angle = (i as f32 / segments as f32) * 2.0 * std::f32::consts::PI;
        vertices.push([radius * angle.cos(), 0.0, radius * angle.sin()]);
        normals.push([0.0, -1.0, 0.0]);
    }
    
    // Top cap edge
    for i in 0..segments {
        let angle = (i as f32 / segments as f32) * 2.0 * std::f32::consts::PI;
        vertices.push([radius * angle.cos(), height, radius * angle.sin()]);
        normals.push([angle.cos(), 0.0, angle.sin()]);
    }
    
    // Top cap center
    vertices.push([0.0, height, 0.0]);
    normals.push([0.0, 1.0, 0.0]);
    
    // Bottom cap indices
    for i in 0..segments {
        indices.push(0);
        indices.push(1 + i);
        indices.push(1 + (i + 1) % segments);
    }
    
    // Side indices
    for i in 0..segments {
        let bottom_start = 1;
        let top_start = 1 + segments;
        let next_i = (i + 1) % segments;
        
        indices.push(bottom_start + i);
        indices.push(top_start + i);
        indices.push(top_start + next_i);
        
        indices.push(bottom_start + i);
        indices.push(top_start + next_i);
        indices.push(bottom_start + next_i);
    }
    
    // Top cap indices
    let top_center = vertices.len() as u32 - 1;
    let top_start = 1 + segments;
    for i in 0..segments {
        indices.push(top_center);
        indices.push(top_start + (i + 1) % segments);
        indices.push(top_start + i);
    }
    
    (vertices, normals, indices)
}

/// Helper to create sphere vertices with proper normals
fn create_sphere_vertices(radius: f32, segments: u32, rings: u32) -> (Vec<[f32; 3]>, Vec<[f32; 3]>, Vec<u32>) {
    let mut vertices = Vec::new();
    let mut normals = Vec::new();
    let mut indices = Vec::new();
    
    // Top vertex
    vertices.push([0.0, radius, 0.0]);
    normals.push([0.0, 1.0, 0.0]);
    
    // Middle rings
    for ring in 1..rings {
        let phi = std::f32::consts::PI * ring as f32 / rings as f32;
        let y = radius * phi.cos();
        let ring_radius = radius * phi.sin();
        
        for seg in 0..segments {
            let theta = 2.0 * std::f32::consts::PI * seg as f32 / segments as f32;
            let x = ring_radius * theta.cos();
            let z = ring_radius * theta.sin();
            
            vertices.push([x, y, z]);
            let normal = Vec3::new(x, y, z).normalize();
            normals.push([normal.x, normal.y, normal.z]);
        }
    }
    
    // Bottom vertex
    vertices.push([0.0, -radius, 0.0]);
    normals.push([0.0, -1.0, 0.0]);
    
    // Top cap indices
    for seg in 0..segments {
        indices.push(0);
        indices.push(1 + seg);
        indices.push(1 + (seg + 1) % segments);
    }
    
    // Middle rings indices
    for ring in 0..rings - 2 {
        let ring_start = 1 + ring * segments;
        let next_ring_start = ring_start + segments;
        
        for seg in 0..segments {
            let next_seg = (seg + 1) % segments;
            
            indices.push(ring_start + seg);
            indices.push(next_ring_start + seg);
            indices.push(next_ring_start + next_seg);
            
            indices.push(ring_start + seg);
            indices.push(next_ring_start + next_seg);
            indices.push(ring_start + next_seg);
        }
    }
    
    // Bottom cap indices
    let bottom_idx = vertices.len() as u32 - 1;
    let last_ring_start = 1 + (rings - 2) * segments;
    for seg in 0..segments {
        indices.push(bottom_idx);
        indices.push(last_ring_start + (seg + 1) % segments);
        indices.push(last_ring_start + seg);
    }
    
    (vertices, normals, indices)
}

/// Helper to create box vertices (for battlements)
fn create_box_vertices(width: f32, height: f32, depth: f32) -> (Vec<[f32; 3]>, Vec<[f32; 3]>, Vec<u32>) {
    let mut vertices = Vec::new();
    let mut normals = Vec::new();
    let mut indices = Vec::new();
    
    let hw = width / 2.0;
    let hh = height / 2.0;
    let hd = depth / 2.0;
    
    // Front face
    vertices.extend_from_slice(&[
        [-hw, -hh, hd], [hw, -hh, hd], [hw, hh, hd], [-hw, hh, hd],
    ]);
    normals.extend_from_slice(&[[0.0, 0.0, 1.0]; 4]);
    
    // Back face
    vertices.extend_from_slice(&[
        [hw, -hh, -hd], [-hw, -hh, -hd], [-hw, hh, -hd], [hw, hh, -hd],
    ]);
    normals.extend_from_slice(&[[0.0, 0.0, -1.0]; 4]);
    
    // Right face
    vertices.extend_from_slice(&[
        [hw, -hh, hd], [hw, -hh, -hd], [hw, hh, -hd], [hw, hh, hd],
    ]);
    normals.extend_from_slice(&[[1.0, 0.0, 0.0]; 4]);
    
    // Left face
    vertices.extend_from_slice(&[
        [-hw, -hh, -hd], [-hw, -hh, hd], [-hw, hh, hd], [-hw, hh, -hd],
    ]);
    normals.extend_from_slice(&[[-1.0, 0.0, 0.0]; 4]);
    
    // Top face
    vertices.extend_from_slice(&[
        [-hw, hh, hd], [hw, hh, hd], [hw, hh, -hd], [-hw, hh, -hd],
    ]);
    normals.extend_from_slice(&[[0.0, 1.0, 0.0]; 4]);
    
    // Bottom face
    vertices.extend_from_slice(&[
        [-hw, -hh, -hd], [hw, -hh, -hd], [hw, -hh, hd], [-hw, -hh, hd],
    ]);
    normals.extend_from_slice(&[[0.0, -1.0, 0.0]; 4]);
    
    // Indices for 6 faces
    for face in 0..6 {
        let offset = face * 4;
        indices.extend_from_slice(&[
            offset, offset + 1, offset + 2,
            offset, offset + 2, offset + 3,
        ]);
    }
    
    (vertices, normals, indices)
}

/// Creates a medieval sword mesh for battle animations
fn create_sword_mesh() -> Mesh {
    use bevy::render::mesh::{Mesh, Indices, PrimitiveTopology};
    use bevy::render::render_asset::RenderAssetUsages;
    
    let mut mesh = Mesh::new(PrimitiveTopology::TriangleList, RenderAssetUsages::default());
    let mut all_vertices = Vec::new();
    let mut all_normals = Vec::new();
    let mut all_indices = Vec::new();
    
    // Blade (thin box)
    let (blade_v, blade_n, blade_i) = create_box_vertices(0.1, 1.5, 0.05);
    all_vertices.extend(blade_v.iter().map(|&v| [v[0], v[1] + 0.75, v[2]]));
    all_normals.extend(blade_n);
    all_indices.extend(blade_i);
    
    // Cross guard (horizontal bar)
    let guard_start = all_vertices.len() as u32;
    let (guard_v, guard_n, guard_i) = create_box_vertices(0.5, 0.08, 0.08);
    all_vertices.extend(guard_v.iter().map(|&v| [v[0], v[1] + 0.1, v[2]]));
    all_normals.extend(guard_n);
    all_indices.extend(guard_i.iter().map(|&i| i + guard_start));
    
    // Handle (grip)
    let handle_start = all_vertices.len() as u32;
    let (handle_v, handle_n, handle_i) = create_cylinder_vertices(0.05, 0.3, 8);
    all_vertices.extend(handle_v.iter().map(|&v| [v[0], v[1] - 0.15, v[2]]));
    all_normals.extend(handle_n);
    all_indices.extend(handle_i.iter().map(|&i| i + handle_start));
    
    // Pommel (sphere at bottom)
    let pommel_start = all_vertices.len() as u32;
    let (pommel_v, pommel_n, pommel_i) = create_sphere_vertices(0.08, 8, 6);
    all_vertices.extend(pommel_v.iter().map(|&v| [v[0], v[1] - 0.35, v[2]]));
    all_normals.extend(pommel_n);
    all_indices.extend(pommel_i.iter().map(|&i| i + pommel_start));
    
    mesh.insert_attribute(Mesh::ATTRIBUTE_POSITION, all_vertices);
    mesh.insert_attribute(Mesh::ATTRIBUTE_NORMAL, all_normals);
    mesh.insert_indices(Indices::U32(all_indices));
    
    mesh
}

/// Creates a medieval shield mesh for battle animations
fn create_shield_mesh() -> Mesh {
    use bevy::render::mesh::{Mesh, Indices, PrimitiveTopology};
    use bevy::render::render_asset::RenderAssetUsages;
    
    let mut mesh = Mesh::new(PrimitiveTopology::TriangleList, RenderAssetUsages::default());
    let mut all_vertices = Vec::new();
    let mut all_normals = Vec::new();
    let mut all_indices = Vec::new();
    
    // Shield face (flattened cylinder)
    let (shield_v, shield_n, shield_i) = create_cylinder_vertices(0.4, 0.1, 16);
    all_vertices.extend(shield_v.iter().map(|&v| [v[0], v[1] + 0.4, v[2]]));
    all_normals.extend(shield_n);
    all_indices.extend(shield_i);
    
    // Shield boss (center bump for strength)
    let boss_start = all_vertices.len() as u32;
    let (boss_v, boss_n, boss_i) = create_sphere_vertices(0.15, 12, 8);
    all_vertices.extend(boss_v.iter().map(|&v| [v[0], v[1] + 0.45, v[2]]));
    all_normals.extend(boss_n);
    all_indices.extend(boss_i.iter().map(|&i| i + boss_start));
    
    mesh.insert_attribute(Mesh::ATTRIBUTE_POSITION, all_vertices);
    mesh.insert_attribute(Mesh::ATTRIBUTE_NORMAL, all_normals);
    mesh.insert_indices(Indices::U32(all_indices));
    
    mesh
}

/// Creates appropriate mesh for piece type with medieval England styling
fn create_piece_mesh(
    meshes: &mut ResMut<Assets<Mesh>>,
    piece_type: core_logic::PieceType,
) -> Handle<Mesh> {
    
    use bevy::render::mesh::{Mesh, Indices, PrimitiveTopology};
    use bevy::render::render_asset::RenderAssetUsages;
    
    match piece_type {
        core_logic::PieceType::King => {
            // King: Tall piece with distinctive cross crown on top
            let mut mesh = Mesh::new(PrimitiveTopology::TriangleList, RenderAssetUsages::default());
            let mut all_vertices = Vec::new();
            let mut all_normals = Vec::new();
            let mut all_indices = Vec::new();
            
            // Base cylinder (wide)
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.45, 0.3, 16);
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices);
            
            // Main body cylinder (tall, narrower)
            let body_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.35, 1.2, 16);
            for v in &mut verts { v[1] += 0.3; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + body_offset));
            
            // Crown base (ring/platform)
            let crown_base_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.38, 0.15, 16);
            for v in &mut verts { v[1] += 1.5; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + crown_base_offset));
            
            // Crown sphere (decorative)
            let crown_sphere_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_sphere_vertices(0.2, 12, 8);
            for v in &mut verts { v[1] += 1.75; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + crown_sphere_offset));
            
            // Cross vertical beam (distinctive king marker)
            let cross_vert_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_box_vertices(0.08, 0.4, 0.08);
            for v in &mut verts { v[1] += 2.15; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + cross_vert_offset));
            
            // Cross horizontal beam
            let cross_horiz_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_box_vertices(0.25, 0.08, 0.08);
            for v in &mut verts { v[1] += 2.15; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + cross_horiz_offset));
            
            let uvs: Vec<[f32; 2]> = vec![[0.0, 0.0]; all_vertices.len()];
            mesh.insert_attribute(Mesh::ATTRIBUTE_POSITION, all_vertices);
            mesh.insert_attribute(Mesh::ATTRIBUTE_NORMAL, all_normals);
            mesh.insert_attribute(Mesh::ATTRIBUTE_UV_0, uvs);
            mesh.insert_indices(Indices::U32(all_indices));
            meshes.add(mesh)
        }
        core_logic::PieceType::Queen => {
            // Queen: Elegant tapered body with multi-pointed crown
            let mut mesh = Mesh::new(PrimitiveTopology::TriangleList, RenderAssetUsages::default());
            let mut all_vertices = Vec::new();
            let mut all_normals = Vec::new();
            let mut all_indices = Vec::new();
            
            // Base cylinder (widest)
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.48, 0.25, 16);
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices);
            
            // Lower body (tapered)
            let lower_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.38, 0.5, 16);
            for v in &mut verts { v[1] += 0.25; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + lower_offset));
            
            // Upper body (narrower, elegant)
            let upper_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.28, 0.7, 16);
            for v in &mut verts { v[1] += 0.75; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + upper_offset));
            
            // Neck (thin)
            let neck_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.18, 0.25, 16);
            for v in &mut verts { v[1] += 1.45; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + neck_offset));
            
            // Crown base (ring)
            let crown_base_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.32, 0.12, 16);
            for v in &mut verts { v[1] += 1.7; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + crown_base_offset));
            
            // Central crown sphere
            let crown_sphere_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_sphere_vertices(0.18, 12, 8);
            for v in &mut verts { v[1] += 1.9; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + crown_sphere_offset));
            
            // 5 Crown points arranged in circle (distinctive queen feature)
            for i in 0..5 {
                let angle = (i as f32 / 5.0) * 2.0 * std::f32::consts::PI;
                let radius = 0.28;
                let x = radius * angle.cos();
                let z = radius * angle.sin();
                
                let point_offset = all_vertices.len() as u32;
                let (mut verts, mut norms, indices) = create_sphere_vertices(0.08, 8, 6);
                for v in &mut verts {
                    v[0] += x;
                    v[1] += 2.05;
                    v[2] += z;
                }
                all_vertices.append(&mut verts);
                all_normals.append(&mut norms);
                all_indices.extend(indices.iter().map(|i| i + point_offset));
            }
            
            let uvs: Vec<[f32; 2]> = vec![[0.0, 0.0]; all_vertices.len()];
            mesh.insert_attribute(Mesh::ATTRIBUTE_POSITION, all_vertices);
            mesh.insert_attribute(Mesh::ATTRIBUTE_NORMAL, all_normals);
            mesh.insert_attribute(Mesh::ATTRIBUTE_UV_0, uvs);
            mesh.insert_indices(Indices::U32(all_indices));
            meshes.add(mesh)
        }
        core_logic::PieceType::Rook => {
            // Rook: Castle tower with battlements (crenellations)
            let mut mesh = Mesh::new(PrimitiveTopology::TriangleList, RenderAssetUsages::default());
            let mut all_vertices = Vec::new();
            let mut all_normals = Vec::new();
            let mut all_indices = Vec::new();
            
            // Wide base pedestal
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.5, 0.25, 16);
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices);
            
            // Main tower body (cylindrical for classic castle look)
            let body_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.4, 1.0, 16);
            for v in &mut verts { v[1] += 0.25; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + body_offset));
            
            // Top rim (slightly wider for battlement base)
            let rim_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.45, 0.1, 16);
            for v in &mut verts { v[1] += 1.25; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + rim_offset));
            
            // Battlements - 4 crenellations (castle tower style)
            let battlement_height = 0.3;
            let battlement_width = 0.15;
            let battlement_radius = 0.42;
            
            // Add 4 battlements at 90-degree intervals
            for i in 0..4 {
                let angle = i as f32 * std::f32::consts::PI / 2.0;
                let x_offset = battlement_radius * angle.cos();
                let z_offset = battlement_radius * angle.sin();
                
                let batt_offset = all_vertices.len() as u32;
                let (mut verts, mut norms, indices) = create_box_vertices(battlement_width, battlement_height, battlement_width);
                for v in &mut verts { 
                    v[0] += x_offset;
                    v[1] += 1.35 + battlement_height / 2.0;
                    v[2] += z_offset;
                }
                all_vertices.append(&mut verts);
                all_normals.append(&mut norms);
                all_indices.extend(indices.iter().map(|i| i + batt_offset));
            }
            
            let uvs: Vec<[f32; 2]> = vec![[0.0, 0.0]; all_vertices.len()];
            mesh.insert_attribute(Mesh::ATTRIBUTE_POSITION, all_vertices);
            mesh.insert_attribute(Mesh::ATTRIBUTE_NORMAL, all_normals);
            mesh.insert_attribute(Mesh::ATTRIBUTE_UV_0, uvs);
            mesh.insert_indices(Indices::U32(all_indices));
            
            meshes.add(mesh)
        }
        core_logic::PieceType::Bishop => {
            // Bishop: Tall elegant piece with distinctive pointed mitre top and slit
            let mut mesh = Mesh::new(PrimitiveTopology::TriangleList, RenderAssetUsages::default());
            let mut all_vertices = Vec::new();
            let mut all_normals = Vec::new();
            let mut all_indices = Vec::new();
            
            // Wide base pedestal
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.42, 0.2, 16);
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices);
            
            // Narrow waist (hourglass shape)
            let waist_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.2, 0.3, 12);
            for v in &mut verts { v[1] += 0.2; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + waist_offset));
            
            // Lower body bulge
            let lower_body_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_sphere_vertices(0.32, 14, 8);
            for v in &mut verts { v[1] += 0.55; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + lower_body_offset));
            
            // Upper body (tapering toward mitre)
            let upper_body_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.26, 0.6, 14);
            for v in &mut verts { v[1] += 0.85; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + upper_body_offset));
            
            // Mitre base (bishop's hat base)
            let mitre_base_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.28, 0.1, 14);
            for v in &mut verts { v[1] += 1.45; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + mitre_base_offset));
            
            // Mitre head (tall pointed sphere - distinctive bishop feature)
            let mitre_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_sphere_vertices(0.22, 12, 10);
            for v in &mut verts {
                v[1] *= 1.6; // Elongate vertically to create pointed mitre
                v[1] += 1.7;
            }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + mitre_offset));
            
            // Mitre slit marker (diagonal cut representation - bishop's traditional feature)
            let slit1_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_sphere_vertices(0.08, 8, 6);
            for v in &mut verts {
                v[0] += 0.18; // Offset to side
                v[1] += 1.85;
                v[2] += 0.1;
            }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + slit1_offset));
            
            let slit2_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_sphere_vertices(0.08, 8, 6);
            for v in &mut verts {
                v[0] -= 0.18; // Opposite side
                v[1] += 1.85;
                v[2] -= 0.1;
            }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + slit2_offset));
            
            let uvs: Vec<[f32; 2]> = vec![[0.0, 0.0]; all_vertices.len()];
            mesh.insert_attribute(Mesh::ATTRIBUTE_POSITION, all_vertices);
            mesh.insert_attribute(Mesh::ATTRIBUTE_NORMAL, all_normals);
            mesh.insert_attribute(Mesh::ATTRIBUTE_UV_0, uvs);
            mesh.insert_indices(Indices::U32(all_indices));
            
            meshes.add(mesh)
        }
        core_logic::PieceType::Knight => {
            // Knight: Classic chess horse head with proper proportions
            let mut mesh = Mesh::new(PrimitiveTopology::TriangleList, RenderAssetUsages::default());
            let mut all_vertices = Vec::new();
            let mut all_normals = Vec::new();
            let mut all_indices = Vec::new();
            
            // Base pedestal
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.4, 0.3, 16);
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices);
            
            // Lower neck (vertical, thicker)
            let lower_neck_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.28, 0.5, 12);
            for v in &mut verts { v[1] += 0.3; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + lower_neck_offset));
            
            // Upper neck (angled forward, tapering)
            let upper_neck_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.22, 0.4, 12);
            for v in &mut verts { 
                v[1] += 0.8;
                v[2] += 0.1; // Slight forward angle
            }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + upper_neck_offset));
            
            // Horse head (elongated sphere, positioned forward and angled)
            let head_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_sphere_vertices(0.3, 14, 10);
            for v in &mut verts {
                // Elongate along Z axis (forward) to create horse-like head
                v[2] *= 1.4;
                // Position at top of neck, angled forward
                v[1] += 1.35;
                v[2] += 0.35;
            }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + head_offset));
            
            // Muzzle/snout (smaller, elongated forward)
            let snout_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_sphere_vertices(0.15, 10, 6);
            for v in &mut verts {
                v[2] *= 1.5; // Elongate forward
                v[1] += 1.25; // Lower than main head
                v[2] += 0.65; // Well forward
            }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + snout_offset));
            
            // Small ear (left)
            let ear_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_sphere_vertices(0.08, 6, 4);
            for v in &mut verts {
                v[1] *= 1.5; // Elongate vertically
                v[0] -= 0.2; // Position to left
                v[1] += 1.55; // Top of head
                v[2] += 0.3;
            }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + ear_offset));
            
            // Small ear (right)
            let ear2_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_sphere_vertices(0.08, 6, 4);
            for v in &mut verts {
                v[1] *= 1.5; // Elongate vertically
                v[0] += 0.2; // Position to right
                v[1] += 1.55; // Top of head
                v[2] += 0.3;
            }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + ear2_offset));
            
            let uvs: Vec<[f32; 2]> = vec![[0.0, 0.0]; all_vertices.len()];
            mesh.insert_attribute(Mesh::ATTRIBUTE_POSITION, all_vertices);
            mesh.insert_attribute(Mesh::ATTRIBUTE_NORMAL, all_normals);
            mesh.insert_attribute(Mesh::ATTRIBUTE_UV_0, uvs);
            mesh.insert_indices(Indices::U32(all_indices));
            meshes.add(mesh)
        }
        core_logic::PieceType::Pawn => {
            // Pawn: Simple base, body cylinder, and sphere top
            let mut mesh = Mesh::new(PrimitiveTopology::TriangleList, RenderAssetUsages::default());
            let mut all_vertices = Vec::new();
            let mut all_normals = Vec::new();
            let mut all_indices = Vec::new();
            
            // Base
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.35, 0.2, 12);
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices);
            
            // Body
            let body_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.28, 0.7, 12);
            for v in &mut verts { v[1] += 0.2; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + body_offset));
            
            // Head sphere
            let head_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_sphere_vertices(0.2, 10, 6);
            for v in &mut verts { v[1] += 1.05; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + head_offset));
            
            let uvs: Vec<[f32; 2]> = vec![[0.0, 0.0]; all_vertices.len()];
            mesh.insert_attribute(Mesh::ATTRIBUTE_POSITION, all_vertices);
            mesh.insert_attribute(Mesh::ATTRIBUTE_NORMAL, all_normals);
            mesh.insert_attribute(Mesh::ATTRIBUTE_UV_0, uvs);
            mesh.insert_indices(Indices::U32(all_indices));
            meshes.add(mesh)
        }
    }
}

/// Converts board position to world 3D coordinates
fn board_to_world_position(pos: &Position) -> Vec3 {
    Vec3::new(
        pos.file as f32 - 3.5,
        0.6, // Height above board
        pos.rank as f32 - 3.5,
    )
}

/// Converts world 3D coordinates back to board position
fn world_to_board_position(world_pos: &Vec3) -> Position {
    Position::new(
        (world_pos.x + 3.5).round() as u8,
        (world_pos.z + 3.5).round() as u8,
    )
}

/// Handles player clicking on pieces to select/move them
fn handle_mouse_click(
    mouse_button: Res<ButtonInput<MouseButton>>,
    windows: Query<&Window, With<PrimaryWindow>>,
    camera_query: Query<(&Camera, &GlobalTransform)>,
    pieces_query: Query<(Entity, &ChessPiece, &Transform)>,
    squares_query: Query<(&BoardSquare, &Transform)>,
    mut game_state: ResMut<ChessGameState>,
    mut battle_counter: ResMut<BattleCounter>,
    mut commands: Commands,
    mut next_state: ResMut<NextState<AppState>>,
    _meshes: ResMut<Assets<Mesh>>,
    _materials: ResMut<Assets<StandardMaterial>>,
) {
    if !mouse_button.just_pressed(MouseButton::Left) {
        return;
    }

    let Ok(window) = windows.get_single() else { return };
    let Some(cursor_pos) = window.cursor_position() else { return };
    let Ok((camera, camera_transform)) = camera_query.get_single() else { return };

    // Cast ray from camera through cursor position
    let Some(ray) = camera.viewport_to_world(camera_transform, cursor_pos) else { return };

    // Check if we clicked a piece
    let mut clicked_piece: Option<Position> = None;
    for (_entity, piece, transform) in pieces_query.iter() {
        if ray_intersects_piece(&ray, transform) {
            clicked_piece = Some(piece.position);
            break;
        }
    }

    // Check if we clicked a square
    let mut clicked_square: Option<Position> = None;
    for (square, transform) in squares_query.iter() {
        if ray_intersects_square(&ray, transform) {
            clicked_square = Some(square.position);
            break;
        }
    }

    // Handle the click
    if let Some(selected_pos) = game_state.selected_piece {
        // We have a piece selected - try to move it
        if let Some(target_pos) = clicked_square {
            // Find the matching move from valid moves
            if let Some(chess_move) = game_state.valid_moves.iter().find(|m| m.to == target_pos).copied() {
                // Check if this is a capture - move the captured piece to the side
                if chess_move.is_capture() {
                    // Get attacker piece type for battle animation
                    let attacker_type = game_state.game.board.get_piece(&selected_pos).map(|p| p.piece_type);
                    let attacker_color = game_state.game.board.get_piece(&selected_pos).map(|p| p.color);
                    
                    for (entity, piece, _) in pieces_query.iter() {
                        if piece.position == target_pos {
                            info!("💥 Capturing {} piece at {}", 
                                if piece.color == ChessColor::White { "white" } else { "black" },
                                target_pos.to_algebraic());
                            
                            // Track capture for battle animations
                            battle_counter.total_captures += 1;
                            let should_battle = battle_counter.total_captures % 3 == 0;
                            
                            if should_battle {
                                // Every third capture triggers a battle!
                                if let (Some(attacker_t), Some(attacker_c)) = (attacker_type, attacker_color) {
                                    info!("⚔️ EPIC BATTLE #{} COMMENCES!", battle_counter.total_captures / 3);
                                    battle_counter.pending_battle = Some(BattleInfo {
                                        attacker_type: attacker_t,
                                        attacker_color: attacker_c,
                                        attacker_position: selected_pos,
                                        defender_type: piece.piece_type,
                                        defender_color: piece.color,
                                        defender_position: target_pos,
                                        chess_move,  // Store move for later execution
                                    });
                                    // Clear selection and skip move execution - battle will handle it
                                    game_state.selected_piece = None;
                                    game_state.valid_moves.clear();
                                    return;
                                }
                            }
                            
                            // Only mark as captured if NOT doing battle animation
                            // Determine capture index and position based on color
                            let (capture_index, x_offset, z_base) = if piece.color == ChessColor::White {
                                let idx = game_state.white_captured_count;
                                game_state.white_captured_count += 1;
                                (idx, 12.0, 0.0) // White pieces on right side
                            } else {
                                let idx = game_state.black_captured_count;
                                game_state.black_captured_count += 1;
                                (idx, -12.0, 0.0) // Black pieces on left side
                            };
                            
                            // Calculate position in captured pieces area (stacked in rows)
                            let row = capture_index / 4;
                            let col = capture_index % 4;
                            let captured_pos = Vec3::new(
                                x_offset,
                                0.2,
                                z_base + (row as f32 * 2.5) - 7.0 + (col as f32 * 0.8)
                            );
                            
                            // Mark as captured and animate to side
                            commands.entity(entity)
                                .insert(CapturedPiece { capture_index })
                                .insert(PieceAnimation {
                                    from: board_to_world_position(&target_pos),
                                    to: captured_pos,
                                    progress: 0.0,
                                    duration: 0.5,
                                });
                            break;
                        }
                    }
                }
                
                // Execute the move
                if game_state.game.make_move(chess_move).is_ok() {
                    info!("✅ Move executed: {} -> {}", selected_pos.to_algebraic(), target_pos.to_algebraic());
                    
                    // Check for game over
                    if let Some(result) = game_state.game.is_game_over() {
                        match result {
                            core_logic::GameResult::Checkmate(winner) => {
                                let current_turn = game_state.game.current_turn;
                                let in_check = game_state.game.is_in_check();
                                let legal_moves = game_state.game.legal_moves();
                                info!("👑 CHECKMATE! {} wins!", if winner == ChessColor::White { "White" } else { "Black" });
                                info!("   Current turn: {:?}, In check: {}, Legal moves: {}", current_turn, in_check, legal_moves.len());
                                next_state.set(AppState::Checkmate);
                                return;
                            }
                            core_logic::GameResult::Stalemate => {
                                info!("🤝 STALEMATE! Game is a draw.");
                                next_state.set(AppState::Checkmate);
                                return;
                            }
                            core_logic::GameResult::Draw(reason) => {
                                info!("🤝 DRAW: {}", reason);
                                next_state.set(AppState::Checkmate);
                                return;
                            }
                        }
                    }
                    
                    // Notify if opponent is in check
                    if game_state.game.is_in_check() {
                        info!("⚠️ CHECK! {} is in check!", if game_state.game.current_turn == ChessColor::White { "White" } else { "Black" });
                    }
                    
                    // Handle castling - move both king and rook
                    if chess_move.is_castling() {
                        info!("🏰 Castling move!");
                        // Move the king
                        for (entity, piece, _) in pieces_query.iter() {
                            if piece.position == selected_pos {
                                commands.entity(entity).insert(PieceAnimation {
                                    from: board_to_world_position(&selected_pos),
                                    to: board_to_world_position(&target_pos),
                                    progress: 0.0,
                                    duration: 0.3,
                                });
                                break;
                            }
                        }
                        
                        // Move the rook
                        let rank = selected_pos.rank;
                        if chess_move.flags.contains(core_logic::MoveFlags::CASTLING_KINGSIDE) {
                            // Kingside: rook moves from h-file (7) to f-file (5)
                            let rook_from = core_logic::Position::new(7, rank);
                            let rook_to = core_logic::Position::new(5, rank);
                            for (entity, piece, _) in pieces_query.iter() {
                                if piece.position == rook_from {
                                    commands.entity(entity).insert(PieceAnimation {
                                        from: board_to_world_position(&rook_from),
                                        to: board_to_world_position(&rook_to),
                                        progress: 0.0,
                                        duration: 0.3,
                                    });
                                    break;
                                }
                            }
                        } else {
                            // Queenside: rook moves from a-file (0) to d-file (3)
                            let rook_from = core_logic::Position::new(0, rank);
                            let rook_to = core_logic::Position::new(3, rank);
                            for (entity, piece, _) in pieces_query.iter() {
                                if piece.position == rook_from {
                                    commands.entity(entity).insert(PieceAnimation {
                                        from: board_to_world_position(&rook_from),
                                        to: board_to_world_position(&rook_to),
                                        progress: 0.0,
                                        duration: 0.3,
                                    });
                                    break;
                                }
                            }
                        }
                    } else {
                        // Normal move - just update the piece position
                        for (entity, piece, _) in pieces_query.iter() {
                            if piece.position == selected_pos {
                                commands.entity(entity).insert(PieceAnimation {
                                    from: board_to_world_position(&selected_pos),
                                    to: board_to_world_position(&target_pos),
                                    progress: 0.0,
                                    duration: 0.3,
                                });
                                break;
                            }
                        }
                    }
                } else {
                    error!("❌ Failed to execute move");
                }
                
                // Deselect
                game_state.selected_piece = None;
                game_state.valid_moves.clear();
            } else {
                // Invalid move - deselect
                game_state.selected_piece = None;
                game_state.valid_moves.clear();
            }
        }
    } else if let Some(piece_pos) = clicked_piece {
        // No piece selected - select this piece if it's the player's color and their turn
        if let Some(piece) = game_state.game.board.get_piece(&piece_pos) {
            // Only allow selecting player's own pieces
            if piece.color == game_state.player_color && piece.color == game_state.game.current_turn {
                info!("🎯 Selected piece at {}", piece_pos.to_algebraic());
                game_state.selected_piece = Some(piece_pos);
                // Get all legal moves and filter for this piece
                game_state.valid_moves = game_state.game.legal_moves()
                    .into_iter()
                    .filter(|m| m.from == piece_pos)
                    .collect();
                info!("   Valid moves: {:?}", game_state.valid_moves.iter().map(|m| m.to.to_algebraic()).collect::<Vec<_>>());
            } else if piece.color != game_state.player_color {
                info!("⛔ Cannot select opponent's piece");
            } else {
                info!("⏳ Not your turn");
            }
        }
    }
}

/// Simple ray-sphere intersection for piece picking
fn ray_intersects_piece(ray: &Ray3d, transform: &Transform) -> bool {
    let to_piece = transform.translation - ray.origin;
    let proj = to_piece.dot(*ray.direction);
    
    if proj < 0.0 {
        return false;
    }
    
    let closest_point = ray.origin + *ray.direction * proj;
    let distance_sq = (closest_point - transform.translation).length_squared();
    
    // Increased radius for easier clicking (0.8 radius)
    distance_sq < 0.64
}

/// Ray-plane intersection for square picking
fn ray_intersects_square(ray: &Ray3d, transform: &Transform) -> bool {
    let plane_normal = Vec3::Y;
    let plane_point = transform.translation;
    
    let denom = plane_normal.dot(*ray.direction);
    if denom.abs() < 0.0001 {
        return false;
    }
    
    let t = (plane_point - ray.origin).dot(plane_normal) / denom;
    if t < 0.0 {
        return false;
    }
    
    let hit_point = ray.origin + *ray.direction * t;
    let local_pos = hit_point - transform.translation;
    
    // Expanded bounds for easier clicking
    local_pos.x.abs() < 0.6 && local_pos.z.abs() < 0.6
}

/// Updates piece positions during animations
fn update_piece_positions(
    time: Res<Time>,
    mut commands: Commands,
    mut query: Query<(Entity, &mut Transform, &mut PieceAnimation, &mut ChessPiece, Option<&CapturedPiece>)>,
) {
    for (entity, mut transform, mut anim, mut piece, captured) in query.iter_mut() {
        anim.progress += time.delta_seconds() / anim.duration;
        
        if anim.progress >= 1.0 {
            transform.translation = anim.to;
            // Only update board position for pieces still on the board (not captured)
            if captured.is_none() {
                piece.position = world_to_board_position(&anim.to);
            }
            commands.entity(entity).remove::<PieceAnimation>();
        } else {
            transform.translation = anim.from.lerp(anim.to, anim.progress);
        }
    }
}

/// Updates visual highlights for selected piece and valid moves
fn update_highlights(
    game_state: Res<ChessGameState>,
    mut commands: Commands,
    mut meshes: ResMut<Assets<Mesh>>,
    mut materials: ResMut<Assets<StandardMaterial>>,
    existing_highlights: Query<Entity, With<MoveHighlight>>,
) {
    // Only update if selection changed
    if !game_state.is_changed() {
        return;
    }

    // Remove old highlights
    for entity in existing_highlights.iter() {
        commands.entity(entity).despawn();
    }

    // Add new highlights for valid moves
    if game_state.selected_piece.is_some() {
        let highlight_material = materials.add(StandardMaterial {
            base_color: Color::srgba(0.3, 1.0, 0.3, 0.5),
            alpha_mode: AlphaMode::Blend,
            unlit: true,
            ..default()
        });

        for chess_move in &game_state.valid_moves {
            let world_pos = board_to_world_position(&chess_move.to);
            commands.spawn((
                PbrBundle {
                    mesh: meshes.add(Cylinder::new(0.4, 0.1)),
                    material: highlight_material.clone(),
                    transform: Transform::from_translation(Vec3::new(
                        world_pos.x,
                        0.15,
                        world_pos.z,
                    )),
                    ..default()
                },
                MoveHighlight {
                    position: chess_move.to,
                },
            ));
        }
    }
}

/// Component marking menu UI elements
#[derive(Component)]
struct MenuUI;

#[derive(Component, Debug)]
enum MenuButton {
    PlayAsWhite,
    PlayAsBlack,
    Difficulty(u8),
    StartGame,
}

/// Tracks menu selections
#[derive(Resource, Default)]
struct MenuSelection {
    color: Option<ChessColor>,
    difficulty: Option<u8>,
}

/// Sets up the main menu UI
fn setup_main_menu(
    mut commands: Commands,
) {
    info!("🎮 Setting up main menu");
    info!("📋 Menu will have color buttons, difficulty buttons (1-10), and Start Game button");

    // Root UI node with gradient-like background
    commands.spawn((
        NodeBundle {
            style: Style {
                width: Val::Percent(100.0),
                height: Val::Percent(100.0),
                flex_direction: FlexDirection::Column,
                justify_content: JustifyContent::Center,
                align_items: AlignItems::Center,
                ..default()
            },
            background_color: BackgroundColor(Color::srgba(0.08, 0.08, 0.12, 0.98)),
            ..default()
        },
        MenuUI,
    ))
    .with_children(|parent| {
        // Title with shadow effect (two text layers)
        parent.spawn(TextBundle::from_section(
            "⚔️ IRON CHESS ⚔️",
            TextStyle {
                font_size: 96.0,
                color: Color::srgb(1.0, 0.92, 0.65), // Brighter gold
                ..default()
            },
        ).with_style(Style {
            margin: UiRect::all(Val::Px(15.0)),
            ..default()
        }));

        parent.spawn(TextBundle::from_section(
            "Medieval Battlefield",
            TextStyle {
                font_size: 26.0,
                color: Color::srgba(0.85, 0.75, 0.55, 0.9),
                ..default()
            },
        ).with_style(Style {
            margin: UiRect::bottom(Val::Px(50.0)),
            ..default()
        }));

        // Color selection section with card-like container
        parent.spawn(NodeBundle {
            style: Style {
                flex_direction: FlexDirection::Column,
                align_items: AlignItems::Center,
                padding: UiRect::all(Val::Px(30.0)),
                margin: UiRect::bottom(Val::Px(20.0)),
                ..default()
            },
            background_color: BackgroundColor(Color::srgba(0.12, 0.12, 0.18, 0.6)),
            ..default()
        })
        .with_children(|card| {
            card.spawn(TextBundle::from_section(
                "SELECT YOUR SIDE",
                TextStyle {
                    font_size: 32.0,
                    color: Color::srgb(0.95, 0.95, 1.0),
                    ..default()
                },
            ).with_style(Style {
                margin: UiRect::bottom(Val::Px(20.0)),
                ..default()
            }));

            // Color buttons in a row
            card.spawn(NodeBundle {
                style: Style {
                    flex_direction: FlexDirection::Row,
                    column_gap: Val::Px(20.0),
                    ..default()
                },
                ..default()
            })
            .with_children(|row| {
                // White button with modern styling
                row.spawn((
                    ButtonBundle {
                        style: Style {
                            width: Val::Px(180.0),
                            height: Val::Px(100.0),
                            justify_content: JustifyContent::Center,
                            align_items: AlignItems::Center,
                            border: UiRect::all(Val::Px(3.0)),
                            ..default()
                        },
                        background_color: BackgroundColor(Color::srgb(0.95, 0.95, 0.92)),
                        border_color: BorderColor(Color::srgb(0.8, 0.75, 0.65)),
                        ..default()
                    },
                    MenuButton::PlayAsWhite,
                ))
                .with_children(|button| {
                    button.spawn(TextBundle::from_section(
                        "♔\nWHITE",
                        TextStyle {
                            font_size: 36.0,
                            color: Color::srgb(0.15, 0.15, 0.15),
                            ..default()
                        },
                    ).with_style(Style {
                        justify_content: JustifyContent::Center,
                        align_items: AlignItems::Center,
                        ..default()
                    }));
                });

                // Black button with modern styling
                row.spawn((
                    ButtonBundle {
                        style: Style {
                            width: Val::Px(180.0),
                            height: Val::Px(100.0),
                            justify_content: JustifyContent::Center,
                            align_items: AlignItems::Center,
                            border: UiRect::all(Val::Px(3.0)),
                            ..default()
                        },
                        background_color: BackgroundColor(Color::srgb(0.15, 0.15, 0.18)),
                        border_color: BorderColor(Color::srgb(0.4, 0.35, 0.3)),
                        ..default()
                    },
                    MenuButton::PlayAsBlack,
                ))
                .with_children(|button| {
                    button.spawn(TextBundle::from_section(
                        "♚\nBLACK",
                        TextStyle {
                            font_size: 36.0,
                            color: Color::srgb(0.95, 0.95, 0.95),
                            ..default()
                        },
                    ).with_style(Style {
                        justify_content: JustifyContent::Center,
                        align_items: AlignItems::Center,
                        ..default()
                    }));
                });
            });
        });

        // Difficulty selection section
        parent.spawn(NodeBundle {
            style: Style {
                flex_direction: FlexDirection::Column,
                align_items: AlignItems::Center,
                padding: UiRect::all(Val::Px(30.0)),
                margin: UiRect::bottom(Val::Px(30.0)),
                ..default()
            },
            background_color: BackgroundColor(Color::srgba(0.12, 0.12, 0.18, 0.6)),
            ..default()
        })
        .with_children(|card| {
            card.spawn(TextBundle::from_section(
                "AI DIFFICULTY LEVEL",
                TextStyle {
                    font_size: 32.0,
                    color: Color::srgb(0.95, 0.95, 1.0),
                    ..default()
                },
            ).with_style(Style {
                margin: UiRect::bottom(Val::Px(10.0)),
                ..default()
            }));

            card.spawn(TextBundle::from_section(
                "1 = Beginner  •  5 = Intermediate  •  10 = Grandmaster",
                TextStyle {
                    font_size: 16.0,
                    color: Color::srgba(0.7, 0.7, 0.8, 0.8),
                    ..default()
                },
            ).with_style(Style {
                margin: UiRect::bottom(Val::Px(20.0)),
                ..default()
            }));

            // Difficulty buttons (1-10) with gradient colors
            card.spawn(NodeBundle {
                style: Style {
                    flex_direction: FlexDirection::Row,
                    justify_content: JustifyContent::Center,
                    align_items: AlignItems::Center,
                    column_gap: Val::Px(12.0),
                    ..default()
                },
                ..default()
            })
            .with_children(|row| {
                for level in 1..=10 {
                    // Color gradient from green (easy) to red (hard)
                    let difficulty_color = if level <= 3 {
                        Color::srgb(0.3, 0.7, 0.3) // Green for easy
                    } else if level <= 6 {
                        Color::srgb(0.7, 0.7, 0.3) // Yellow for medium
                    } else if level <= 8 {
                        Color::srgb(0.8, 0.5, 0.2) // Orange for hard
                    } else {
                        Color::srgb(0.8, 0.2, 0.2) // Red for expert
                    };

                    row.spawn((
                        ButtonBundle {
                            style: Style {
                                width: Val::Px(50.0),
                                height: Val::Px(50.0),
                                justify_content: JustifyContent::Center,
                                align_items: AlignItems::Center,
                                border: UiRect::all(Val::Px(2.0)),
                                ..default()
                            },
                            background_color: BackgroundColor(difficulty_color),
                            border_color: BorderColor(Color::srgba(1.0, 1.0, 1.0, 0.3)),
                            ..default()
                        },
                        MenuButton::Difficulty(level),
                    ))
                    .with_children(|button| {
                        button.spawn(TextBundle::from_section(
                            format!("{}", level),
                            TextStyle {
                                font_size: 26.0,
                                color: Color::srgb(1.0, 1.0, 1.0),
                                ..default()
                            },
                        ));
                    });
                }
            });
        });

        // Start Game button - prominent and inviting
        parent.spawn((
            ButtonBundle {
                style: Style {
                    width: Val::Px(320.0),
                    height: Val::Px(90.0),
                    justify_content: JustifyContent::Center,
                    align_items: AlignItems::Center,
                    border: UiRect::all(Val::Px(3.0)),
                    ..default()
                },
                background_color: BackgroundColor(Color::srgb(0.25, 0.6, 0.25)),
                border_color: BorderColor(Color::srgb(0.4, 0.8, 0.4)),
                ..default()
            },
            MenuButton::StartGame,
        ))
        .with_children(|button| {
            button.spawn(TextBundle::from_section(
                "⚔️  START BATTLE  ⚔️",
                TextStyle {
                    font_size: 40.0,
                    color: Color::srgb(1.0, 1.0, 1.0),
                    ..default()
                },
            ));
        });
    });
}

/// Handles menu button interactions
fn handle_menu_interaction(
    mut interaction_query: Query<
        (&Interaction, &MenuButton, &mut BackgroundColor),
        Changed<Interaction>,
    >,
    mut menu_selection: ResMut<MenuSelection>,
    mut game_state: ResMut<ChessGameState>,
    mut camera_state: ResMut<CameraState>,
    mut ai_difficulty: ResMut<AIDifficulty>,
    mut next_state: ResMut<NextState<AppState>>,
) {
    for (interaction, button, mut color) in interaction_query.iter_mut() {
        match *interaction {
            Interaction::Pressed => {
                match button {
                    MenuButton::PlayAsWhite => {
                        info!("✓ Selected White");
                        menu_selection.color = Some(ChessColor::White);
                        // Gold highlight for selection
                        *color = BackgroundColor(Color::srgb(1.0, 0.92, 0.5));
                    }
                    MenuButton::PlayAsBlack => {
                        info!("✓ Selected Black");
                        menu_selection.color = Some(ChessColor::Black);
                        // Deep blue highlight for selection
                        *color = BackgroundColor(Color::srgb(0.3, 0.35, 0.5));
                    }
                    MenuButton::Difficulty(level) => {
                        info!("🎯 Set difficulty to level {}", level);
                        menu_selection.difficulty = Some(*level);
                        ai_difficulty.0 = *level;
                        // Bright highlight based on difficulty
                        let highlight_color = if *level <= 3 {
                            Color::srgb(0.4, 0.9, 0.4)
                        } else if *level <= 6 {
                            Color::srgb(0.9, 0.9, 0.4)
                        } else if *level <= 8 {
                            Color::srgb(1.0, 0.6, 0.3)
                        } else {
                            Color::srgb(1.0, 0.3, 0.3)
                        };
                        *color = BackgroundColor(highlight_color);
                    }
                    MenuButton::StartGame => {
                        if let (Some(player_color), Some(_difficulty)) = (menu_selection.color, menu_selection.difficulty) {
                            info!("▶️ Starting game as {:?}", player_color);
                            game_state.player_color = player_color;
                            
                            // Set camera to view from player's side
                            // White at bottom (south), Black at top (north)
                            if player_color == ChessColor::White {
                                // White pieces at bottom, camera behind them looking north toward black
                                camera_state.rotation_angle = std::f32::consts::PI;  // Camera at south looking north
                                camera_state.distance = 15.0;  // Pull back for better view
                                next_state.set(AppState::PlayerTurn);
                            } else {
                                // Black pieces at top, camera behind them looking south toward white
                                camera_state.rotation_angle = 0.0;  // Camera at north looking south
                                camera_state.distance = 15.0;  // Pull back for better view
                                next_state.set(AppState::AIThinking);
                            }
                        } else {
                            warn!("⚠️ Please select both color and difficulty before starting!");
                        }
                    }
                }
            }
            Interaction::Hovered => {
                // Check if this is the selected button - if so, keep it bright
                let is_selected = match button {
                    MenuButton::PlayAsWhite => menu_selection.color == Some(ChessColor::White),
                    MenuButton::PlayAsBlack => menu_selection.color == Some(ChessColor::Black),
                    MenuButton::Difficulty(level) => menu_selection.difficulty == Some(*level),
                    MenuButton::StartGame => false,
                };
                
                if !is_selected {
                    *color = BackgroundColor(match button {
                        MenuButton::PlayAsWhite => Color::srgb(1.0, 1.0, 0.98),
                        MenuButton::PlayAsBlack => Color::srgb(0.25, 0.25, 0.32),
                        MenuButton::Difficulty(level) => {
                            if *level <= 3 {
                                Color::srgb(0.35, 0.8, 0.35)
                            } else if *level <= 6 {
                                Color::srgb(0.8, 0.8, 0.35)
                            } else if *level <= 8 {
                                Color::srgb(0.9, 0.6, 0.25)
                            } else {
                                Color::srgb(0.9, 0.25, 0.25)
                            }
                        }
                        MenuButton::StartGame => Color::srgb(0.3, 0.75, 0.3),
                    });
                }
            }
            Interaction::None => {
                // Check if this is the selected button - if so, keep it bright
                let is_selected = match button {
                    MenuButton::PlayAsWhite => menu_selection.color == Some(ChessColor::White),
                    MenuButton::PlayAsBlack => menu_selection.color == Some(ChessColor::Black),
                    MenuButton::Difficulty(level) => menu_selection.difficulty == Some(*level),
                    MenuButton::StartGame => false,
                };
                
                if !is_selected {
                    *color = BackgroundColor(match button {
                        MenuButton::PlayAsWhite => Color::srgb(0.95, 0.95, 0.92),
                        MenuButton::PlayAsBlack => Color::srgb(0.15, 0.15, 0.18),
                        MenuButton::Difficulty(level) => {
                            if *level <= 3 {
                                Color::srgb(0.3, 0.7, 0.3)
                            } else if *level <= 6 {
                                Color::srgb(0.7, 0.7, 0.3)
                            } else if *level <= 8 {
                                Color::srgb(0.8, 0.5, 0.2)
                            } else {
                                Color::srgb(0.8, 0.2, 0.2)
                            }
                        }
                        MenuButton::StartGame => Color::srgb(0.25, 0.6, 0.25),
                    });
                }
            }
        }
    }
}

/// Cleanup menu UI when transitioning out
fn cleanup_menu(
    mut commands: Commands,
    menu_query: Query<Entity, With<MenuUI>>,
    mut menu_selection: ResMut<MenuSelection>,
) {
    for entity in menu_query.iter() {
        commands.entity(entity).despawn_recursive();
    }
    // Reset menu selections
    menu_selection.color = None;
    menu_selection.difficulty = None;
}

/// AI thinking system with difficulty-based move selection
fn ai_thinking_system(
    game_state: Res<ChessGameState>,
    ai_difficulty: Res<AIDifficulty>,
    mut ai_timer: ResMut<AIMoveTimer>,
) {
    // Only calculate move if we don't have a pending one
    if ai_timer.pending_move.is_some() {
        return;
    }
    
    info!("🤖 AI is thinking... (Difficulty: {})", ai_difficulty.0);
    
    // Get AI color (opposite of player)
    let ai_color = game_state.player_color.opposite();
    
    // Verify it's AI's turn
    if game_state.game.current_turn != ai_color {
        warn!("⚠️ Not AI's turn, skipping");
        return;
    }
    
    // Get all legal moves
    let legal_moves = game_state.game.legal_moves();
    
    if legal_moves.is_empty() {
        info!("🏁 AI has no legal moves - game over");
        return;
    }
    
    // Select move based on difficulty level
    let ai_move = select_ai_move(&legal_moves, &game_state.game, ai_difficulty.0);
    
    info!("🤖 AI selected: {} -> {}", ai_move.from.to_algebraic(), ai_move.to.to_algebraic());
    
    // Store the move and reset timer
    ai_timer.pending_move = Some(ai_move);
    ai_timer.timer.reset();
}

/// Delayed AI move execution for visibility
fn ai_move_delay_system(
    mut game_state: ResMut<ChessGameState>,
    mut battle_counter: ResMut<BattleCounter>,
    mut ai_timer: ResMut<AIMoveTimer>,
    mut next_state: ResMut<NextState<AppState>>,
    mut commands: Commands,
    mut pieces_query: Query<(Entity, &mut ChessPiece, &Transform)>,
    time: Res<Time>,
) {
    // Wait for the pending move
    if let Some(ai_move) = ai_timer.pending_move {
        ai_timer.timer.tick(time.delta());
        
        if ai_timer.timer.finished() {
            info!("🤖 Executing AI move after delay");
            
            // Handle captures - move to captured display area
            if ai_move.is_capture() {
                // Get attacker piece type for battle animation
                let attacker_type = game_state.game.board.get_piece(&ai_move.from).map(|p| p.piece_type);
                let attacker_color = game_state.game.board.get_piece(&ai_move.from).map(|p| p.color);
                
                for (entity, piece, _) in pieces_query.iter() {
                    if piece.position == ai_move.to {
                        info!("💥 AI capturing {} piece at {}",
                            if piece.color == ChessColor::White { "white" } else { "black" },
                            ai_move.to.to_algebraic());
                        
                        // Track capture for battle animations
                        battle_counter.total_captures += 1;
                        let should_battle = battle_counter.total_captures % 3 == 0;
                        
                        if should_battle {
                            // Every third capture triggers a battle!
                            if let (Some(attacker_t), Some(attacker_c)) = (attacker_type, attacker_color) {
                                info!("⚔️ EPIC BATTLE #{} COMMENCES!", battle_counter.total_captures / 3);
                                battle_counter.pending_battle = Some(BattleInfo {
                                    attacker_type: attacker_t,
                                    attacker_color: attacker_c,
                                    attacker_position: ai_move.from,
                                    defender_type: piece.piece_type,
                                    defender_color: piece.color,
                                    defender_position: ai_move.to,
                                    chess_move: ai_move,  // Store move for later execution
                                });
                                // Don't execute move yet - battle will handle it
                                // Clear pending move and return early
                                ai_timer.pending_move = None;
                                return;
                            }
                        }
                        
                        // Only mark as captured if NOT doing battle animation
                        // Determine capture index and position based on color
                        let (capture_index, x_offset, z_base) = if piece.color == ChessColor::White {
                            let idx = game_state.white_captured_count;
                            game_state.white_captured_count += 1;
                            (idx, 12.0, 0.0) // White pieces on right side
                        } else {
                            let idx = game_state.black_captured_count;
                            game_state.black_captured_count += 1;
                            (idx, -12.0, 0.0) // Black pieces on left side
                        };
                        
                        // Calculate position in captured pieces area (stacked in rows)
                        let row = capture_index / 4;
                        let col = capture_index % 4;
                        let captured_pos = Vec3::new(
                            x_offset,
                            0.2,
                            z_base + (row as f32 * 2.5) - 7.0 + (col as f32 * 0.8)
                        );
                        
                        // Mark as captured and animate to side
                        commands.entity(entity)
                            .insert(CapturedPiece { capture_index })
                            .insert(PieceAnimation {
                                from: board_to_world_position(&ai_move.to),
                                to: captured_pos,
                                progress: 0.0,
                                duration: 0.5,
                            });
                        break;
                    }
                }
            }
            
            // Execute the move
            if game_state.game.make_move(ai_move).is_ok() {
                // Animate the AI piece and update its position
                for (entity, mut piece, _) in pieces_query.iter_mut() {
                    if piece.position == ai_move.from {
                        commands.entity(entity).insert(PieceAnimation {
                            from: board_to_world_position(&ai_move.from),
                            to: board_to_world_position(&ai_move.to),
                            progress: 0.0,
                            duration: 0.8,  // Slower animation for visibility
                        });
                        // Update the piece's position immediately
                        piece.position = ai_move.to;
                        break;
                    }
                }
                
                // Check for game over
                if let Some(result) = game_state.game.is_game_over() {
                    match result {
                        core_logic::GameResult::Checkmate(winner) => {
                            let current_turn = game_state.game.current_turn;
                            let in_check = game_state.game.is_in_check();
                            let legal_moves = game_state.game.legal_moves();
                            info!("👑 CHECKMATE! {} wins!", if winner == ChessColor::White { "White" } else { "Black" });
                            info!("   Current turn: {:?}, In check: {}, Legal moves: {}", current_turn, in_check, legal_moves.len());
                            ai_timer.pending_move = None;
                            next_state.set(AppState::Checkmate);
                            return;
                        }
                        core_logic::GameResult::Stalemate => {
                            info!("🤝 STALEMATE! Game is a draw.");
                            ai_timer.pending_move = None;
                            next_state.set(AppState::Checkmate);
                            return;
                        }
                        core_logic::GameResult::Draw(reason) => {
                            info!("🤝 DRAW: {}", reason);
                            ai_timer.pending_move = None;
                            next_state.set(AppState::Checkmate);
                            return;
                        }
                    }
                }
                
                // Notify if player is in check
                if game_state.game.is_in_check() {
                    info!("⚠️ CHECK! You are in check!");
                }
                
                // Clear pending move
                ai_timer.pending_move = None;
                
                // Check if there's a pending battle - if so, trigger it after AI move
                // The battle will be triggered by check_for_ai_turn after animations finish
                next_state.set(AppState::PlayerTurn);
            } else {
                error!("❌ AI move failed");
                ai_timer.pending_move = None;
                next_state.set(AppState::PlayerTurn);
            }
        }
    }
}

/// Select AI move based on difficulty (1-10)
fn select_ai_move(legal_moves: &[ChessMove], game: &GameState, difficulty: u8) -> ChessMove {
    use rand::seq::SliceRandom;
    use rand::Rng;
    let mut rng = rand::thread_rng();
    
    match difficulty {
        1..=3 => {
            // Beginner: Random moves
            legal_moves.choose(&mut rng).unwrap().clone()
        }
        4..=7 => {
            // Intermediate: Prefer captures, threats, and center control
            let mut scored_moves: Vec<(ChessMove, i32)> = legal_moves.iter()
                .map(|m| {
                    let mut score = 0;
                    
                    // Prefer captures (value based on captured piece)
                    if m.is_capture() {
                        score += 100;
                    }
                    
                    // Value center control strongly
                    let (file, rank) = (m.to.file, m.to.rank);
                    if (file == 3 || file == 4) && (rank == 3 || rank == 4) {
                        score += 50;
                    }
                    
                    // Prefer development (moving pieces forward)
                    if game.current_turn == ChessColor::White && m.to.rank > m.from.rank {
                        score += 15;
                    } else if game.current_turn == ChessColor::Black && m.to.rank < m.from.rank {
                        score += 15;
                    }
                    
                    // Add randomness (less for higher difficulty)
                    let randomness = if difficulty >= 7 { 3 } else { 8 };
                    score += rng.gen_range(-randomness..=randomness);
                    
                    (m.clone(), score)
                })
                .collect();
            
            scored_moves.sort_by_key(|(_, score)| -score);
            let top_n = (scored_moves.len() / (difficulty as usize - 1)).max(1);
            scored_moves[..top_n].choose(&mut rng).unwrap().0.clone()
        }
        8..=10 => {
            // Expert: Minimax algorithm with alpha-beta pruning
            let depth = match difficulty {
                8 => 2,
                9 => 3,
                _ => 3,  // difficulty 10
            };
            
            info!("🧠 Running minimax search (depth: {})", depth);
            minimax_best_move(game, depth, legal_moves)
        }
        _ => legal_moves.choose(&mut rng).unwrap().clone(),
    }
}

/// Minimax algorithm with alpha-beta pruning for strong AI
fn minimax_best_move(game: &GameState, depth: u8, legal_moves: &[ChessMove]) -> ChessMove {
    let maximizing = game.current_turn == ChessColor::White;
    let mut best_move = legal_moves[0];
    let mut best_score = if maximizing { i32::MIN } else { i32::MAX };
    
    for chess_move in legal_moves {
        let mut game_copy = game.clone();
        if game_copy.make_move(*chess_move).is_ok() {
            let score = minimax(&game_copy, depth - 1, i32::MIN, i32::MAX, !maximizing);
            
            if maximizing && score > best_score {
                best_score = score;
                best_move = *chess_move;
            } else if !maximizing && score < best_score {
                best_score = score;
                best_move = *chess_move;
            }
        }
    }
    
    info!("🎯 Minimax selected move with score: {}", best_score);
    best_move
}

/// Minimax with alpha-beta pruning
fn minimax(game: &GameState, depth: u8, mut alpha: i32, mut beta: i32, maximizing: bool) -> i32 {
    if depth == 0 {
        return evaluate_position(game);
    }
    
    let legal_moves = game.legal_moves();
    
    if legal_moves.is_empty() {
        // Checkmate or stalemate
        if game.is_in_check() {
            return if maximizing { -10000 } else { 10000 };
        }
        return 0; // Stalemate
    }
    
    if maximizing {
        let mut max_eval = i32::MIN;
        for chess_move in legal_moves {
            let mut game_copy = game.clone();
            if game_copy.make_move(chess_move).is_ok() {
                let eval = minimax(&game_copy, depth - 1, alpha, beta, false);
                max_eval = max_eval.max(eval);
                alpha = alpha.max(eval);
                if beta <= alpha {
                    break; // Beta cutoff
                }
            }
        }
        max_eval
    } else {
        let mut min_eval = i32::MAX;
        for chess_move in legal_moves {
            let mut game_copy = game.clone();
            if game_copy.make_move(chess_move).is_ok() {
                let eval = minimax(&game_copy, depth - 1, alpha, beta, true);
                min_eval = min_eval.min(eval);
                beta = beta.min(eval);
                if beta <= alpha {
                    break; // Alpha cutoff
                }
            }
        }
        min_eval
    }
}

/// Evaluate board position (positive = White winning, negative = Black winning)
fn evaluate_position(game: &GameState) -> i32 {
    let mut score = 0;
    
    // Material evaluation
    for file in 0..8 {
        for rank in 0..8 {
            let pos = Position::new(file, rank);
            if let Some(piece) = game.board.get_piece(&pos) {
                let piece_value = match piece.piece_type {
                    core_logic::PieceType::Pawn => 100,
                    core_logic::PieceType::Knight => 320,
                    core_logic::PieceType::Bishop => 330,
                    core_logic::PieceType::Rook => 500,
                    core_logic::PieceType::Queen => 900,
                    core_logic::PieceType::King => 20000,
                };
                
                let position_bonus = match piece.piece_type {
                    core_logic::PieceType::Pawn => {
                        // Pawns more valuable as they advance
                        if piece.color == ChessColor::White {
                            rank as i32 * 10
                        } else {
                            (7 - rank) as i32 * 10
                        }
                    }
                    core_logic::PieceType::Knight | core_logic::PieceType::Bishop => {
                        // Knights and bishops prefer center
                        let center_distance = (file as i32 - 3).abs() + (rank as i32 - 3).abs();
                        20 - center_distance * 5
                    }
                    _ => 0,
                };
                
                let total_value = piece_value + position_bonus;
                
                if piece.color == ChessColor::White {
                    score += total_value;
                } else {
                    score -= total_value;
                }
            }
        }
    }
    
    // Mobility bonus (more legal moves = better position)
    let mobility = game.legal_moves().len() as i32 * 10;
    if game.current_turn == ChessColor::White {
        score += mobility;
    } else {
        score -= mobility;
    }
    
    score
}

/// Animates battle sequences when pieces are captured
fn animate_battle_sequence(
    time: Res<Time>,
    mut battle_anim_state: ResMut<BattleAnimationState>,
    mut battle_counter: ResMut<BattleCounter>,
    mut camera_state: ResMut<CameraState>,
    mut camera_query: Query<&mut Transform, With<Camera3d>>,
    mut pieces_query: Query<(Entity, &mut ChessPiece, &mut Transform, Option<&mut BattleParticipant>), (Without<Camera3d>, Without<BattleAccessory>, Without<CapturedPiece>)>,
    mut accessories_query: Query<&mut Transform, (With<BattleAccessory>, Without<Camera3d>, Without<ChessPiece>)>,
    mut meshes: ResMut<Assets<Mesh>>,
    mut materials: ResMut<Assets<StandardMaterial>>,
    mut commands: Commands,
    mut next_state: ResMut<NextState<AppState>>,
    mut game_state: ResMut<ChessGameState>,
) {
    let Some(battle_info) = &battle_counter.pending_battle else {
        next_state.set(AppState::PlayerTurn);
        return;
    };
    
    battle_anim_state.timer.tick(time.delta());
    let progress = battle_anim_state.timer.fraction();
    
    // On first frame, mark the pieces participating in battle
    if progress < 0.01 && battle_anim_state.phase == BattlePhase::Introduction {
        for (entity, piece, transform, participant) in pieces_query.iter_mut() {
            if participant.is_none() {
                // Find attacker and defender pieces by exact position
                let is_attacker = piece.position == battle_info.attacker_position && 
                                 piece.piece_type == battle_info.attacker_type && 
                                 piece.color == battle_info.attacker_color;
                let is_defender = piece.position == battle_info.defender_position && 
                                 piece.piece_type == battle_info.defender_type && 
                                 piece.color == battle_info.defender_color;
                
                if is_attacker || is_defender {
                    let role = if is_attacker { BattleRole::Attacker } else { BattleRole::Defender };
                    
                    // Create sword for attacker
                    let sword_entity = if is_attacker {
                        let sword_mesh = create_sword_mesh();
                        let sword_entity = commands.spawn((
                            PbrBundle {
                                mesh: meshes.add(sword_mesh),
                                material: materials.add(StandardMaterial {
                                    base_color: Color::srgb(0.7, 0.7, 0.75), // Silver color
                                    metallic: 0.8,
                                    perceptual_roughness: 0.3,
                                    ..default()
                                }),
                                transform: Transform::from_translation(
                                    transform.translation + Vec3::new(0.3, 0.0, 0.0)
                                ),
                                ..default()
                            },
                            BattleAccessory,
                        )).id();
                        Some(sword_entity)
                    } else {
                        None
                    };
                    
                    // Create shield for defender
                    let shield_entity = if is_defender {
                        let shield_mesh = create_shield_mesh();
                        let shield_entity = commands.spawn((
                            PbrBundle {
                                mesh: meshes.add(shield_mesh),
                                material: materials.add(StandardMaterial {
                                    base_color: Color::srgb(0.4, 0.25, 0.1), // Brown/bronze color
                                    metallic: 0.5,
                                    perceptual_roughness: 0.5,
                                    ..default()
                                }),
                                transform: Transform::from_translation(
                                    transform.translation + Vec3::new(-0.3, 0.2, 0.0)
                                ),
                                ..default()
                            },
                            BattleAccessory,
                        )).id();
                        Some(shield_entity)
                    } else {
                        None
                    };
                    
                    commands.entity(entity).insert(BattleParticipant {
                        role,
                        initial_position: transform.translation,
                        initial_scale: transform.scale,
                        sword_entity,
                        shield_entity,
                    });
                }
            }
        }
    }
    
    // Get camera transform
    if let Ok(mut camera_transform) = camera_query.get_single_mut() {
        match battle_anim_state.phase {
            BattlePhase::Introduction => {
                // Phase 1 (0-1.5s): Dramatic zoom into the battlefield
                if progress < 0.25 {
                    let phase_progress = progress / 0.25;
                    // Save original camera position and zoom in dramatically
                    let target_distance = 8.0;
                    let target_height = 4.5; // Higher up to see the full scene
                    let current_distance = camera_state.distance.lerp(target_distance, phase_progress);
                    let current_height = camera_state.height.lerp(target_height, phase_progress);
                    
                    let x = camera_state.rotation_angle.sin() * current_distance;
                    let z = camera_state.rotation_angle.cos() * current_distance;
                    camera_transform.translation = Vec3::new(x, current_height, z);
                    camera_transform.look_at(Vec3::ZERO, Vec3::Y);
                    
                    // Animate pieces - grow larger and spotlight effect
                    for (_entity, _piece, mut transform, participant) in pieces_query.iter_mut() {
                        if let Some(part) = participant {
                            let scale_factor = 1.0 + (phase_progress * 1.5); // Grow to 2.5x size
                            transform.scale = part.initial_scale * scale_factor;
                            // Slight lift off the board
                            transform.translation.y = part.initial_position.y + (phase_progress * 0.5);
                        } else {
                            // Hide non-participant pieces to avoid fragments
                            transform.scale = Vec3::ZERO;
                        }
                    }
                    
                    if phase_progress > 0.95 {
                        info!("🎬 BATTLE SCENE: {} {:?} vs {} {:?}",
                            if battle_info.attacker_color == ChessColor::White { "White" } else { "Black" },
                            battle_info.attacker_type,
                            if battle_info.defender_color == ChessColor::White { "White" } else { "Black" },
                            battle_info.defender_type
                        );
                        battle_anim_state.phase = BattlePhase::Approach;
                    }
                }
            }
            BattlePhase::Approach => {
                // Phase 2 (1.5-3.5s): Warriors approach each other
                if progress >= 0.25 && progress < 0.58 {
                    let phase_progress = (progress - 0.25) / 0.33;
                    // Slow pan around the battlefield
                    camera_state.rotation_angle += 0.008;
                    let distance = 8.0;
                    let height = 4.5 + (phase_progress * 1.0); // Slight lift
                    
                    let x = camera_state.rotation_angle.sin() * distance;
                    let z = camera_state.rotation_angle.cos() * distance;
                    camera_transform.translation = Vec3::new(x, height, z);
                    camera_transform.look_at(Vec3::ZERO, Vec3::Y);
                    
                    // Animate pieces - move toward each other and rotate
                    for (_entity, _piece, mut transform, participant) in pieces_query.iter_mut() {
                        if let Some(part) = participant {
                            // Keep enlarged
                            transform.scale = part.initial_scale * 2.5;
                            
                            // Move pieces toward center
                            let move_distance = phase_progress * 2.0;
                            if part.role == BattleRole::Attacker {
                                transform.translation = part.initial_position + Vec3::new(move_distance, 0.8, 0.0);
                                // Aggressive rotation
                                transform.rotation = Quat::from_rotation_y(phase_progress * std::f32::consts::PI * 2.0);
                                
                                // Move sword with attacker
                                if let Some(sword_entity) = part.sword_entity {
                                    if let Ok(mut sword_transform) = accessories_query.get_mut(sword_entity) {
                                        sword_transform.translation = transform.translation + Vec3::new(0.4, 0.3, 0.0);
                                        sword_transform.rotation = Quat::from_rotation_y(phase_progress * std::f32::consts::PI * 2.0)
                                            * Quat::from_rotation_z(std::f32::consts::PI * -0.25);
                                    }
                                }
                            } else {
                                transform.translation = part.initial_position + Vec3::new(-move_distance, 0.8, 0.0);
                                // Defensive stance
                                transform.rotation = Quat::from_rotation_y(-phase_progress * std::f32::consts::PI);
                                
                                // Move shield with defender
                                if let Some(shield_entity) = part.shield_entity {
                                    if let Ok(mut shield_transform) = accessories_query.get_mut(shield_entity) {
                                        shield_transform.translation = transform.translation + Vec3::new(-0.4, 0.4, 0.0);
                                        shield_transform.rotation = Quat::from_rotation_y(-phase_progress * std::f32::consts::PI);
                                    }
                            }
                        }
                    } else {
                        // Restore non-participant pieces to normal
                        if transform.scale == Vec3::ZERO {
                            transform.scale = Vec3::splat(1.0);
                        }
                    }
                }
                
                if phase_progress > 0.5 {
                    info!("⚔️ Warriors clash!");
                }                    if phase_progress > 0.95 {
                        battle_anim_state.phase = BattlePhase::Combat;
                    }
                }
            }
            BattlePhase::Combat => {
                // Phase 3 (3.5-5.0s): Epic combat with dramatic camera moves
                if progress >= 0.58 && progress < 0.83 {
                    let phase_progress = (progress - 0.58) / 0.25;
                    // Dynamic camera movement - circle faster
                    camera_state.rotation_angle += 0.015;
                    let distance = 6.0 + (phase_progress.sin() * 2.0); // Zoom in/out
                    let height = 4.5 + (phase_progress.cos() * 1.5); // Bob up/down
                    
                    let x = camera_state.rotation_angle.sin() * distance;
                    let z = camera_state.rotation_angle.cos() * distance;
                    camera_transform.translation = Vec3::new(x, height, z);
                    camera_transform.look_at(Vec3::ZERO, Vec3::Y);
                    
                    // Animate pieces - dramatic combat moves
                    for (_entity, _piece, mut transform, participant) in pieces_query.iter_mut() {
                        if let Some(part) = participant {
                            let combat_intensity = (phase_progress * std::f32::consts::PI * 4.0).sin();
                            
                            if part.role == BattleRole::Attacker {
                                // Attacker strikes - jumping and spinning
                                transform.translation = part.initial_position + Vec3::new(
                                    2.0,
                                    1.5 + combat_intensity.abs() * 1.0, // Jump during combat
                                    0.0
                                );
                                transform.rotation = Quat::from_rotation_y(phase_progress * std::f32::consts::PI * 6.0)
                                    * Quat::from_rotation_x(combat_intensity * 0.3);
                                transform.scale = part.initial_scale * (2.5 + combat_intensity.abs() * 0.5);
                                
                                // Sword swinging animation - dramatic overhead strikes
                                if let Some(sword_entity) = part.sword_entity {
                                    if let Ok(mut sword_transform) = accessories_query.get_mut(sword_entity) {
                                        let swing_angle = combat_intensity * std::f32::consts::PI * 0.8; // Wide swinging arc
                                        sword_transform.translation = transform.translation + Vec3::new(
                                            0.5 + (swing_angle.sin() * 0.3),
                                            0.5 + (swing_angle.cos() * 0.4),
                                            0.0
                                        );
                                        sword_transform.rotation = Quat::from_rotation_y(phase_progress * std::f32::consts::PI * 6.0)
                                            * Quat::from_rotation_z(swing_angle - std::f32::consts::PI * 0.5);
                                    }
                                }
                            } else {
                                // Defender recoils and falls
                                let fall_progress = phase_progress.powf(2.0);
                                transform.translation = part.initial_position + Vec3::new(
                                    -2.0,
                                    1.0 - fall_progress * 0.8, // Fall down
                                    0.0
                                );
                                transform.rotation = Quat::from_rotation_z(fall_progress * std::f32::consts::PI * 0.5)
                                    * Quat::from_rotation_y(-phase_progress * std::f32::consts::PI);
                                transform.scale = part.initial_scale * (2.5 - fall_progress * 1.0);
                                
                                // Shield blocking then dropping as defender falls
                                if let Some(shield_entity) = part.shield_entity {
                                    if let Ok(mut shield_transform) = accessories_query.get_mut(shield_entity) {
                                        if phase_progress < 0.5 {
                                            // Raised defensively
                                            shield_transform.translation = transform.translation + Vec3::new(-0.3, 0.6, 0.2);
                                            shield_transform.rotation = Quat::from_rotation_y(-phase_progress * std::f32::consts::PI)
                                                * Quat::from_rotation_x(std::f32::consts::PI * 0.3);
                                        } else {
                                            // Falls with defender
                                            shield_transform.translation = transform.translation + Vec3::new(
                                                -0.5,
                                                0.3 - fall_progress * 0.5,
                                                0.0
                                            );
                                            shield_transform.rotation = Quat::from_rotation_z(fall_progress * std::f32::consts::PI * 0.8)
                                                * Quat::from_rotation_y(-phase_progress * std::f32::consts::PI);
                                        }
                                    }
                                }
                            }
                        } else {
                            // Restore non-participant pieces to normal
                            if transform.scale == Vec3::ZERO {
                                transform.scale = Vec3::splat(1.0);
                            }
                        }
                    }
                    
                    if phase_progress > 0.7 {
                        info!("💥 Victory!");
                    }
                    
                    if phase_progress > 0.95 {
                        battle_anim_state.phase = BattlePhase::Conclusion;
                    }
                }
            }
            BattlePhase::Conclusion => {
                // Phase 4 (5.0-6.0s): Zoom back out to game view
                if progress >= 0.83 {
                    let phase_progress = (progress - 0.83) / 0.17;
                    // Zoom back to player's perspective
                    let target_distance = 15.0;
                    let target_height = 12.0;
                    let current_distance = 6.0_f32.lerp(target_distance, phase_progress);
                    let current_height = 4.5_f32.lerp(target_height, phase_progress);
                    
                    // Smoothly return to player's viewing angle
                    let target_angle = if game_state.player_color == ChessColor::White {
                        std::f32::consts::PI
                    } else {
                        0.0
                    };
                    camera_state.rotation_angle = camera_state.rotation_angle.lerp(target_angle, phase_progress * 0.3);
                    
                    let x = camera_state.rotation_angle.sin() * current_distance;
                    let z = camera_state.rotation_angle.cos() * current_distance;
                    camera_transform.translation = Vec3::new(x, current_height, z);
                    camera_transform.look_at(Vec3::ZERO, Vec3::Y);
                    
                    // Return pieces to normal - fade out defeated piece
                    for (entity, _piece, mut transform, participant) in pieces_query.iter_mut() {
                        if let Some(part) = participant {
                            if part.role == BattleRole::Attacker {
                                // Attacker returns to position triumphantly
                                transform.translation = part.initial_position;
                                transform.scale = (part.initial_scale * 2.5).lerp(part.initial_scale, phase_progress);
                                transform.rotation = Quat::IDENTITY;
                                
                                // Fade out sword with attacker
                                if let Some(sword_entity) = part.sword_entity {
                                    if let Ok(mut sword_transform) = accessories_query.get_mut(sword_entity) {
                                        sword_transform.translation = transform.translation + Vec3::new(0.3, 0.0, 0.0);
                                        sword_transform.scale = Vec3::splat(1.0 - phase_progress);
                                        
                                        // Despawn sword at end
                                        if phase_progress > 0.9 {
                                            commands.entity(sword_entity).despawn();
                                        }
                                    }
                                }
                                
                                // Ensure final scale is exactly correct at end
                                if phase_progress > 0.99 {
                                    transform.scale = part.initial_scale;
                                }
                            } else {
                                // Defender fades away (will be captured)
                                transform.scale = part.initial_scale * (1.5 - phase_progress * 1.5);
                                transform.translation.y = -0.5; // Sink into ground
                                
                                // Fade out shield with defender
                                if let Some(shield_entity) = part.shield_entity {
                                    if let Ok(mut shield_transform) = accessories_query.get_mut(shield_entity) {
                                        shield_transform.translation = transform.translation + Vec3::new(-0.3, 0.0, 0.0);
                                        shield_transform.scale = Vec3::splat(1.5 - phase_progress * 1.5);
                                        
                                        // Despawn shield at end
                                        if phase_progress > 0.9 {
                                            commands.entity(shield_entity).despawn();
                                        }
                                    }
                                }
                            }
                            
                            // Remove battle participant component
                            if phase_progress > 0.9 {
                                commands.entity(entity).remove::<BattleParticipant>();
                            }
                        } else {
                            // Restore non-participant pieces to their original scale
                            if transform.scale == Vec3::ZERO {
                                transform.scale = Vec3::splat(0.4);
                            }
                        }
                    }
                    
                    if phase_progress > 0.95 {
                        info!("🎬 Battle sequence complete - returning to game");
                        
                        // Execute the stored move and despawn the defeated defender
                        if let Some(battle_info) = &battle_counter.pending_battle {
                            // Execute the move on the board now
                            let chess_move = battle_info.chess_move;
                            if game_state.game.make_move(chess_move).is_ok() {
                                info!("✅ Battle move executed: {} -> {}", chess_move.from.to_algebraic(), chess_move.to.to_algebraic());
                                
                                // Update attacker visual position
                                for (entity, mut piece, _transform, participant) in pieces_query.iter_mut() {
                                    if let Some(part) = participant {
                                        if part.role == BattleRole::Attacker {
                                            piece.position = chess_move.to;
                                        }
                                    }
                                }
                                
                                // Despawn the defeated defender piece
                                for (entity, piece, _transform, participant) in pieces_query.iter() {
                                    if let Some(part) = participant {
                                        if part.role == BattleRole::Defender {
                                            commands.entity(entity).despawn_recursive();
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        
                        // Clear the pending battle
                        battle_counter.pending_battle = None;
                        // Reset camera to proper game view
                        camera_state.distance = target_distance;
                        camera_state.height = target_height;
                        // Check whose turn it is after the battle
                        if game_state.game.current_turn == game_state.player_color {
                            next_state.set(AppState::PlayerTurn);
                        } else {
                            next_state.set(AppState::AIThinking);
                        }
                    }
                }
            }
        }
    }
}

/// Check if it's AI's turn after player moves
fn check_for_ai_turn(
    game_state: Res<ChessGameState>,
    battle_counter: Res<BattleCounter>,
    mut battle_anim_state: ResMut<BattleAnimationState>,
    mut next_state: ResMut<NextState<AppState>>,
    animation_query: Query<&PieceAnimation>,
) {
    // Wait for all animations to complete
    if !animation_query.is_empty() {
        return;
    }
    
    // Check if there's a pending battle to trigger
    if battle_counter.pending_battle.is_some() {
        info!("🎬 Launching cinematic battle sequence!");
        battle_anim_state.phase = BattlePhase::Introduction;
        battle_anim_state.timer = Timer::from_seconds(6.0, TimerMode::Once);
        next_state.set(AppState::BattleAnimation);
        return;
    }
    
    // Check if it's AI's turn (current turn is opposite of player color)
    if game_state.game.current_turn != game_state.player_color {
        info!("⏭️ Switching to AI turn");
        next_state.set(AppState::AIThinking);
    }
}

/// Camera controls for rotating and zooming
fn camera_controls(
    keyboard: Res<ButtonInput<KeyCode>>,
    mouse_button: Res<ButtonInput<MouseButton>>,
    mut camera_state: ResMut<CameraState>,
    mut camera_query: Query<&mut Transform, With<Camera3d>>,
    mut scroll_events: EventReader<bevy::input::mouse::MouseWheel>,
    mut motion_events: EventReader<MouseMotion>,
) {
    let mut updated = false;
    
    // Rotation with arrow keys or A/D
    if keyboard.pressed(KeyCode::ArrowLeft) || keyboard.pressed(KeyCode::KeyA) {
        camera_state.rotation_angle += 0.02;
        updated = true;
    }
    if keyboard.pressed(KeyCode::ArrowRight) || keyboard.pressed(KeyCode::KeyD) {
        camera_state.rotation_angle -= 0.02;
        updated = true;
    }

    // Mouse drag rotation (ONLY when right mouse button is held)
    if mouse_button.pressed(MouseButton::Right) {
        for ev in motion_events.read() {
            camera_state.rotation_angle -= ev.delta.x * 0.002;
            camera_state.height += ev.delta.y * 0.01;
            updated = true;
        }
    } else {
        // Clear events if not using them
        motion_events.clear();
    }
    
    // Zoom with mouse wheel or W/S - only changes distance, not angle
    for event in scroll_events.read() {
        camera_state.distance -= event.y * 0.5;
        camera_state.distance = camera_state.distance.clamp(3.0, 30.0);  // Extended range for close-up views
        updated = true;
    }
    
    if keyboard.pressed(KeyCode::ArrowUp) || keyboard.pressed(KeyCode::KeyW) {
        camera_state.distance -= 0.15;
        camera_state.distance = camera_state.distance.clamp(3.0, 30.0);
        updated = true;
    }
    if keyboard.pressed(KeyCode::ArrowDown) || keyboard.pressed(KeyCode::KeyS) {
        camera_state.distance += 0.15;
        camera_state.distance = camera_state.distance.clamp(3.0, 30.0);
        updated = true;
    }
    
    // Adjust height with Q/E
    if keyboard.pressed(KeyCode::KeyQ) {
        camera_state.height += 0.1;
        camera_state.height = camera_state.height.clamp(3.0, 20.0);
        updated = true;
    }
    if keyboard.pressed(KeyCode::KeyE) {
        camera_state.height -= 0.1;
        camera_state.height = camera_state.height.clamp(3.0, 20.0);
        updated = true;
    }
    
    // Update camera position if controls were used
    if updated {
        if let Ok(mut transform) = camera_query.get_single_mut() {
            let angle = camera_state.rotation_angle;
            let distance = camera_state.distance;
            let height = camera_state.height;
            
            let x = angle.sin() * distance;
            let z = angle.cos() * distance;
            
            transform.translation = Vec3::new(x, height, z);
            transform.look_at(Vec3::ZERO, Vec3::Y);
        }
    }
}

/// Update camera position when entering gameplay to match player perspective
fn update_camera_for_player(
    camera_state: Res<CameraState>,
    mut camera_query: Query<&mut Transform, With<Camera3d>>,
) {
    if let Ok(mut transform) = camera_query.get_single_mut() {
        let angle = camera_state.rotation_angle;
        let distance = camera_state.distance;
        let height = camera_state.height;
        
        let x = angle.sin() * distance;
        let z = angle.cos() * distance;
        
        transform.translation = Vec3::new(x, height, z);
        transform.look_at(Vec3::ZERO, Vec3::Y);
        
        info!("📷 Camera updated: angle={:.2}, distance={:.1}, height={:.1}", angle, distance, height);
    }
}

/// Directs the endgame cinematic replay
fn replay_director_system(
    _time: Res<Time>,
) {
    info!("🎬 Replay system active");
    // TODO: Implement camera choreography and move replay
}

/// Component marking game over UI
#[derive(Component)]
struct GameOverUI;

/// Setup game over screen
fn setup_game_over_screen(
    mut commands: Commands,
    game_state: Res<ChessGameState>,
) {
    let result = game_state.game.is_game_over();
    let (main_message, winner_text, text_color) = match result {
        Some(core_logic::GameResult::Checkmate(winner)) => {
            let winner_name = if winner == ChessColor::White { "White" } else { "Black" };
            let color = if winner == ChessColor::White { 
                Color::srgb(0.95, 0.95, 0.95) 
            } else { 
                Color::srgb(0.3, 0.3, 0.3) 
            };
            ("CHECKMATE", Some(format!("{} Victorious", winner_name)), color)
        },
        Some(core_logic::GameResult::Stalemate) => {
            ("STALEMATE", Some("Draw".to_string()), Color::srgb(0.7, 0.7, 0.7))
        },
        Some(core_logic::GameResult::Draw(_)) => {
            ("DRAW", Some("Game Drawn".to_string()), Color::srgb(0.7, 0.7, 0.7))
        },
        None => ("GAME OVER", None, Color::srgb(0.9, 0.9, 0.9)),
    };

    // Overlay UI
    commands.spawn((
        NodeBundle {
            style: Style {
                width: Val::Percent(100.0),
                height: Val::Percent(100.0),
                flex_direction: FlexDirection::Column,
                justify_content: JustifyContent::Center,
                align_items: AlignItems::Center,
                ..default()
            },
            background_color: BackgroundColor(Color::srgba(0.0, 0.0, 0.0, 0.85)),
            ..default()
        },
        GameOverUI,
    ))
    .with_children(|parent| {
        // Main message
        parent.spawn(TextBundle::from_section(
            main_message,
            TextStyle {
                font_size: 72.0,
                color: Color::srgb(0.9, 0.8, 0.5),
                ..default()
            },
        ).with_style(Style {
            margin: UiRect::bottom(Val::Px(20.0)),
            ..default()
        }));

        // Winner/result text
        if let Some(winner) = winner_text {
            parent.spawn(TextBundle::from_section(
                winner,
                TextStyle {
                    font_size: 42.0,
                    color: text_color,
                    ..default()
                },
            ).with_style(Style {
                margin: UiRect::bottom(Val::Px(40.0)),
                ..default()
            }));
        }

        // Instructions
        parent.spawn(TextBundle::from_section(
            "Press SPACE to return to main menu\nPress ESC to quit",
            TextStyle {
                font_size: 28.0,
                color: Color::srgb(0.8, 0.8, 0.8),
                ..default()
            },
        ).with_style(Style {
            margin: UiRect::top(Val::Px(20.0)),
            ..default()
        }));
    });
}

/// Handle input on game over screen
fn handle_game_over_input(
    keyboard: Res<ButtonInput<KeyCode>>,
    mut next_state: ResMut<NextState<AppState>>,
    mut commands: Commands,
    game_over_ui: Query<Entity, With<GameOverUI>>,
    mut app_exit: EventWriter<bevy::app::AppExit>,
) {
    if keyboard.just_pressed(KeyCode::Space) {
        // Clean up game over UI
        for entity in game_over_ui.iter() {
            commands.entity(entity).despawn_recursive();
        }
        // Return to main menu
        next_state.set(AppState::MainMenu);
    } else if keyboard.just_pressed(KeyCode::Escape) {
        app_exit.send(bevy::app::AppExit::Success);
    }
}

/// Handle undo input during player turn
fn handle_undo_input(
    keyboard: Res<ButtonInput<KeyCode>>,
    mut game_state: ResMut<ChessGameState>,
    mut pieces_query: Query<(Entity, &mut ChessPiece, &mut Transform), Without<CapturedPiece>>,
    mut captured_query: Query<(Entity, &ChessPiece, &mut Transform, &CapturedPiece)>,
    mut commands: Commands,
) {
    if keyboard.just_pressed(KeyCode::KeyU) {
        // Undo the last move if there is a move history
        if game_state.game.move_history.is_empty() {
            info!("⏮️ No moves to undo!");
            return;
        }
        
        info!("⏮️ Undoing last move...");
        
        // Clear any current selection
        game_state.selected_piece = None;
        game_state.valid_moves.clear();
        
        // Get the last move from history
        if let Some(last_move) = game_state.game.move_history.pop() {
            info!("✅ Undoing move: {} -> {}", last_move.from.to_algebraic(), last_move.to.to_algebraic());
            
            // Get the piece type that was at the destination
            let moving_piece = game_state.game.board.get_piece(&last_move.to);
            
            if let Some(piece_at_dest) = moving_piece {
                // Move the piece back to its original position on the board
                game_state.game.board.remove_piece(&last_move.to);
                game_state.game.board.set_piece(last_move.from, Piece {
                    has_moved: false, // Reset has_moved flag
                    ..piece_at_dest
                });
                
                // Update the 3D piece position
                for (_entity, mut piece, mut transform) in pieces_query.iter_mut() {
                    if piece.position == last_move.to 
                        && piece.piece_type == piece_at_dest.piece_type
                        && piece.color == piece_at_dest.color {
                        piece.position = last_move.from;
                        transform.translation = Vec3::new(
                            last_move.from.file as f32 - 3.5,
                            0.5,
                            last_move.from.rank as f32 - 3.5,
                        );
                        info!("🔄 Moved piece back from {} to {}", last_move.to.to_algebraic(), last_move.from.to_algebraic());
                        break;
                    }
                }
                
                // Restore captured piece if there was one
                if last_move.is_capture() {
                    // Find the most recently captured piece of the opposite color
                    let mut captured_pieces: Vec<_> = captured_query.iter_mut().collect();
                    captured_pieces.sort_by_key(|(_, _, _, cap)| std::cmp::Reverse(cap.capture_index));
                    
                    if let Some(cap_tuple) = captured_pieces.first_mut() {
                        let (entity, piece, transform, _cap) = cap_tuple;
                        if piece.color != piece_at_dest.color {
                            // Restore the piece to the board
                            let restored_piece = Piece::new(piece.piece_type, piece.color);
                            game_state.game.board.set_piece(last_move.to, restored_piece);
                            
                            // Update 3D position and remove captured marker
                            transform.translation = Vec3::new(
                                last_move.to.file as f32 - 3.5,
                                0.5,
                                last_move.to.rank as f32 - 3.5,
                            );
                            transform.scale = Vec3::splat(1.0);
                            commands.entity(*entity).remove::<CapturedPiece>();
                            
                            // Decrement captured count
                            if piece.color == ChessColor::White {
                                game_state.white_captured_count = game_state.white_captured_count.saturating_sub(1);
                            } else {
                                game_state.black_captured_count = game_state.black_captured_count.saturating_sub(1);
                            }
                            
                            info!("♻️ Restored captured {:?} {:?} to {}", piece.color, piece.piece_type, last_move.to.to_algebraic());
                        }
                    }
                }
                
                // Handle castling undo
                if last_move.is_castling() {
                    let is_kingside = last_move.to.file > last_move.from.file;
                    let rook_from_file = if is_kingside { 7 } else { 0 };
                    let rook_to_file = if is_kingside { 4 } else { 2 };
                    let rank = last_move.from.rank;
                    
                    // Move rook back on board
                    if let Some(rook_piece) = game_state.game.board.remove_piece(&Position::new(rook_to_file, rank)) {
                        game_state.game.board.set_piece(Position::new(rook_from_file, rank), Piece {
                            has_moved: false,
                            ..rook_piece
                        });
                    }
                    
                    // Move rook back in 3D
                    for (_entity, mut piece, mut transform) in pieces_query.iter_mut() {
                        if piece.piece_type == core_logic::PieceType::Rook 
                            && piece.color == piece_at_dest.color
                            && piece.position.file == rook_to_file 
                            && piece.position.rank == rank {
                            piece.position = Position::new(rook_from_file, rank);
                            transform.translation = Vec3::new(
                                rook_from_file as f32 - 3.5,
                                0.5,
                                rank as f32 - 3.5,
                            );
                            info!("🏰 Moved castling rook back to {}", Position::new(rook_from_file, rank).to_algebraic());
                            break;
                        }
                    }
                }
            }
            
            // Switch turn back
            game_state.game.current_turn = game_state.game.current_turn.opposite();
            
        } else {
            info!("❌ Failed to undo move");
        }
    }
}


