//
// Created by Doğukan Somuncu on 11.10.2024.
//
#include "colors.h"

// Define colors for Tetris pieces and the background
const Color darkGrey = {50, 50, 50, 255};  // Background or inactive cells
const Color blue = {0, 0, 255, 255};       // I piece (light blue)
const Color green = {0, 255, 0, 255};      // J piece (green)
const Color red = {255, 0, 0, 255};        // L piece (red)
const Color yellow = {255, 255, 0, 255};   // O piece (yellow)
const Color purple = {128, 0, 128, 255};   // T piece (purple)
const Color cyan = {0, 255, 255, 255};     // S piece (cyan)
const Color orange = {255, 165, 0, 255};    // Z piece (orange)
const Color darkBlue = {44, 44, 127, 225};  // Dark blue background

// Function to return a vector containing the colors for each piece
std::vector<Color> GetCellColors() {
    return {darkGrey, blue, green, red, yellow, purple, cyan, orange, darkBlue};
}
