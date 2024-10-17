#include "game.h"
#include <random>

// Constructor for the Game class
Game::Game() {
    grid = Grid();                          // Initialize the game grid
    blocks = GetAllBlocks();                // Retrieve all available blocks
    currentBlock = GetRandomBlock();        // Set the current block to a random block
    nextBlock = GetRandomBlock();           // Set the next block to a random block
    gameOver = false;                       // Initialize the game over state to false
    score = 0;                              // Initialize the score to zero
}

// Function to get a random block from the available blocks
Block Game::GetRandomBlock() {
    if (blocks.empty()) {
        blocks = GetAllBlocks();            // Refill the blocks if the list is empty
    }
    int randomIndex = rand() % blocks.size();  // Generate a random index within the bounds of available blocks
    Block block = blocks[randomIndex];      // Select a block at the random index
    blocks.erase(blocks.begin() + randomIndex); // Remove the selected block from the list of available blocks
    return block;                           // Return the randomly selected block
}

// Function to return all available blocks
std::vector<Block> Game::GetAllBlocks() {
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()}; // Return a vector of all block types
}

// Function to draw the current state of the game
void Game::Draw() {
    grid.Draw();                             // Draw the game grid
    currentBlock.Draw(11, 11);              // Draw the current block at the specified position
    switch (nextBlock.id) {
        case 3:
            nextBlock.Draw(255, 290);  // I block spesific
            break;
        case 4:
            nextBlock.Draw(255, 280);  // O block spesific
            break;
        default:
            nextBlock.Draw(285, 270);  // Draw the next block at the specified position


    }
}

// Function to handle user input
void Game::HandleInput() {
    int keyPressed = GetKeyPressed();       // Get the currently pressed key
    if (gameOver && keyPressed != 0) {     // If the game is over and a key is pressed
        gameOver = false;                   // Reset the game over state
        Reset();                            // Reset the game to its initial state
    }
    switch (keyPressed) {                   // Handle movement and rotation based on the pressed key
        case KEY_LEFT:
            MoveBlockLeft();                // Move the block left
            break;
        case KEY_RIGHT:
            MoveBlockRight();               // Move the block right
            break;
        case KEY_DOWN:
            MoveBlockDown();                // Move the block down
            break;
        case KEY_UP:
            RotateBlock();                  // Rotate the block
            break;
    }
}

// Function to move the current block left
void Game::MoveBlockLeft() {
    if (!gameOver) {                        // Only move if the game is not over
        currentBlock.Move(0, -1);          // Move the block left by updating its position
        if (IsBlockOutside() || !BlockFits()) { // Check if the block is outside the grid or doesn't fit
            currentBlock.Move(0, 1);      // Move the block back to the right if it doesn't fit
        }
    }
}

// Function to move the current block right
void Game::MoveBlockRight() {
    if (!gameOver) {                        // Only move if the game is not over
        currentBlock.Move(0, 1);           // Move the block right
        if (IsBlockOutside() || !BlockFits()) { // Check if the block is outside the grid or doesn't fit
            currentBlock.Move(0, -1);     // Move the block back to the left if it doesn't fit
        }
    }
}

// Function to move the current block down
void Game::MoveBlockDown() {
    if (!gameOver) {                        // Only move if the game is not over
        currentBlock.Move(1, 0);           // Move the block down
        if (IsBlockOutside() || !BlockFits()) { // Check if the block is outside the grid or doesn't fit
            currentBlock.Move(-1, 0);     // Move the block back up if it doesn't fit
            LockBlock();                   // Lock the block in place if it cannot move down anymore
        }
    }
}

// Function to check if the current block is outside the grid
bool Game::IsBlockOutside() {
    std::vector<Position> tiles = currentBlock.GetCellPosition(); // Get the position of block tiles
    for (Position item: tiles) {          // Iterate over each tile's position
        if (grid.IsCellOutside(item.row, item.column)) {
            return true;                   // Return true if any tile is outside the grid
        }
    }
    return false;                          // Return false if all tiles are within the grid
}

// Function to lock the current block in the grid
void Game::LockBlock() {
    std::vector<Position> tiles = currentBlock.GetCellPosition(); // Get the position of block tiles
    for (Position item: tiles) {
        grid.grid[item.row][item.column] = currentBlock.id;     // Lock the block's ID in the grid at the tile's position
    }

    currentBlock = nextBlock;                 // Set the current block to the next block
    if (!BlockFits()) {                        // Check if the next block fits in the grid
        gameOver = true;                       // If it doesn't fit, set game over state to true
    }
    nextBlock = GetRandomBlock();             // Get a new random block for the next turn
    int rowsCleared = grid.ClearFullRow();    // Clear any full rows and get the number of cleared rows
    UpdateScore(rowsCleared, 0);              // Update score based on cleared rows
}

// Function to rotate the current block
void Game::RotateBlock() {
    if (!gameOver) {                        // Only rotate if the game is not over
        currentBlock.Rotate();                 // Rotate the block
        if (IsBlockOutside() || !BlockFits()) { // Check if the rotated block is outside the grid or doesn't fit
            currentBlock.UndoRotation();     // Undo the rotation if it doesn't fit
        }
    }
}

// Function to check if the current block fits in the grid
bool Game::BlockFits() {
    std::vector<Position> tiles = currentBlock.GetCellPosition(); // Get the position of block tiles
    for (Position item: tiles) {               // Iterate over each tile's position
        if (!grid.IsCellEmpty(item.row, item.column)) {
            return false;                       // Return false if any tile is not empty (blocked)
        }
    }
    return true;                                // Return true if all tiles fit in the grid
}

// Function to reset the game state
void Game::Reset() {
    grid.Initialize();                          // Reinitialize the grid to empty
    blocks = GetAllBlocks();                    // Retrieve all available blocks again
    currentBlock = GetRandomBlock();            // Set the current block to a random block
    nextBlock = GetRandomBlock();               // Set the next block to a random block
    score = 0;                                  // Reset the score to zero
}

// Function to update the score based on cleared lines
void Game::UpdateScore(int LinesCleared, int moveDownPoints) {
    switch (LinesCleared) {                     // Update score based on the number of lines cleared
        case 1:
            score += 100;                       // Add score for clearing one line
            break;
        case 2:
            score += 200;                       // Add score for clearing two lines
            break;
        case 3:
            score += 500;                       // Add score for clearing three lines
            break;
        default:
            break;                              // No additional score for clearing more than three lines
    }
    score += moveDownPoints;                    // Add any additional points for moving the block down
}
