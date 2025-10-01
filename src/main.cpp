#include "Game.h"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        IronChess::Game game;
        
        if (!game.initialize()) {
            std::cerr << "Failed to initialize Iron Chess!" << std::endl;
            return -1;
        }
        
        std::cout << "🏰 Iron Chess - Medieval Chess Experience 🏰" << std::endl;
        std::cout << "Starting the game..." << std::endl;
        
        game.run();
        game.cleanup();
        
        std::cout << "Thank you for playing Iron Chess!" << std::endl;
        return 0;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
}