# Iron Chess: Rust + Bevy Architecture
## Medieval 3D Chess Experience - Technical Design Document

**Version:** 1.0  
**Target Platform:** Desktop (Windows, macOS, Linux)  
**Engine:** Bevy 0.14  
**Language:** Rust 2021 Edition

---

## 🏗️ System Architecture Overview

### Modular Crate Structure

```
iron-chess/
├── Cargo.toml                 # Workspace root
├── crates/
│   ├── iron-chess/            # Main executable (orchestrator)
│   ├── core-logic/            # Chess rules & game state
│   ├── ai-engine/             # AI opponent (10 difficulty levels)
│   ├── animation/             # Battle sequences & cinematics
│   └── rendering/             # 3D visualization & effects
└── assets/
    ├── models/                # .glb chess pieces & environment
    ├── textures/              # PBR materials (albedo, normal, metallic)
    ├── audio/                 # Battle sounds & orchestral music
    └── shaders/               # Custom WGSL shaders
```

---

## 📦 Crate Responsibilities

### 1. `core-logic` - Chess Engine Foundation
**Purpose:** Pure chess logic with zero dependencies on rendering

**Components:**
- `ChessPiece` - Piece type, color, position, moved status
- `ChessBoard` - 8x8 board state representation
- `GameState` - Current turn, move history, game phase
- `MoveValidator` - Legal move generation & validation

**Systems:**
- Move validation (pawns, knights, bishops, rooks, queens, kings)
- Check/checkmate/stalemate detection
- En passant, castling, promotion rules
- Move history tracking for replay

**Key Types:**
```rust
pub enum PieceType { Pawn, Knight, Bishop, Rook, Queen, King }
pub enum Color { White, Black }
pub struct Position { file: u8, rank: u8 }
pub struct ChessMove { from: Position, to: Position, flags: MoveFlags }
```

---

### 2. `ai-engine` - Intelligent Opponent
**Purpose:** Multi-level AI with asynchronous thinking

**Difficulty Levels:**
1. **Level 1-3:** Random + basic material evaluation
2. **Level 4-6:** Minimax (depth 3-5) with alpha-beta pruning
3. **Level 7-9:** Advanced evaluation (mobility, king safety, pawn structure)
4. **Level 10:** Stockfish FFI integration (optional) or depth 7+ search

**Components:**
- `AIOpponent` - Resource storing difficulty level
- `SearchState` - Current search progress
- `EvaluationCache` - Transposition table

**Systems:**
- `ai_thinking_system` - Runs on AsyncComputeTaskPool
- `ai_move_application_system` - Applies selected move to board
- Iterative deepening with time management

**Evaluation Features:**
- Material count (P=1, N=3, B=3, R=5, Q=9)
- Positional piece-square tables
- King safety metrics
- Pawn structure analysis

---

### 3. `animation` - Cinematic Battle System
**Purpose:** Battle animations and endgame replay choreography

**State Machine:**
```
Idle → PlayerMove → [EvaluateBattle] → AIThinking → AIMove → [EvaluateBattle] → Idle
                           ↓
                    BattleSequence (every 3rd capture)
                           ↓
                      Cinematic Camera
```

**Components:**
- `BattleAnimation` - Tracks current animation phase
- `AnimationTimer` - Frame-based timing
- `CinematicCamera` - Camera path keyframes
- `MoveCounter` - Triggers battle every 3 captures

**Battle Sequences:**
- Knight: Cavalry charge with lance strike
- Bishop: Staff glow and holy light
- Rook: Battering ram or ballista shot
- Pawn: Shield clash and sword swing
- Queen: Dramatic gesture with particle effects
- King: Regal standoff (rarely captured)

**Systems:**
- `battle_trigger_system` - Detects capture conditions
- `animate_battle_system` - Updates animation state
- `camera_choreography_system` - Smooth camera transitions

---

### 4. `rendering` - Visual Presentation
**Purpose:** PBR rendering, lighting, and atmospheric effects

**Scene Components:**
- Medieval chessboard (carved stone tiles)
- Volumetric fog with HDR bloom
- Point lights (torches) with dynamic shadows
- Particle system (drifting embers)
- Skybox (misty castle environment)

