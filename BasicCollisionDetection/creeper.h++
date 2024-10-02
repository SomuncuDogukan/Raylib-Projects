#pragma once
#include <raylib.h>

// The Creeper class represents a game entity that can be drawn and updated.
class Creeper {
public:
    // Constructor for the Creeper class. Initializes the object.
    Creeper();

    // Destructor for the Creeper class. Cleans up resources.
    ~Creeper();

    // Draws the Creeper on the screen.
    void Draw();

    // Updates the state of the Creeper (e.g., movement, behavior).
    void Update();

    // Returns the bounding rectangle of the Creeper for collision detection.
    Rectangle GetRect();

    // Draws the hitbox of the Creeper.
    // If isColliding is true, the hitbox is likely drawn in a different color to indicate a collision.
    void DrawHitbox(bool isColliding);

private:
    Texture2D image{};     // The texture/image representing the Creeper.
    Vector2 position{};    // The position of the Creeper on the screen.
    int speed;             // The speed at which the Creeper moves.
};
