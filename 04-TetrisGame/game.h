#pragma once

#include "grid.h"
#include "blocks.cpp"

// Class representing the game logic for Tetris
class Game {
public:
    // Constructor to initialize the game state
    Game();

    Grid grid;  // The game grid

    // Method to get a random block from the available blocks
    Block GetRandomBlock();

    // Method to get all available blocks
    std::vector<Block> GetAllBlocks();

    // Method to handle user input for moving and rotating blocks
    void HandleInput();

    // Method to draw the game elements on the screen
    void Draw();

    // Method to move the current block to the left
    void MoveBlockLeft();

    // Method to move the current block to the right
    void MoveBlockRight();

    // Method to move the current block down
    void MoveBlockDown();

    bool gameOver;  // Flag indicating if the game is over
    int score;      // Player's score

private:
    // Method to check if the current block is outside the grid boundaries
    bool IsBlockOutside();

    // Method to rotate the current block
    void RotateBlock();

    // Method to lock the current block in place on the grid
    void LockBlock();

    // Method to check if the current block fits in the grid
    bool BlockFits();

    std::vector<Block> blocks;  // Vector holding available blocks
    Block currentBlock;         // The block currently in play
    Block nextBlock;            // The next block to be played

    // Method to reset the game state
    void Reset();

    // Method to update the player's score based on lines cleared
    void UpdateScore(int LinesCleared, int moveDownPoints);
};