**Systems:**
- `setup_scene_system` - Initial scene construction
- `piece_rendering_system` - Updates piece transforms
- `highlight_system` - Shows valid moves (glowing overlays)
- `particle_update_system` - Ember physics
- `lighting_system` - Dynamic torch flicker

**Materials:**
- Stone: Rough albedo, normal mapped, low metallic
- Metal (pieces): High metallic, reflective
- Cloth (bishops): Subsurface scattering approximation

---

### 5. `iron-chess` - Main Orchestrator
**Purpose:** Ties all systems together, manages game loop

**Bevy App Structure:**
```rust
App::new()
    .add_plugins(DefaultPlugins)
    .add_plugins(CoreLogicPlugin)
    .add_plugins(AIEnginePlugin)
    .add_plugins(AnimationPlugin)
    .add_plugins(RenderingPlugin)
    .add_state::<GameState>()
    .add_systems(Startup, setup)
    .add_systems(Update, handle_input.run_if(in_state(GameState::PlayerTurn)))
    .run();
```

**States:**
- `MainMenu`
- `PlayerTurn`
- `AIThinking`
- `BattleSequence`
- `EndgameReplay`
- `Checkmate`

---

## 🎬 Endgame Replay System

### Replay Architecture

**Data Structure:**
```rust
pub struct GameReplay {
    moves: Vec<AnnotatedMove>,
    key_moments: Vec<ReplayMoment>,
    total_duration: f32,
}

pub struct AnnotatedMove {
    chess_move: ChessMove,
    timestamp: f32,
    evaluation: i32,
    annotation: MoveAnnotation, // Brilliant, Blunder, Sacrifice, etc.
}

pub struct ReplayMoment {
    move_index: usize,
    camera_path: CameraPath,
    narration: String,
    music_cue: MusicCue,
}
```

**Replay Phases:**
1. **Opening** (moves 1-10): Fast playback, overview camera
2. **Middlegame** (moves 11-30): Normal speed, focus on key exchanges
3. **Endgame** (moves 31+): Slow motion on checkmate sequence

**Camera Choreography:**
- Swooping orbital shots around battlefield
- Close-ups on captured pieces
- Bird's-eye view for positional sacrifices
- Cinematic angles for checkmate

**Systems:**
- `replay_director_system` - Selects next replay moment
- `replay_playback_system` - Animates piece movements
- `narration_system` - Displays move commentary
- `music_conductor_system` - Triggers orchestral cues

---

## 🎮 Input & UI System

### Player Interaction
- **Click to Select:** Highlight piece + show legal moves
- **Click to Move:** Execute move with smooth animation
- **Camera Control:** Mouse drag to orbit, scroll to zoom
- **Keyboard Shortcuts:**
  - `1-9`: Switch camera presets
  - `R`: Request draw
  - `U`: Undo last move (vs AI)
  - `ESC`: Pause menu

### UI Elements
- Turn indicator (White/Black banner)
- Material advantage counter
- Captured pieces display
- AI thinking indicator
- Move history log
- Difficulty selector (pre-game)

---

## 🔧 Technical Implementation Details

### ECS Component Design

```rust
// Core entity components
#[derive(Component)]
pub struct Piece {
    pub piece_type: PieceType,
    pub color: Color,
    pub has_moved: bool,
}

#[derive(Component)]
pub struct BoardPosition {
    pub file: u8,
    pub rank: u8,
}

#[derive(Component)]
pub struct Animating {
    pub from: Vec3,
    pub to: Vec3,
    pub progress: f32,
    pub duration: f32,
}

#[derive(Component)]
pub struct Selectable;

#[derive(Component)]
pub struct Highlighted {
    pub color: Color,
}
```

### State Management

```rust
#[derive(States, Default, Debug, Clone, PartialEq, Eq, Hash)]
pub enum GameState {
    #[default]
    MainMenu,
    DifficultySelect,
    PlayerTurn,
    AIThinking,
    PieceAnimating,
    BattleSequence,
    EndgameReplay,
    Checkmate,
}
```

