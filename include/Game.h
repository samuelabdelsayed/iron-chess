#pragma once

#include "ChessBoard.h"
#include "ChessAI.h"
#include "Graphics.h"
#include <GLFW/glfw3.h>
#include <memory>
#include <array>

namespace IronChess {

enum class GameMode {
    PlayerVsPlayer,
    PlayerVsAI,
    AIVsAI,
    Tutorial
};

class Game {
public:
    Game();
    ~Game();
    
    bool initialize();
    void run();
    void cleanup();
    
    // Game state
    void startNewGame(GameMode mode = GameMode::PlayerVsAI);
    void resetGame();
    bool isRunning() const { return running; }
    
    // Input handling
    void handleClick(double x, double y);
    void handleKeyPress(int key);
    void handleScroll(double yOffset);
    
private:
    // Window and rendering
    GLFWwindow* window;
    std::unique_ptr<Camera> camera;
    std::unique_ptr<Shader> pieceShader;
    std::unique_ptr<Shader> boardShader;
    
    // Game logic
    std::unique_ptr<ChessBoard> chessBoard;
    std::unique_ptr<ChessAI> ai;
    GameMode currentGameMode;
    bool running;
    
    // UI state
    Position selectedSquare;
    bool pieceSelected;
    std::vector<Move> highlightedMoves;
    
    // 3D models and textures
    struct PieceModels {
        std::unique_ptr<Model> pawn;
        std::unique_ptr<Model> rook;
        std::unique_ptr<Model> knight;
        std::unique_ptr<Model> bishop;
        std::unique_ptr<Model> queen;
        std::unique_ptr<Model> king;
    } pieceModels;
    
    std::unique_ptr<Model> boardModel;
    std::array<std::unique_ptr<Texture>, 2> pieceTextures; // White, Black
    std::array<std::unique_ptr<Texture>, 2> squareTextures; // Light, Dark
    
    // Rendering
    void render();
    void renderBoard();
    void renderPieces();
    void renderUI();
    void renderHighlights();
    
    // Model loading
    void loadAssets();
    void createPrimitiveModels(); // Fallback if no models found
    
    // Game logic
    void processPlayerMove(const Position& from, const Position& to);
    void processAIMove();
    void updateGameState();
    
    // Utility
    Position screenToBoard(double x, double y) const;
    glm::vec3 boardToWorld(const Position& pos) const;
    Model* getPieceModel(PieceType type) const;
    
    // Event callbacks
    static void mouseCallback(GLFWwindow* window, int button, int action, int mods);
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);
    static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
    
    // Window settings
    static constexpr int WINDOW_WIDTH = 1200;
    static constexpr int WINDOW_HEIGHT = 800;
    static constexpr const char* WINDOW_TITLE = "Iron Chess - Medieval Chess Experience";
};

} // namespace IronChess