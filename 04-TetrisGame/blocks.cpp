#include "block.h"
#include "position.h"

// L-shaped block class, inheriting from the Block base class
class LBlock : public Block
{
public:
    LBlock()
    {
        id = 1; // Assign a unique ID for color or block recognition
        // Define the cells for each rotation state of the L-block
        cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)}; // Initial vertical position
        cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)}; // First horizontal rotation
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)}; // Second vertical rotation
        cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)}; // Second horizontal rotation
        Move(0, 3); // Adjust the initial position of the block
    }
};

// J-shaped block class, inheriting from the Block base class
class JBlock : public Block
{
public:
    JBlock()
    {
        id = 2; // Assign a unique ID for color or block recognition
        // Define the cells for each rotation state of the J-block
        cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)}; // Initial vertical position
        cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)}; // First horizontal rotation
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)}; // Second vertical rotation
        cells[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)}; // Second horizontal rotation
        Move(0, 3); // Adjust the initial position of the block
    }
};

// I-shaped block class (long bar), inheriting from the Block base class
class IBlock : public Block
{
public:
    IBlock()
    {
        id = 3; // Assign a unique ID for color or block recognition
        // Define the cells for each rotation state of the I-block
        cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)}; // Horizontal position
        cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)}; // Vertical position (rotated)
        cells[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)}; // Horizontal position (rotated back)
        cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)}; // Vertical position (rotated back)
        Move(-1, 3); // Adjust the initial position of the block
    }
};

// O-shaped block class (square), inheriting from the Block base class
class OBlock : public Block
{
public:
    OBlock()
    {
        id = 4; // Assign a unique ID for color or block recognition
        // O-block is a square, so it does not have any rotations
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)}; // Only one position
        Move(0, 4); // Adjust the initial position of the block
    }
};

// S-shaped block class, inheriting from the Block base class
class SBlock : public Block
{
public:
    SBlock()
    {
        id = 5; // Assign a unique ID for color or block recognition
        // Define the cells for each rotation state of the S-block
        cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)}; // Initial position
        cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)}; // First rotation
        cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)}; // Second rotation
        cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)}; // Third rotation
        Move(0, 3); // Adjust the initial position of the block
    }
};

// T-shaped block class, inheriting from the Block base class
class TBlock : public Block
{
public:
    TBlock()
    {
        id = 6; // Assign a unique ID for color or block recognition
        // Define the cells for each rotation state of the T-block
        cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)}; // Initial position
        cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)}; // First rotation
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)}; // Second rotation
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)}; // Third rotation
        Move(0, 3); // Adjust the initial position of the block
    }
};

// Z-shaped block class, inheriting from the Block base class
class ZBlock : public Block
{
public:
    ZBlock()
    {
        id = 7; // Assign a unique ID for color or block recognition
        // Define the cells for each rotation state of the Z-block
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)}; // Initial position
        cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)}; // First rotation
        cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)}; // Second rotation
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)}; // Third rotation
        Move(0, 3); // Adjust the initial position of the block
    }
};
