# Iron Chess ⚔️🏰

Immersive 3D medieval chess built with Rust and the Bevy game engine. Experience chess as an epic battlefield with physically-based rendering, atmospheric lighting, and smooth gameplay set in medieval England.

## ✨ Features

### 🎨 Visual Excellence
- **PBR Rendering** - Physically-based materials with authentic stone and metallic surfaces
- **Medieval Atmosphere** - Moonlit battlefield with flickering torchlight ambiance
- **Distinctive Piece Meshes** - Recognizable 3D models including L-shaped knights with horse heads
- **Smooth Visuals** - 60 FPS gameplay with anti-aliasing and depth rendering

### 🎮 Interactive Gameplay
- **Intuitive Menu System** - Choose your color and AI difficulty with visual feedback
- **Point-and-Click Controls** - Select pieces and moves with mouse ray-casting
- **Persistent Visual Feedback** - Selected menu buttons stay highlighted (bright yellow/purple/green)
- **Dynamic Camera** - Right-click drag to rotate, keyboard controls, mouse wheel zoom

### 🤖 AI Opponent
- **10 Difficulty Levels** - Configurable challenge from 1 (beginner) to 10 (expert)
- **Legal Move Engine** - AI makes only valid chess moves
- **Turn-Based Play** - Proper White/Black alternation with state management

### ♟️ Complete Chess Engine
- **All Standard Rules** - Castling, en passant, pawn promotion, check/checkmate detection
- **Move Validation** - Comprehensive legal move generation prevents illegal moves
- **Bitflag System** - Efficient move encoding with capture/castle/promotion flags
- **Algebraic Notation** - Full support for standard chess notation (e2-e4, etc.)

## 🚀 Quick Start

```bash
# Prerequisites: Rust 1.70+ with cargo
# Install from https://rustup.rs/

# Clone and run
git clone https://github.com/samuelabdelsayed/iron-chess.git
cd iron-chess
cargo run --release

# Development build (faster compile, slower runtime)
cargo run
```

### First Launch
1. **Main Menu** - Press Start Game
2. **Color Selection** - Click White or Black (buttons turn bright yellow/purple when selected)
3. **Difficulty Selection** - Choose AI level 1-10 (button turns bright green when selected)
4. **Play!** - 3D board loads with pieces ready

## 🎮 Controls

### Menu Navigation
| Action | Control |
|--------|---------|
| Select Button | **Left Click** |
| Confirm Selection | **Click highlighted button again** |

### In-Game Controls
| Action | Control |
|--------|---------|
| Select & Move Pieces | **Left Click** |
| Rotate Camera | **Right Click + Drag** |
| Zoom In/Out | **Mouse Scroll** |
| Pan Left/Right | **A / D Keys** |
| Pan Forward/Back | **W / S Keys** |
| Pan Up/Down | **Q / E Keys** |

## 🏗️ Architecture

```
iron-chess/
├── crates/
│   ├── core-logic/        # Chess engine library
│   │   ├── board.rs       # 8x8 board state & castling
│   │   ├── pieces.rs      # Color, PieceType, Position
│   │   ├── moves.rs       # ChessMove with bitflags
│   │   ├── validation.rs  # Legal move generation
│   │   └── lib.rs         # GameState, make_move, checkmate
│   └── iron-chess/        # Bevy game binary
│       └── src/main.rs    # ECS systems, rendering, UI
├── Cargo.toml             # Workspace configuration
└── target/                # Build artifacts (gitignored)
```

### Key Technologies
- **Language**: Rust 2021 Edition
- **Game Engine**: Bevy 0.14 (ECS architecture)
- **Rendering**: PBR materials with HDR, MSAA, depth prepass
- **Dependencies**: rand 0.8, serde, bitflags 2.6, tracing
- **Build System**: Cargo with workspace structure

## 🎯 Gameplay Tips

- **Menu Selection**: Buttons stay highlighted after selection - click multiple times to confirm
- **Camera Control**: Right-click and drag for free rotation, keyboard for fine positioning
- **Valid Moves**: Game prevents illegal moves - only legal squares are clickable
- **Opening Strategy**: Classic openings work - e4, d4, Nf3, Nc3
- **Knight Recognition**: L-shaped pieces with forward-facing horse heads

## 📋 Requirements

- **Operating System**: macOS, Linux, or Windows
- **Rust**: 1.70 or newer (install via [rustup.rs](https://rustup.rs))
- **Graphics**: Modern GPU with Vulkan/Metal/DirectX 12 support
- **Memory**: 4GB RAM minimum
- **Display**: 1280x720 or higher resolution

## 🔧 Development

```bash
# Check for warnings
cargo clippy

# Run tests
cargo test

# Build optimized release
cargo build --release

# Clean build artifacts
cargo clean

# Check compile without building
cargo check
```

### Project Structure (Bevy ECS)
- **Components**: `ChessPiece`, `BoardSquare`, `MenuButton`, `Selectable`
- **Resources**: `ChessGameState`, `CameraState`, `MenuSelection`, `AIDifficulty`
- **States**: `MainMenu`, `ColorSelect`, `DifficultySelect`, `PlayerTurn`, `AIThinking`, `Checkmate`
- **Systems**: Event-driven with state-dependent system sets

## 🎭 Technical Highlights

### Chess Engine Features
- **8x8 Board Representation** with piece tracking
- **Bitflag Move System** for captures, castling, en passant, promotion
- **Legal Move Generation** with king safety checks
- **Castling Rights Management** (kingside/queenside per player)
- **En Passant Detection** with target square tracking
- **Check & Checkmate Detection**

### Rendering Pipeline
- **PBR Materials**: Metallic pieces (0.9) with varying roughness
- **Directional Lighting**: Moonlight from above at 45° angle
- **Point Lights**: Flickering torchlight for atmosphere (4 corners)
- **Camera**: Perspective projection with orbit controls
- **Mesh Generation**: Procedural piece meshes with distinctive knight shape

## 🐛 Troubleshooting

**Issue**: Cargo build fails
- Update Rust: `rustup update`
- Clean and rebuild: `cargo clean && cargo build`

**Issue**: Menu buttons not responding
- Ensure you're clicking on the button text/background
- Selected buttons change color - click again to proceed

**Issue**: Camera not rotating
- Hold **RIGHT mouse button** (not left) while dragging
- Camera only rotates during gameplay, not in menus

**Issue**: Graphics artifacts or crashes
- Update graphics drivers
- Check GPU supports Vulkan/Metal/DX12
- Try reducing window size in main.rs

## 📄 License

MIT License - see [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

Built with Rust and Bevy to deliver a rich 3D chess experience with medieval aesthetics and smooth gameplay.
