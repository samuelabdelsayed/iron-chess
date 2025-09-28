# Iron Chess ⚔️🏰
## Epic 3D Medieval Chess Experience

A revolutionary chess game built in Unreal Engine 5 that transforms traditional gameplay into an immersive medieval battle experience, complete with dynamic battle sequences, AI-driven storytelling, and cinematic endgame reenactments.

![Iron Chess Banner](https://via.placeholder.com/800x300/2c3e50/ecf0f1?text=Iron+Chess+%E2%9A%94%EF%B8%8F%F0%9F%8F%B0)

---

## 🎯 Features

### ⚔️ **Living Battlefield**
- **Dynamic Battle Sequences**: Board "comes alive" every 3 moves with epic mini battle-scenes
- **Piece-Specific Combat**: Knights charge on horseback, rooks become siege towers, bishops cast mystical spells
- **Cinematic Camera Work**: Dynamic angles and dramatic lighting for every battle
- **Particle Effects**: Sparks, dust, magical energy, and medieval atmosphere

### 🧠 **Advanced AI System**
- **10 Difficulty Levels**: From absolute beginner to grandmaster-level challenge
- **AI Personalities**: Adjustable aggression, risk-taking, and strategic focus
- **Stockfish Integration**: World-class chess engine for highest difficulties
- **Opening Book**: Extensive library of chess openings for varied gameplay

### 🎬 **Cinematic Storytelling**
- **Endgame Reenactments**: Every completed game becomes an epic medieval battle story
- **5 Narrative Themes**: Heroic Victory, Tactical Genius, Epic Battle, Swift Conquest, Redemption
- **Professional Narration**: British-accented voice acting with medieval flair
- **Orchestral Soundtrack**: Dynamic music that adapts to game state

### 🏰 **Medieval Authenticity**
- **Photorealistic Graphics**: Unreal Engine 5 with Lumen global illumination
- **Hand-Crafted Models**: Detailed 3D chess pieces inspired by medieval England
- **Atmospheric Environment**: Floating stone arena with castle battlements backdrop
- **Period Audio**: Orchestral music and medieval sound effects

---

## 🛠️ Technical Specifications

### **Engine & Platform**
- **Engine**: Unreal Engine 5.4+
- **Language**: C++ with Blueprint integration
- **Platforms**: Windows, macOS, PlayStation 5, Xbox Series X/S
- **Target Performance**: 60 FPS (PC), 30 FPS (Consoles)

### **System Requirements**

#### Minimum Requirements
- **OS**: Windows 10 64-bit / macOS 12.0+
- **Processor**: Intel i5-8400 / AMD Ryzen 5 2600
- **Memory**: 8 GB RAM
- **Graphics**: GTX 1060 6GB / RX 580 8GB
- **DirectX**: Version 12
- **Storage**: 15 GB available space

#### Recommended Requirements
- **OS**: Windows 11 64-bit / macOS 13.0+
- **Processor**: Intel i7-10700K / AMD Ryzen 7 3700X
- **Memory**: 16 GB RAM
- **Graphics**: RTX 3070 / RX 6700 XT
- **DirectX**: Version 12
- **Storage**: 15 GB SSD space

---

## 🚀 Getting Started

### Prerequisites
1. **Unreal Engine 5.4+** installed via Epic Games Launcher
2. **Xcode 14+** (macOS) or **Visual Studio 2022** (Windows) with C++ support
3. **Git** for version control

### Step 1: Install Unreal Engine 5

#### Epic Games Launcher (Recommended)
1. **Download Epic Games Launcher**: Visit [unrealengine.com](https://www.unrealengine.com/download)

**🔒 macOS Security Warning Fix:**
If you get "Apple cannot check it for malicious software":
- **Right-click** the installer → **"Open"** → **"Open"** again
- Or **System Preferences** → **Security & Privacy** → **"Open Anyway"**
- This is normal for non-App Store apps - Epic Games Launcher is safe

2. **Install the Launcher**: Follow the standard macOS installation process
3. **Sign in/Create Account**: You'll need an Epic Games account
4. **Install Unreal Engine 5.4+**: 
   - Open Epic Games Launcher
   - Go to "Unreal Engine" tab
   - Click "Install Engine" 
   - Select version 5.4 or later
   - **Important**: Install to default location for best compatibility

### Step 2: Install Development Tools

#### Xcode (macOS)
```bash
# Install Xcode from App Store or:
xcode-select --install

# Verify installation
xcode-select -p
# Should output: /Applications/Xcode.app/Contents/Developer
```

### Step 3: Build Iron Chess

#### Quick Setup
```bash
# 1. Clone the repository
git clone https://github.com/samuelabdelsayed/iron-chess.git
cd iron-chess

# 2. Generate project files (macOS)
"/Users/Shared/Epic Games/UE_5.4/Engine/Binaries/DotNET/UnrealBuildTool/UnrealBuildTool" -projectfiles -project="$(pwd)/IronChess.uproject" -game -rocket -progress

# 3. Build the project
./build.sh

# 4. Open the project
open IronChess.uproject
```

---

## 🎮 How to Play

### Basic Controls
- **Mouse**: Click to select and move pieces
- **WASD**: Camera movement (if enabled)
- **Mouse Wheel**: Zoom in/out
- **ESC**: Open game menu
- **Space**: Skip current battle sequence
- **Tab**: Toggle UI visibility during cinematics

### Game Modes
1. **Player vs AI**: Challenge the computer at your chosen difficulty
2. **Player vs Player**: Local multiplayer on the same device
3. **Tutorial Mode**: Learn chess basics with medieval storytelling
4. **Replay Mode**: Watch cinematic reenactments of completed games

### AI Difficulty Levels
1. **Beginner**: Random moves with basic patterns
2. **Novice**: Simple position evaluation
3. **Casual**: Minimax depth 2-3
4. **Intermediate**: Minimax depth 3-4
5. **Advanced**: Opening book + tactical awareness
6. **Expert**: Endgame knowledge + advanced tactics
7. **Master**: Deep position analysis + strategic patterns
8. **Grandmaster**: Tournament-level play
9. **World Class**: Limited Stockfish integration
10. **Superhuman**: Full Stockfish power

---

## 🏗️ Architecture Overview

### Core Systems

#### Chess Logic (`/Source/IronChess/Core/`)
- **ChessTypes.h**: Data structures for pieces, moves, and board state
- **ChessGameLogic.h/.cpp**: Complete chess rule implementation with move validation

#### AI System (`/Source/IronChess/AI/`)
- **ChessAIComponent.h/.cpp**: Minimax algorithm with personality system and Stockfish integration

#### Animation System (`/Source/IronChess/Animation/`)
- **BattleSequenceComponent.h/.cpp**: Dynamic battle sequences triggered every 3 moves

#### Cinematic System (`/Source/IronChess/Cinematic/`)
- **CinematicDirector.h/.cpp**: Automated endgame reenactment generation with narrative AI

### Event System
The game uses a comprehensive event-driven architecture:
- `OnMoveMade`: Triggered when any move is completed
- `OnBattleSequenceStarted`: When battle animations begin
- `OnCinematicStarted`: When endgame reenactment begins
- `OnGameStateChanged`: When game state changes (check, checkmate, etc.)

---

## 📁 Project Structure

```
iron-chess/
├── Config/                          # UE5 configuration files
├── Content/                         # UE5 assets and blueprints
├── Documentation/                   # Complete project documentation
│   ├── Design_Document.md          # System architecture
│   ├── Asset_Pipeline.md           # 3D model and audio specs  
│   └── Sample_Narrative_Content.md # Scripts and storyboards
├── Source/                          # C++ source code
│   └── IronChess/
│       ├── Core/                   # Chess game logic
│       ├── AI/                     # AI opponent system
│       ├── Animation/              # Battle sequence system
│       └── Cinematic/              # Replay and storytelling
├── IronChess.uproject              # Main UE5 project file
└── README.md                       # This file
```

---

## 🎨 Asset Pipeline

### 3D Models
- **Chess Pieces**: Medieval-themed with 3 LOD levels each
- **Environment**: Floating stone arena + castle backdrop
- **Polygon Budget**: 5K-15K triangles per piece (LOD0)

### Textures
- **Resolution**: 2048x2048 (pieces), 4096x4096 (detailed models)
- **Formats**: BC7 (albedo), BC5 (normal), BC4 (roughness/metallic)
- **Style**: Photorealistic medieval materials

### Audio
- **Music**: Orchestral medieval soundtrack with adaptive layers
- **SFX**: Sword clashes, horse sounds, castle ambience
- **Narration**: Professional British voice actor
- **Format**: 44.1kHz WAV/OGG

---

## 🧪 Testing

### Running Tests
```bash
# Unit Tests (C++)
# Build in Development configuration and run:
IronChess.exe -ExecCmds="Automation RunTests IronChess"

# Integration Tests
# Launch editor and use Session Frontend for multiplayer testing
```

### Test Coverage
- ✅ Chess move validation
- ✅ AI decision making
- ✅ Battle sequence triggering
- ✅ Cinematic generation
- ✅ Performance benchmarks

### Performance Targets
- **Frame Rate**: 60 FPS (PC), 30 FPS (Console)
- **Memory**: < 4GB RAM usage
- **Loading**: < 15 seconds initial load
- **Draw Calls**: < 2000 per frame

---

## 🚧 Development Status

### ✅ Completed
- [x] **BREAKTHROUGH**: Solved Mac C++ compilation on UE5.6 + Xcode 26.x 🎉
- [x] Core chess engine with all rules  
- [x] AI system with 10 difficulty levels
- [x] Battle animation framework
- [x] Cinematic replay system
- [x] Complete C++ architecture successfully compiling
- [x] Comprehensive documentation

### 🔄 In Progress
- [ ] 3D asset creation (chess pieces, environment)
- [ ] UI/UX implementation
- [ ] Audio integration
- [ ] Platform-specific optimizations

### 📋 Planned
- [ ] Multiplayer networking
- [ ] Tournament mode
- [ ] Custom piece sets
- [ ] VR support
- [ ] Achievement system

---

## 🤝 Contributing

### Development Workflow
1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Follow the coding standards (see `CODING_STANDARDS.md`)
4. Write tests for new functionality
5. Commit changes (`git commit -m 'Add amazing feature'`)
6. Push to branch (`git push origin feature/amazing-feature`)
7. Open a Pull Request

### Coding Standards
- Follow Unreal Engine C++ coding conventions
- Use meaningful variable and function names
- Document all public APIs with Doxygen comments
- Maintain consistent code formatting
- Write unit tests for core gameplay systems

---

## 📚 Documentation

### For Developers
- **[Design Document](Documentation/Design_Document.md)**: Complete system architecture
- **[Asset Pipeline](Documentation/Asset_Pipeline.md)**: 3D model and audio specifications
- **API Reference**: Generated Doxygen documentation (coming soon)

### For Artists
- **[Asset Pipeline](Documentation/Asset_Pipeline.md)**: Detailed requirements for 3D models, textures, and animations
- **Style Guide**: Medieval aesthetic guidelines and reference materials

### For Players
- **Tutorial**: In-game interactive chess tutorial with medieval storytelling
- **Strategy Guide**: Tips for different AI difficulty levels

---

## 🐛 Troubleshooting

### Common Issues

#### Build Errors
```
Q: "Cannot open source file 'CoreMinimal.h'"
A: Ensure Unreal Engine 5.4+ is properly installed and project files are generated
```

#### Performance Issues
```
Q: Game runs slowly on my system
A: Try lowering graphics settings or reducing battle sequence frequency in options
```

#### Audio Problems
```
Q: No sound during battles or narration
A: Check Windows audio settings and ensure game audio isn't muted
```

### Getting Help
- **Issues**: Report bugs via GitHub Issues
- **Discussions**: Join our Discord community (link coming soon)
- **Documentation**: Check the `/Documentation/` folder for detailed guides

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

### Third-Party Assets
- **Stockfish**: GPL v3 License (chess engine integration)
- **Unreal Engine**: Epic Games License
- **Audio**: Custom composed orchestral music

---

## 🙏 Acknowledgments

- **Epic Games** for Unreal Engine 5
- **Stockfish Team** for the world-class chess engine
- **Medieval Chess Community** for historical accuracy consultation
- **Beta Testers** who provided invaluable feedback

---

## 📞 Contact

- **Project Lead**: [Your Name]
- **Email**: contact@ironchess.game
- **Discord**: [Community Server]
- **Twitter**: [@IronChessGame]

---

## 🎯 Roadmap

### Version 1.0 (Launch)
- Complete single-player experience
- 10 AI difficulty levels
- Full cinematic system
- Tutorial mode

### Version 1.1 (Post-Launch)
- Online multiplayer
- Leaderboards and rankings
- Additional chess variants

### Version 2.0 (Major Update)
- VR support
- Custom piece sets
- Tournament mode
- Advanced analytics

---

**Ready to command your medieval army? The battlefield awaits! ⚔️🏰**