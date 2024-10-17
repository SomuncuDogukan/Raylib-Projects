//
// Created by Doğukan Somuncu on 11.10.2024.
//
#pragma once

#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block {
public:
    Block(); // Constructor to initialize the block

    void Draw(int offsetX, int offsetY); // Draw the block on the screen

    int id; // Block ID to identify the shape of the block (e.g., I, O, T, etc.)

    // Stores the positions of the block's cells for each rotation state
    std::map<int, std::vector<Position>> cells;

    // Move the block by a certain number of rows and columns
    void Move(int rows, int columns);

    // Get the current positions of the block's cells
    std::vector<Position> GetCellPosition();

    // Rotate the block to the next rotation state
    void Rotate();

    // Undo the previous rotation, useful if the rotation is invalid (e.g., collision)
    void UndoRotation();

private:
    int cellSize; // The size of a single block unit (for drawing purposes)

    int rotationState; // Current rotation state of the block (0-3 for Tetris blocks)

    std::vector<Color> colors; // List of colors to differentiate block types

    int rowOffset; // Current row position of the block in the grid
    int columnOffset; // Current column position of the block in the grid
};
