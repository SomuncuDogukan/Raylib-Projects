#include "raylib.h"       // Includes the Raylib library for graphics and game functionality.
#include "creeper.h++"      // Includes the header file for the Creeper class.

int main() {
    Color silver = {192, 192, 192, 255}; // Defines a color (silver) with RGBA values.

    const int screenWidth = 1200;  // Sets the screen width.
    const int screenHeight = 800;   // Sets the screen height.

    // Initializes the game window with the specified width, height, and title.
    InitWindow(screenWidth, screenHeight, "Basic Collision Detection");
    SetTargetFPS(60);  // Sets the target frames per second (FPS) to 60.

    Creeper creeper; // Creates an instance of the Creeper class.
    Rectangle obstacle = Rectangle{800, 200, 300, 300}; // Defines an obstacle rectangle at position (800, 200) with a width and height of 300.

    while (!WindowShouldClose()) { // Main game loop runs until the window is closed.
        creeper.Update(); // Updates the state of the creeper.

        // Checks for collision between the creeper's bounding rectangle and the obstacle.
        bool isColliding = CheckCollisionRecs(creeper.GetRect(), obstacle);

        BeginDrawing(); // Starts the drawing process.
        ClearBackground(silver); // Clears the screen with the silver color.

        // Draws the obstacle rectangle with a black outline.
        DrawRectangleLinesEx(obstacle, 5, BLACK);

        creeper.Draw(); // Draws the creeper on the screen.
        creeper.DrawHitbox(isColliding); // Draws the creeper's hitbox, indicating if it is colliding.

        EndDrawing(); // Ends the drawing process.
    }

    CloseWindow(); // Closes the game window and releases resources.
    return 0; // Exits the program.
}
