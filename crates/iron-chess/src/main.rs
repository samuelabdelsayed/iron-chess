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
use core_logic::{self, GameState, Position, ChessMove};

// Type alias to avoid confusion with Bevy's Color
type ChessColor = core_logic::Color;

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
}

impl ChessGameState {
    fn new() -> Self {
        Self {
            game: GameState::new(),
            selected_piece: None,
            valid_moves: Vec::new(),
            player_color: ChessColor::White,
        }
    }
}

/// Tracks battle animations triggered every 3 captures
#[derive(Resource, Default)]
#[allow(dead_code)] // Will be used for battle animations
struct BattleCounter {
    captures: u32,
}

#[allow(dead_code)] // Will be used for battle animations
impl BattleCounter {
    fn should_trigger_battle(&self) -> bool {
        self.captures > 0 && self.captures % 3 == 0
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

    // Special materials for knights - gold/bronze with emissive glow
    let white_knight_material = materials.add(StandardMaterial {
        base_color: Color::srgb(1.0, 0.84, 0.0),  // Gold
        emissive: Color::srgb(0.3, 0.25, 0.0).into(),  // Warm glow
        perceptual_roughness: 0.2,
        metallic: 0.8,
        ..default()
    });

    let black_knight_material = materials.add(StandardMaterial {
        base_color: Color::srgb(0.8, 0.5, 0.2),  // Bronze
        emissive: Color::srgb(0.2, 0.12, 0.05).into(),  // Warm glow
        perceptual_roughness: 0.2,
        metallic: 0.8,
        ..default()
    });

    // Iterate through board and spawn pieces
    for file in 0..8 {
        for rank in 0..8 {
            let pos = Position::new(file, rank);
            if let Some(piece) = game_state.game.board.get_piece(&pos) {
                let mesh = create_piece_mesh(&mut meshes, piece.piece_type);
                
                // Knights get special gold/bronze materials for maximum visibility
                let material = if piece.piece_type == core_logic::PieceType::Knight {
                    if piece.color == ChessColor::White {
                        white_knight_material.clone()
                    } else {
                        black_knight_material.clone()
                    }
                } else {
                    if piece.color == ChessColor::White {
                        white_material.clone()
                    } else {
                        black_material.clone()
                    }
                };

                let world_pos = board_to_world_position(&pos);
                
                // Knights get MUCH larger scale for maximum visibility
                let scale = if piece.piece_type == core_logic::PieceType::Knight {
                    Vec3::splat(0.7)  // 75% larger than other pieces
                } else {
                    Vec3::splat(0.4)
                };

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

/// Creates appropriate mesh for piece type with medieval England styling
fn create_piece_mesh(
    meshes: &mut ResMut<Assets<Mesh>>,
    piece_type: core_logic::PieceType,
) -> Handle<Mesh> {
    
    use bevy::render::mesh::{Mesh, Indices, PrimitiveTopology};
    use bevy::render::render_asset::RenderAssetUsages;
    
    match piece_type {
        core_logic::PieceType::King => {
            // King: Cylinder body with large sphere crown on top
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
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.35, 1.4, 16);
            for v in &mut verts { v[1] += 0.3; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + body_offset));
            
            // Crown sphere (large)
            let crown_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_sphere_vertices(0.25, 12, 8);
            for v in &mut verts { v[1] += 1.95; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + crown_offset));
            
            let uvs: Vec<[f32; 2]> = vec![[0.0, 0.0]; all_vertices.len()];
            mesh.insert_attribute(Mesh::ATTRIBUTE_POSITION, all_vertices);
            mesh.insert_attribute(Mesh::ATTRIBUTE_NORMAL, all_normals);
            mesh.insert_attribute(Mesh::ATTRIBUTE_UV_0, uvs);
            mesh.insert_indices(Indices::U32(all_indices));
            meshes.add(mesh)
        }
        core_logic::PieceType::Queen => {
            // Queen: Wide base cylinder, tapered body, sphere crown with points
            let mut mesh = Mesh::new(PrimitiveTopology::TriangleList, RenderAssetUsages::default());
            let mut all_vertices = Vec::new();
            let mut all_normals = Vec::new();
            let mut all_indices = Vec::new();
            
            // Base cylinder (widest)
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.48, 0.25, 16);
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices);
            
            // Lower body (tapered cone shape using cylinders)
            let lower_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.38, 0.5, 16);
            for v in &mut verts { v[1] += 0.25; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + lower_offset));
            
