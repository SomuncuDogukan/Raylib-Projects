//
// Created by Doğukan Somuncu on 11.10.2024.
//
#include "block.h"
#include "colors.h"

// Constructor to initialize the Block with default values
Block::Block() {
    cellSize = 30; // Size of each individual block unit (30x30 pixels)
    rotationState = 0; // Initial rotation state (0 = no rotation)
    colors = GetCellColors(); // Fetch colors for the blocks
    rowOffset = 0; // Initial row position offset
    columnOffset = 0; // Initial column position offset
}

// Draw the block's current cells on the screen
void Block::Draw(int offsetX, int offsetY) {
    std::vector<Position> tiles = GetCellPosition(); // Get current positions of block's cells
    for (Position item: tiles) {
        // Draw each cell of the block at the corresponding position, with a color based on block ID
        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}

// Move the block by a specified number of rows and columns
void Block::Move(int rows, int columns) {
    rowOffset += rows; // Update row offset based on the movement
    columnOffset += columns; // Update column offset based on the movement
}

// Get the current position of the block's cells, accounting for movement
std::vector<Position> Block::GetCellPosition() {
    std::vector<Position> tiles = cells[rotationState]; // Get the cells for the current rotation state
    std::vector<Position> movedTiles; // Create a new vector to store the updated positions

    // Adjust each cell's position according to the block's current row and column offset
    for (Position item: tiles) {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos); // Add the new position to the list
    }
    return movedTiles; // Return the adjusted positions
}

// Rotate the block to the next state
void Block::Rotate() {
    rotationState++; // Increment the rotation state to rotate the block
    if (rotationState == (int) cells.size()) { // If it exceeds the number of rotation states available, reset to 0
        rotationState = 0;
    }
}

// Revert to the previous rotation state, useful for undoing invalid rotations
void Block::UndoRotation() {
    rotationState--; // Decrement the rotation state
    if (rotationState == -1) { // If rotation goes below 0, set it to the last rotation state
        rotationState = cells.size() - 1;
    }
}
