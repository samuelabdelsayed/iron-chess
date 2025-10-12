# Iron Chess ⚔️🏰

Real-time 3D medieval chess with OpenGL rendering, authentic piece meshes, and interactive gameplay. Experience chess as an epic battlefield with detailed medieval-themed pieces and cinematic battle sequences.

## ✨ Features

### 🎨 Visual Excellence
- **Real 3D OpenGL Rendering** - Hardware-accelerated graphics with proper lighting and shadows
- **Medieval Piece Design** - Authentic models including horse-headed knights, mitred bishops, castle towers, and centurion pawns
- **Enhanced Lighting** - Solid piece colors with directional lighting for depth and realism
- **Smooth Animations** - Visual feedback for piece movement and selections

### 🎮 Interactive Gameplay
- **Intuitive Controls** - Click to select, click to move with visual highlighting
- **Move Validation** - Real-time highlighting of valid moves (yellow=selected, green=legal moves)
- **Dynamic Camera** - Free orbit, zoom, and 4 preset views (White, Black, Top, Side)
- **Battle Sequences** - Cinematic animations triggered during gameplay

### 🤖 AI Opponent
- **6 Difficulty Levels** - From Peasant (beginner) to Legendary (grandmaster)
- **Adaptive Strategy** - AI personality changes with difficulty
- **Medieval Descriptions** - Narrative flavor text for moves and captures

### ♟️ Complete Chess Engine
- **All Standard Rules** - Castling, en passant, pawn promotion, check/checkmate
- **Turn-Based System** - Proper White/Black alternation
- **Move Validation** - Prevents illegal moves, self-check, and rule violations
- **Game State Tracking** - Full board history and move counting

## 🚀 Quick Start

```bash
# Install dependencies (macOS)
brew install cmake glfw glm

# Clone and build
git clone https://github.com/samuelabdelsayed/iron-chess.git
cd iron-chess
bash build.sh

# Play!
./build/bin/IronChess
```

### First Launch
1. Choose your army color (White plays first)
2. Select difficulty level (1-6)
3. 3D window opens with the medieval battlefield
4. Click a piece, see valid moves highlighted, click destination

## 🎮 Controls

| Action | Control |
|--------|---------|
| Select & Move Pieces | **Left Click** |
| Rotate Camera | **Click + Drag** |
| Zoom In/Out | **Mouse Scroll** |
| White View | **Key 1** |
| Black View | **Key 2** |
| Top-Down View | **Key 3** |
| Side View | **Key 4** |
| Battle Animation | **Space** |
| Exit Game | **ESC** |

## 🏗️ Architecture

```
iron-chess/
├── src/
│   ├── core/           # Game engine & main loop
│   ├── rendering/      # OpenGL graphics & shaders
│   ├── gameplay/       # Chess logic & input handling
│   ├── ai/             # AI opponent system
│   └── math/           # Utilities & transformations
├── include/            # Header files
└── build/              # Compiled binaries
```

### Key Technologies
- **Language**: C++20
- **Graphics**: OpenGL 3.3 Core Profile
- **Windowing**: GLFW 3.x
- **Mathematics**: GLM (OpenGL Mathematics)
- **Build System**: CMake

## 🎯 Gameplay Tips

- **Opening Moves**: Start with center pawns (e4, d4) or develop knights early
- **Highlighting System**: Yellow shows selected piece, green shows where it can move
- **Camera Navigation**: Use preset views (1-4) to see the board from different angles
- **Valid Moves**: The game only allows legal chess moves - invalid attempts are blocked
- **AI Difficulty**: Start with Knight (Level 3) for balanced play

## 📋 Requirements

- **Operating System**: macOS (10.14+)
- **Graphics**: OpenGL 3.3+ compatible GPU
- **Build Tools**: CMake 3.15+, C++20 compiler
- **Libraries**: GLFW 3.x, GLM
- **Display**: Recommended 1200x800 or higher resolution

## 🔧 Development

```bash
# Clean build
make clean
bash build.sh

# Debug build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make

# Run tests (if implemented)
./build/bin/IronChessTests
```

## 🎭 Features in Detail

### Medieval Piece Designs
Each piece is crafted with authentic medieval characteristics:
- **Kings**: Crown with royal spikes
- **Queens**: Elegant tall cylinder
- **Rooks**: Castle towers with battlements and arrow slits
- **Bishops**: Pointed mitre with decorative cross
- **Knights**: Detailed horse head with armor
- **Pawns**: Centurion soldiers with helmets

### Battle Sequences
Epic cinematic moments during gameplay featuring:
- Particle effects and visual flair
- Medieval narrative descriptions
- Orchestral music cues (text-based)
- Chronicle system for endgame recap

## 🐛 Troubleshooting

**Issue**: Window doesn't open
- Ensure OpenGL 3.3+ is supported: `glxinfo | grep "OpenGL version"`
- Check GLFW installation: `brew list glfw`

**Issue**: Pieces not selecting correctly
- The coordinate system uses logic rank 0 at bottom (White side)
- Click directly on visible pieces in bottom 2 rows for White

**Issue**: Build fails
- Verify CMake version: `cmake --version` (need 3.15+)
- Check compiler: `clang++ --version` (need C++20 support)

## 📄 License

MIT License - see [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

Built with modern C++ and OpenGL to deliver a rich 3D chess experience with medieval aesthetics and smooth gameplay.
