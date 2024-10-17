//
// Created by Doğukan Somuncu on 11.10.2024.
//
#pragma once  // Ensure this header file is included only once during compilation

class Position {
public:
    // Constructor to initialize a Position with specific row and column values
    Position(int row, int column);

    int row;    // Row index of the position
    int column; // Column index of the position
};
