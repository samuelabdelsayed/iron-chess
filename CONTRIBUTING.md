# Contributing to Iron Chess

## 🏰 Welcome to the Iron Chess Development Team!

This guide will help you contribute effectively to the Iron Chess project - the revolutionary 3D medieval chess experience.

---

## 🚀 Quick Start for Developers

### Prerequisites
- **Unreal Engine 5.4+** installed via Epic Games Launcher
- **Xcode 14+** (macOS) with command line tools
- **Git** for version control
- **Basic knowledge** of C++, Unreal Engine, and chess rules

### Getting Started
```bash
# Clone the repository
git clone https://github.com/yourusername/iron-chess.git
cd iron-chess

# Generate UE5 project files
"/Users/Shared/Epic Games/UE_5.4/Engine/Binaries/DotNET/UnrealBuildTool/UnrealBuildTool" -projectfiles -project="$(pwd)/IronChess.uproject" -game -rocket -progress

# Open in editor
open IronChess.uproject
```

---

## 🏗️ Project Architecture

### Code Organization
```
Source/IronChess/
├── Core/           # Chess game logic and rules
├── AI/             # AI opponent system  
├── Animation/      # Battle sequence system
└── Cinematic/      # Replay and storytelling
```

### Key Classes
- **`UChessGameLogic`**: Core chess engine with move validation
- **`UChessAIComponent`**: AI opponent with 10 difficulty levels
- **`UBattleSequenceComponent`**: Dynamic battle animations
- **`ACinematicDirector`**: Endgame reenactment system

---

## 🎨 Art & Design Guidelines

### Visual Style
- **Theme**: Medieval England (12th-15th century)
- **Color Palette**: Stone grays, iron blacks, royal golds
- **Lighting**: Dramatic, torch-lit atmosphere
- **Quality**: Photorealistic with stylized elements

### Asset Requirements
- **Chess Pieces**: 5K-15K triangles, PBR materials
- **Environment**: Floating stone arena + castle backdrop
- **Animations**: 30 FPS gameplay, 60 FPS cinematics
- **Audio**: Orchestral medieval soundtrack

Detailed specifications: [`Documentation/Asset_Pipeline.md`](Documentation/Asset_Pipeline.md)

---

## 💻 Coding Standards

### C++ Guidelines
- Follow **Unreal Engine C++ coding standards**
- Use **meaningful variable names** with proper prefixes
- **Document all public APIs** with Doxygen comments
- **Include guard** all header files
- **UCLASS/USTRUCT** macros for UE5 reflection

### Example Code Style
```cpp
UCLASS(BlueprintType, Blueprintable)
class IRONCHESS_API UChessGameLogic : public UObject
{
    GENERATED_BODY()

public:
    /** Validates if the given move is legal according to chess rules */
    UFUNCTION(BlueprintCallable, Category = "Chess")
    bool IsValidMove(const FChessMove& Move) const;

protected:
    /** Current state of the chess board */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Chess")
    FChessBoardState BoardState;

private:
    /** Internal helper for pawn move validation */
    bool IsValidPawnMove(const FChessMove& Move) const;
};
```

### Blueprint Integration
- **Expose C++ functionality** via UFUNCTION
- **Use Blueprint events** for UI callbacks
- **Keep game logic in C++**, UI logic in Blueprint
- **Test both C++ and Blueprint workflows**

---

## 🧪 Testing Guidelines

### What to Test
- **Chess move validation** for all piece types
- **AI decision making** at different difficulty levels
- **Battle sequence triggering** every 3 moves
- **Performance targets** (60 FPS PC, 30 FPS console)

### Testing Workflow
```cpp
// Example unit test
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FChessLogicTest, "IronChess.ChessLogic.BasicMoves",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FChessLogicTest::RunTest(const FString& Parameters)
{
    UChessGameLogic* GameLogic = NewObject<UChessGameLogic>();
    GameLogic->ResetGame();
    
    // Test pawn move
    FChessMove PawnMove(FChessPosition(4, 1), FChessPosition(4, 3)); // e2-e4
    TestTrue("Pawn move should be valid", GameLogic->IsValidMove(PawnMove));
    
    return true;
}
```

---

## 📝 Documentation Standards

### Code Documentation
- **Header comments** explaining class purpose
- **Function documentation** with parameters and return values
- **Inline comments** for complex logic only
- **Update documentation** with code changes