### Resource Definitions

```rust
#[derive(Resource)]
pub struct ChessBoard {
    pub squares: [[Option<Entity>; 8]; 8],
    pub current_turn: Color,
    pub move_count: u32,
}

#[derive(Resource)]
pub struct SelectedPiece {
    pub entity: Option<Entity>,
    pub legal_moves: Vec<Position>,
}

#[derive(Resource)]
pub struct AIConfig {
    pub difficulty: u8, // 1-10
    pub thinking_time: Duration,
}

#[derive(Resource)]
pub struct ReplayData {
    pub moves: Vec<AnnotatedMove>,
    pub current_replay_index: usize,
    pub is_replaying: bool,
}
```

---

## 🚀 Performance Optimization

### Parallel System Execution
- AI search runs on `AsyncComputeTaskPool`
- Particle updates use parallel queries
- Animation systems can run concurrently with physics

### Asset Loading Strategy
- Preload all piece models during `MainMenu` state
- Use Bevy's `AssetServer` with hot-reloading in dev
- Compress textures (BC7 for albedo, BC5 for normals)

### Rendering Optimizations
- Instanced rendering for duplicate pieces
- Level-of-detail (LOD) for distant pieces during replay
- Occlusion culling for off-screen entities
- Batched draw calls for particle effects

---

## 🎯 Extensibility Roadmap

### Phase 1: Core Gameplay (MVP)
- ✅ Complete chess rules
- ✅ Basic AI (levels 1-5)
- ✅ Simple piece movement
- ✅ Material counting

### Phase 2: Cinematic Polish
- ✅ Battle animations (every 3rd capture)
- ✅ PBR lighting and fog
- ✅ Camera choreography
- ✅ Endgame replay system

### Phase 3: Advanced AI
- ✅ Levels 6-10 with alpha-beta pruning
- ✅ Opening book integration
- ✅ Endgame tablebases (Syzygy)
- ✅ AI personality tuning

### Phase 4: Multiplayer
- 🔄 Online matchmaking (WebRTC or dedicated server)
- 🔄 ELO rating system
- 🔄 Spectator mode with shared replay viewing
- 🔄 Tournament brackets

### Phase 5: Story Campaign
- 🔄 Historical chess battles as missions
- 🔄 Narrative voiceovers
- 🔄 Unlockable piece skins
- 🔄 Achievement system

---

## 📚 Development Guidelines

### Code Style
- Use `clippy` with `--all-features --all-targets`
- Format with `rustfmt` (120 char line width)
- Document all public APIs with examples
- Write integration tests for chess logic

### Testing Strategy
- Unit tests for move validation
- Property-based tests for board invariants
- AI regression tests with known positions
- Visual tests for rendering (snapshot testing)

### Version Control
- Feature branches for major systems
- Squash commits before merging to main
- Semantic versioning for releases
- Tag milestones (v0.1.0-alpha, v0.2.0-beta, v1.0.0)

---

## 🎵 Audio Design (Future)

### Sound Effects
- Piece movement: Stone sliding on stone
- Captures: Clash of metal, dramatic thud
- Check: Warning bell
- Checkmate: Victory fanfare or defeat toll

### Music Layers
- Ambient: Soft medieval strings
- Tension: Drums during AI thinking
- Battle: Orchestral crescendo
- Victory: Full orchestra with choir

---

## 🔐 License & Attribution

**Engine:** Bevy (MIT/Apache-2.0 dual license)  
**Project:** MIT License  
**Assets:** To be sourced from public domain or licensed separately

---

## 📝 Summary

This architecture provides:
1. **Clean separation of concerns** via workspace crates
2. **Idiomatic Bevy ECS** with components, systems, and resources
3. **Asynchronous AI** that doesn't block rendering
4. **Cinematic replay system** with camera choreography
5. **Extensible design** for multiplayer and story modes

The foundation is production-ready for a AAA-quality chess experience with medieval atmosphere and Hollywood-style presentation.

**Next Steps:** Implement scaffolding code for each crate, starting with `core-logic`.
