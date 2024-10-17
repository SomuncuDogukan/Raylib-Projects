//
// Created by Doğukan Somuncu on 11.10.2024.
//
#pragma once

#include "raylib.h"         // Include Raylib for graphics functionality
#include "vector"          // Include vector for using std::vector
#include "colors.h"        // Include colors header for color definitions

// Class representing the game grid
class Grid {
public:
    Grid();  // Constructor to initialize the grid

    void Initialize();  // Method to initialize the grid with empty cells

    void print();  // Method to print the grid to the console (for debugging)

    void Draw();  // Method to draw the grid on the screen

    int grid[20][10]{};  // 2D array representing the grid (20 rows x 10 columns)

    bool IsCellOutside(int row, int column);  // Check if a cell is outside the grid boundaries

    bool IsCellEmpty(int row, int column);  // Check if a cell is empty

    int ClearFullRow();  // Clear full rows and return the number of cleared rows

private:
    int numRows;  // Number of rows in the grid
    int numCols;  // Number of columns in the grid
    int cellSize;  // Size of each cell in pixels
    std::vector<Color> colors;  // Vector to hold colors for the grid cells

    bool IsRowFull(int row);  // Check if a specific row is full

    void ClearRow(int row);  // Clear a specified row

    void MoveRowDown(int row, int numRow);  // Move a specified row down by a given number of rows
};
