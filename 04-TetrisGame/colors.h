//
// Created by Doğukan Somuncu on 11.10.2024.
//
#pragma once

#include "raylib.h"
#include <vector>

// Declare color constants for Tetris pieces and the background
extern const Color darkGrey;   // Color for the background or inactive cells
extern const Color blue;       // Color for the I piece
extern const Color green;      // Color for the J piece
extern const Color red;        // Color for the L piece
extern const Color yellow;     // Color for the O piece
extern const Color purple;     // Color for the T piece
extern const Color cyan;       // Color for the S piece
extern const Color orange;     // Color for the Z piece
extern const Color darkBlue;   // Dark blue background color

// Function prototype to get the vector of cell colors
std::vector<Color> GetCellColors();
