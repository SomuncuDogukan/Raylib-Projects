#include "raylib.h"

int main() {
    // Initialize ball position
    int ballX = 400;
    int ballY = 400;

    // Define custom color
    Color myBlue = {10, 90, 200, 255};

    // Initialize the window
    InitWindow(800, 800, "First Raylib");
    SetTargetFPS(60); // Set the desired frames per second

    // Game Loop
    while (!WindowShouldClose()) {
        // 1. Event Handling
        if (IsKeyDown(KEY_RIGHT)) {
            ballX += 3; // Move right
        }
        if (IsKeyDown(KEY_LEFT)) {
            ballX -= 3; // Move left
        }
        if (IsKeyDown(KEY_UP)) {
            ballY -= 3; // Move up
        }
        if (IsKeyDown(KEY_DOWN)) {
            ballY += 3; // Move down
        }

        // 2. Updating Positions
        // (No additional updates needed in this example)

        // 3. Drawing
        BeginDrawing();

        ClearBackground(myBlue); // Clear the background with green color

        DrawCircle(ballX, ballY, 20, WHITE); // Draw the ball

        EndDrawing();
    }

    // Closing the window
    CloseWindow();
    return 0;
}
