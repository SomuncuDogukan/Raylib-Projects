#include "raylib.h"

int main() {
    // Initialize the Raylib window
    InitWindow(800, 600, "Raylib Test - Simple Window");

    // Set the background color
    SetTargetFPS(60);  // Set the desired frames per second

    // Main game loop
    while (!WindowShouldClose()) {
        // Start drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);  // Clear the background with white color

        // Draw some text
        DrawText("Hello, Raylib!", 190, 200, 20, LIGHTGRAY);
        DrawText("Press ESC to exit", 180, 250, 20, DARKGRAY);

        // End drawing
        EndDrawing();
    }

    // Close the window and clean up resources
    CloseWindow();
    return 0;
}