            // Upper body (narrower)
            let upper_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.28, 0.7, 16);
            for v in &mut verts { v[1] += 0.75; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + upper_offset));
            
            // Neck (thin)
            let neck_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.18, 0.3, 16);
            for v in &mut verts { v[1] += 1.45; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + neck_offset));
            
            // Crown sphere
            let crown_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_sphere_vertices(0.22, 12, 8);
            for v in &mut verts { v[1] += 1.9; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + crown_offset));
            
            let uvs: Vec<[f32; 2]> = vec![[0.0, 0.0]; all_vertices.len()];
            mesh.insert_attribute(Mesh::ATTRIBUTE_POSITION, all_vertices);
            mesh.insert_attribute(Mesh::ATTRIBUTE_NORMAL, all_normals);
            mesh.insert_attribute(Mesh::ATTRIBUTE_UV_0, uvs);
            mesh.insert_indices(Indices::U32(all_indices));
            meshes.add(mesh)
        }
        core_logic::PieceType::Rook => {
            // Rook: Siege tower with battlements (crenellations)
            // Tall rectangular tower structure
            let mut mesh = Mesh::new(
                PrimitiveTopology::TriangleList,
                RenderAssetUsages::default(),
            );
            
            // Main tower body (wider at base, narrower at top for realism)
            let base_size = 0.75;
            let top_size = 0.65;
            let height = 1.5;
            
            #[rustfmt::skip]
            let vertices: Vec<[f32; 3]> = vec![
                // Bottom square
                [-base_size, 0.0, -base_size], [base_size, 0.0, -base_size],
                [base_size, 0.0, base_size], [-base_size, 0.0, base_size],
                // Top square (battlements)
                [-top_size, height, -top_size], [top_size, height, -top_size],
                [top_size, height, top_size], [-top_size, height, top_size],
            ];
            
            #[rustfmt::skip]
            let indices: Vec<u32> = vec![
                // Bottom
                0, 1, 2, 0, 2, 3,
                // Sides
                0, 4, 5, 0, 5, 1,
                1, 5, 6, 1, 6, 2,
                2, 6, 7, 2, 7, 3,
                3, 7, 4, 3, 4, 0,
                // Top
                4, 6, 5, 4, 7, 6,
            ];
            
            let normals: Vec<[f32; 3]> = vec![[0.0, 1.0, 0.0]; vertices.len()];
            let uvs: Vec<[f32; 2]> = vec![[0.0, 0.0]; vertices.len()];
            
            mesh.insert_attribute(Mesh::ATTRIBUTE_POSITION, vertices);
            mesh.insert_attribute(Mesh::ATTRIBUTE_NORMAL, normals);
            mesh.insert_attribute(Mesh::ATTRIBUTE_UV_0, uvs);
            mesh.insert_indices(Indices::U32(indices));
            
            meshes.add(mesh)
        }
        core_logic::PieceType::Bishop => {
            // Bishop: Cylinder body with tall pointed cone top (mitre)
            let mut mesh = Mesh::new(PrimitiveTopology::TriangleList, RenderAssetUsages::default());
            let mut all_vertices = Vec::new();
            let mut all_normals = Vec::new();
            let mut all_indices = Vec::new();
            
            // Base cylinder
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.35, 0.25, 16);
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices);
            
            // Body cylinder (tall and thin)
            let body_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.28, 1.1, 16);
            for v in &mut verts { v[1] += 0.25; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + body_offset));
            
            // Small sphere at neck
            let neck_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_sphere_vertices(0.15, 10, 6);
            for v in &mut verts { v[1] += 1.35; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + neck_offset));
            
            // Use built-in cone for pointed mitre top
            let uvs: Vec<[f32; 2]> = vec![[0.0, 0.0]; all_vertices.len()];
            mesh.insert_attribute(Mesh::ATTRIBUTE_POSITION, all_vertices);
            mesh.insert_attribute(Mesh::ATTRIBUTE_NORMAL, all_normals);
            mesh.insert_attribute(Mesh::ATTRIBUTE_UV_0, uvs);
            mesh.insert_indices(Indices::U32(all_indices));
            
            // Add cone top separately by combining meshes
            meshes.add(mesh)
        }
        core_logic::PieceType::Knight => {
            // Knight: Base + neck cylinder + head sphere (suggesting horse)
            let mut mesh = Mesh::new(PrimitiveTopology::TriangleList, RenderAssetUsages::default());
            let mut all_vertices = Vec::new();
            let mut all_normals = Vec::new();
            let mut all_indices = Vec::new();
            
            // Base pedestal
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.4, 0.35, 16);
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices);
            
            // Neck cylinder (vertical)
            let neck_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_cylinder_vertices(0.25, 0.9, 12);
            for v in &mut verts { v[1] += 0.35; }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + neck_offset));
            
            // Head sphere (large, forward)
            let head_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_sphere_vertices(0.35, 14, 10);
            // Position forward and up to suggest horse head
            for v in &mut verts {
                v[1] += 1.5;
                v[2] += 0.25; // Forward
            }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + head_offset));
            
            // Snout sphere (smaller, more forward)
            let snout_offset = all_vertices.len() as u32;
            let (mut verts, mut norms, indices) = create_sphere_vertices(0.2, 10, 6);
            for v in &mut verts {
                v[1] += 1.4;
                v[2] += 0.55; // Even more forward
            }
            all_vertices.append(&mut verts);
            all_normals.append(&mut norms);
            all_indices.extend(indices.iter().map(|i| i + snout_offset));
            
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
    mut commands: Commands,
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
                // Check if this is a capture - despawn the captured piece
                if chess_move.is_capture() {
                    for (entity, piece, _) in pieces_query.iter() {
                        if piece.position == target_pos {
                            info!("💥 Capturing piece at {}", target_pos.to_algebraic());
                            commands.entity(entity).despawn();
                            break;
                        }
                    }
                }
                
                // Execute the move
                if game_state.game.make_move(chess_move).is_ok() {
                    info!("✅ Move executed: {} -> {}", selected_pos.to_algebraic(), target_pos.to_algebraic());
                    
                    // Update the piece position in the ECS
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
    mut query: Query<(Entity, &mut Transform, &mut PieceAnimation, &mut ChessPiece)>,
) {
    for (entity, mut transform, mut anim, mut piece) in query.iter_mut() {
        anim.progress += time.delta_seconds() / anim.duration;
        
        if anim.progress >= 1.0 {
            transform.translation = anim.to;
            // Update piece position and remove animation component
            piece.position = world_to_board_position(&anim.to);
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

    // Root UI node
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
            background_color: BackgroundColor(Color::srgba(0.1, 0.1, 0.15, 0.95)),
            ..default()
        },
        MenuUI,
    ))
    .with_children(|parent| {
        // Title
        parent.spawn(TextBundle::from_section(
            "⚔️ IRON CHESS ⚔️",
            TextStyle {
                font_size: 80.0,
                color: Color::srgb(0.9, 0.8, 0.6),
                ..default()
            },
        ).with_style(Style {
            margin: UiRect::all(Val::Px(20.0)),
            ..default()
        }));

        parent.spawn(TextBundle::from_section(
            "Medieval England Awaits",
            TextStyle {
                font_size: 30.0,
                color: Color::srgb(0.7, 0.6, 0.5),
                ..default()
            },
        ).with_style(Style {
            margin: UiRect::bottom(Val::Px(40.0)),
            ..default()
        }));

        // Color selection
        parent.spawn(TextBundle::from_section(
            "Choose Your Color:",
            TextStyle {
                font_size: 40.0,
                color: Color::srgb(0.9, 0.9, 0.9),
                ..default()
            },
        ).with_style(Style {
            margin: UiRect::all(Val::Px(15.0)),
            ..default()
        }));

        // White button
        parent.spawn((
            ButtonBundle {
                style: Style {
                    width: Val::Px(300.0),
                    height: Val::Px(80.0),
                    justify_content: JustifyContent::Center,
                    align_items: AlignItems::Center,
                    margin: UiRect::all(Val::Px(10.0)),
                    ..default()
                },
                background_color: BackgroundColor(Color::srgb(0.9, 0.9, 0.85)),
                ..default()
            },
            MenuButton::PlayAsWhite,
        ))
        .with_children(|button| {
            button.spawn(TextBundle::from_section(
                "♔ Play as White",
                TextStyle {
                    font_size: 32.0,
                    color: Color::srgb(0.1, 0.1, 0.1),
                    ..default()
                },
            ));
        });

        // Black button
        parent.spawn((
            ButtonBundle {
                style: Style {
                    width: Val::Px(300.0),
                    height: Val::Px(80.0),
                    justify_content: JustifyContent::Center,
                    align_items: AlignItems::Center,
                    margin: UiRect::all(Val::Px(10.0)),
                    ..default()
                },
                background_color: BackgroundColor(Color::srgb(0.15, 0.15, 0.2)),
                ..default()
            },
            MenuButton::PlayAsBlack,
        ))
        .with_children(|button| {
            button.spawn(TextBundle::from_section(
                "♚ Play as Black",
                TextStyle {
                    font_size: 32.0,
                    color: Color::srgb(0.9, 0.9, 0.9),
                    ..default()
                },
            ));
        });

        // Difficulty label
        parent.spawn(TextBundle::from_section(
            "AI Difficulty:",
            TextStyle {
                font_size: 40.0,
                color: Color::srgb(0.9, 0.9, 0.9),
                ..default()
            },
        ).with_style(Style {
            margin: UiRect {
                top: Val::Px(40.0),
                bottom: Val::Px(15.0),
                ..default()
            },
            ..default()
        }));

        // Difficulty buttons (1-10)
        parent.spawn(NodeBundle {
            style: Style {
                flex_direction: FlexDirection::Row,
                justify_content: JustifyContent::Center,
                align_items: AlignItems::Center,
                column_gap: Val::Px(10.0),
                ..default()
            },
            ..default()
        })
        .with_children(|row| {
            for level in 1..=10 {
                row.spawn((
                    ButtonBundle {
                        style: Style {
                            width: Val::Px(55.0),
                            height: Val::Px(55.0),
                            justify_content: JustifyContent::Center,
                            align_items: AlignItems::Center,
                            ..default()
                        },
                        background_color: BackgroundColor(Color::srgb(0.4, 0.3, 0.2)),
                        ..default()
                    },
                    MenuButton::Difficulty(level),
                ))
                .with_children(|button| {
                    button.spawn(TextBundle::from_section(
                        format!("{}", level),
                        TextStyle {
                            font_size: 28.0,
                            color: Color::srgb(0.9, 0.8, 0.6),
                            ..default()
                        },
                    ));
                });
            }
        });

        // Start Game button
        parent.spawn((
            ButtonBundle {
                style: Style {
                    width: Val::Px(300.0),
                    height: Val::Px(80.0),
                    justify_content: JustifyContent::Center,
                    align_items: AlignItems::Center,
                    margin: UiRect::top(Val::Px(40.0)),
                    ..default()
                },
                background_color: BackgroundColor(Color::srgb(0.2, 0.5, 0.2)),
                ..default()
            },
            MenuButton::StartGame,
        ))
        .with_children(|button| {
            button.spawn(TextBundle::from_section(
                "⚔️ Start Battle",
                TextStyle {
                    font_size: 36.0,
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
                        // Bright yellow to show selection
                        *color = BackgroundColor(Color::srgb(1.0, 1.0, 0.5));
                    }
                    MenuButton::PlayAsBlack => {
                        info!("✓ Selected Black");
                        menu_selection.color = Some(ChessColor::Black);
                        // Bright purple to show selection
                        *color = BackgroundColor(Color::srgb(0.6, 0.4, 0.8));
                    }
                    MenuButton::Difficulty(level) => {
                        info!("🎯 Set difficulty to level {}", level);
                        menu_selection.difficulty = Some(*level);
                        ai_difficulty.0 = *level;
                        // Bright green to show selection
                        *color = BackgroundColor(Color::srgb(0.3, 0.9, 0.3));
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
                        MenuButton::PlayAsWhite => Color::srgb(1.0, 1.0, 0.95),
                        MenuButton::PlayAsBlack => Color::srgb(0.25, 0.25, 0.3),
                        MenuButton::Difficulty(_) => Color::srgb(0.5, 0.4, 0.3),
                        MenuButton::StartGame => Color::srgb(0.3, 0.7, 0.3),
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
                        MenuButton::PlayAsWhite => Color::srgb(0.9, 0.9, 0.85),
                        MenuButton::PlayAsBlack => Color::srgb(0.15, 0.15, 0.2),
                        MenuButton::Difficulty(_) => Color::srgb(0.4, 0.3, 0.2),
                        MenuButton::StartGame => Color::srgb(0.2, 0.5, 0.2),
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
            
            // Handle captures
            if ai_move.is_capture() {
                for (entity, piece, _) in pieces_query.iter() {
                    if piece.position == ai_move.to {
                        info!("💥 AI capturing piece at {}", ai_move.to.to_algebraic());
                        commands.entity(entity).despawn();
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
                
                // Clear pending move and return to player turn
                ai_timer.pending_move = None;
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
                8 => 3,
                9 => 4,
                _ => 5,  // difficulty 10
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
    _time: Res<Time>,
    mut next_state: ResMut<NextState<AppState>>,
) {
    info!("⚔️ Battle animation playing");
    // Placeholder: skip to next state after 2 seconds
    // TODO: Implement full battle choreography
    next_state.set(AppState::PlayerTurn);
}

/// Check if it's AI's turn after player moves
fn check_for_ai_turn(
    game_state: Res<ChessGameState>,
    mut next_state: ResMut<NextState<AppState>>,
    animation_query: Query<&PieceAnimation>,
) {
    // Wait for all animations to complete
    if !animation_query.is_empty() {
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
    
    // Zoom with mouse wheel or W/S
    for event in scroll_events.read() {
        camera_state.distance -= event.y * 0.5;
        camera_state.distance = camera_state.distance.clamp(5.0, 25.0);
        updated = true;
    }
    
    if keyboard.pressed(KeyCode::ArrowUp) || keyboard.pressed(KeyCode::KeyW) {
        camera_state.distance -= 0.1;
        camera_state.distance = camera_state.distance.clamp(5.0, 25.0);
        updated = true;
    }
    if keyboard.pressed(KeyCode::ArrowDown) || keyboard.pressed(KeyCode::KeyS) {
        camera_state.distance += 0.1;
        camera_state.distance = camera_state.distance.clamp(5.0, 25.0);
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