### Git Commit Messages
```
feat(ai): add personality-based move selection
fix(chess): resolve en passant validation bug  
docs(readme): update build instructions
refactor(battle): improve sequence performance
```

### Pull Request Guidelines
1. **Clear description** of changes made
2. **Link to related issues** if applicable  
3. **Include screenshots** for visual changes
4. **Test your changes** thoroughly
5. **Update documentation** as needed

---

## 🔄 Development Workflow

### Branch Strategy
- **`main`**: Production-ready code
- **`develop`**: Integration branch for features
- **`feature/feature-name`**: Individual feature development
- **`hotfix/bug-name`**: Critical bug fixes

### Development Process
1. **Create feature branch** from `develop`
2. **Implement and test** your changes
3. **Update documentation** as needed
4. **Create pull request** to `develop`
5. **Code review** and approval process
6. **Merge to develop** after approval

### Code Review Checklist
- [ ] Code follows style guidelines
- [ ] All tests pass
- [ ] Documentation updated
- [ ] No performance regressions
- [ ] UE5 best practices followed

---

## 🎯 Team Roles & Responsibilities

### Core Systems (C++ Developers)
- **Chess Logic**: Move validation, game state management
- **AI System**: Difficulty scaling, Stockfish integration
- **Performance**: Optimization, memory management
- **Architecture**: System design, integration

### Gameplay (Blueprint Developers)  
- **UI/UX**: Menus, game interface, settings
- **Input Handling**: Mouse/touch controls, accessibility
- **Game Flow**: Tutorials, transitions, save/load
- **Polish**: Visual feedback, juice, feel

### Art Team
- **3D Modeling**: Chess pieces, environment assets
- **Animation**: Piece movements, battle sequences
- **VFX**: Particle effects, magical elements
- **Lighting**: Atmosphere, mood, performance

### Audio Team
- **Music**: Orchestral medieval soundtrack
- **SFX**: Move sounds, battle effects, ambience  
- **Narration**: Professional voice recording
- **Implementation**: Spatial audio, dynamic mixing

---

## 📊 Quality Assurance

### Performance Targets
- **Frame Rate**: 60 FPS (PC), 30 FPS (Console)
- **Memory**: < 4GB RAM usage
- **Loading**: < 15 seconds initial load
- **Responsiveness**: < 100ms input lag

### Bug Reporting
Use GitHub Issues with this template:
```
## Bug Description
Brief description of the issue

## Steps to Reproduce
1. Step one
2. Step two
3. Expected vs actual behavior

## Environment
- Platform: [PC/Mac/PS5/Xbox]
- UE5 Version: [5.4.x]
- Build Configuration: [Development/Shipping]

## Screenshots/Videos
Attach relevant media
```

---

## 🏆 Recognition & Rewards

### Contribution Levels
- **🥉 Contributor**: First merged PR
- **🥈 Regular Contributor**: 5+ merged PRs
- **🥇 Core Contributor**: Major feature implementation
- **💎 Maintainer**: Project architecture and direction

### Ways to Contribute
- **Code**: Features, bug fixes, optimizations
- **Art**: 3D models, textures, animations
- **Audio**: Music, sound effects, narration
- **Documentation**: Guides, tutorials, specifications
- **Testing**: Bug reports, performance analysis
- **Community**: Discord support, feedback collection

---

## 📞 Getting Help

### Resources
- **Documentation**: [`/Documentation/`](Documentation/) folder
- **API Reference**: Generated from code comments
- **UE5 Docs**: [docs.unrealengine.com](https://docs.unrealengine.com)
- **Chess Programming**: [chessprogramming.org](https://www.chessprogramming.org)

### Communication
- **Discord**: [Join our server] (coming soon)
- **GitHub Discussions**: For feature requests and questions  
- **Issues**: For bug reports and technical problems
- **Email**: [dev@ironchess.game] for sensitive matters

---

## 🎮 The Vision

**Iron Chess** is more than a chess game - it's a revolutionary experience that transforms every match into an epic medieval war story. We're creating:

- **The first chess game** with dynamic battle cinematics
- **AI-driven storytelling** that makes every game unique  
- **10 levels of adaptive difficulty** for all skill levels
- **AAA production values** with medieval authenticity

Together, we're building something that will redefine what chess can be in the digital age.

**Welcome to the team! Let's create something legendary! ⚔️🏰**