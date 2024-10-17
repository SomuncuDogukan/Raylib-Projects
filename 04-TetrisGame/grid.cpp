//
// Created by Doğukan Somuncu on 11.10.2024.
//
#include "grid.h"
#include <iostream>
#include "colors.h"

// Constructor to initialize the grid parameters
Grid::Grid() {
    numRows = 20;     // Number of rows in the grid
    numCols = 10;     // Number of columns in the grid
    cellSize = 30;    // Size of each cell in pixels
    Initialize();     // Call to the initialization function
    colors = GetCellColors(); // Get colors for the cells
}

// Method to initialize the grid with empty cells
void Grid::Initialize() {
    for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numCols; column++) {
            grid[row][column] = 0; // Set all cells to empty (0)
        }
    }
}

// Method to print the grid to the console for debugging
void Grid::print() {
    for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numCols; column++) {
            std::cout << grid[row][column] << " "; // Print the cell value
        }
        std::cout << std::endl; // New line after each row
    }
}

// Method to draw the grid on the screen
void Grid::Draw() {
    for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numCols; column++) {
            int cellValue = grid[row][column]; // Get the value of the cell
            // Draw a rectangle for the cell with the corresponding color
            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

// Method to check if a cell is outside the grid boundaries
bool Grid::IsCellOutside(int row, int column) {
    return (row < 0 || row >= numRows || column < 0 || column >= numCols);
}

// Method to check if a cell is empty
bool Grid::IsCellEmpty(int row, int column) {
    return (grid[row][column] == 0); // Return true if the cell is empty
}

// Method to check if a specified row is full
bool Grid::IsRowFull(int row) {
    for (int column = 0; column < numCols; column++) {
        if (grid[row][column] == 0) {
            return false; // Return false if any cell in the row is empty
        }
    }
    return true; // Return true if the row is full
}

// Method to clear a specified row by setting all its cells to empty
void Grid::ClearRow(int row) {
    for (int column = 0; column < numCols; column++) {
        grid[row][column] = 0; // Set each cell in the row to empty
    }
}

// Method to move a specified row down by a given number of rows
void Grid::MoveRowDown(int row, int numRows) {
    for (int column = 0; column < numCols; column++) {
        grid[row + numRows][column] = grid[row][column]; // Move the row down
        grid[row][column] = 0; // Clear the original row
    }
}

// Method to clear all full rows and move down the rows above them
int Grid::ClearFullRow() {
    int completed = 0; // Counter for completed rows
    for (int row = numRows - 1; row >= 0; row--) {
        if (IsRowFull(row)) {
            ClearRow(row); // Clear the full row
            completed++; // Increment the completed row counter
        } else if (completed > 0) {
            MoveRowDown(row, completed); // Move down rows above the cleared rows
        }
    }
    return completed; // Return the number of completed rows
}
