#include <iostream>
#include "raylib.h"
#include "grid.h"
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0; // Holds the last update time for block movement

// This function checks if the specified time interval has passed
bool EventTriggered(double interval) {
    double currentTime = GetTime(); // Get the current time

    // If the current time exceeds the last update time by the given interval, trigger the event
    if (currentTime - lastUpdateTime > interval) {
        lastUpdateTime = currentTime; // Update the last event trigger time
        return true;
    }

    return false; // Event has not been triggered yet
}

int main() {
    // Initialize the game window
    InitWindow(500, 620, "04 - Tetris Game");
    SetTargetFPS(60); // Set the target FPS to 60

    // Load a custom font for rendering text
    Font font = GetFontDefault(); // Raylib's default font

    // Initialize the game object
    Game game = Game();

    while (!WindowShouldClose()) { // Main game loop
        game.HandleInput(); // Handle player inputs

        // Check if it's time to move the block down based on the interval
        if (EventTriggered(0.2)) {
            game.MoveBlockDown(); // Move the current block down
        }

        // Begin drawing the game elements
        BeginDrawing();
        ClearBackground(darkBlue); // Clear the background to dark blue

        // Draw the score and next block labels
        DrawTextEx(font, "Score", {350, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {365, 175}, 38, 2, WHITE);

        // If the game is over, display the "GAME OVER" text
        if (game.gameOver){
            DrawTextEx(font, "GAME OVER", {320, 450}, 30, 2, WHITE);
            DrawTextEx(font, "Press any key to restart", {320, 490}, 10, 2, WHITE);


        }

        // Draw the score rectangle
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, BLUE);

        // Display the current score
        char scoreText[10];
        sprintf(scoreText, "%d", game.score); // Convert the score integer to a string
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2); // Measure the size of the text

        // Draw the score inside the score box, centered
        DrawTextEx(font, scoreText, {350 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);

        // Draw the "Next" block preview rectangle
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, BLUE);

        game.Draw(); // Draw the current game state (grid, blocks, etc.)

        EndDrawing(); // Finish drawing for this frame
    }

    // Close the game window and clean up
    CloseWindow();

    return 0;
}
