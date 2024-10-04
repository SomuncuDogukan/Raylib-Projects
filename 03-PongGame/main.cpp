#include <iostream>
#include "raylib.h"

using namespace std;

// Global scores for player and CPU
int playerScore = 0;
int cpuScore = 0;

// Ball class representing the ball in the game
class Ball {
public:
    float x, y;      // Position of the ball
    int speedX, speedY; // Speed of the ball in both directions
    int radius;      // Radius of the ball

    // Draw the ball on the screen
    void Draw() {
        DrawCircle(x, y, radius, WHITE);
    }

    // Update the ball's position and check for collisions
    void Update() {
        x += speedX;
        y += speedY;

        // Bounce off top and bottom edges
        if (y + radius >= GetScreenHeight() || y - radius <= 0) {
            speedY *= -1;
        }
        // Check for scoring conditions
        if (x + radius >= GetScreenWidth()) {
            cpuScore++; // CPU scores
            ResetBall();
        }
        if (x - radius <= 0) {
            playerScore++; // Player scores
            ResetBall();
        }
    }

    // Reset the ball to the center of the screen
    void ResetBall() {
        x = GetScreenWidth() / 2;
        y = GetScreenHeight() / 2;

        int speedChoices[2] = {-1, 1};
        speedX *= speedChoices[GetRandomValue(0, 1)];
        speedY *= speedChoices[GetRandomValue(0, 1)];
    }
};

// Paddle class representing paddles in the game
class Paddle {
protected:
    // Restrict paddle movement within the screen bounds
    void ConstrainMovement() {
        if (y <= 0) {
            y = 0;
        }
        if (y + height >= GetScreenHeight()) {
            y = GetScreenHeight() - height;
        }
    }

public:
    float x, y;   // Position of the paddle
    float width, height; // Size of the paddle
    int speed;    // Speed of the paddle movement

    // Draw the paddle on the screen
    void Draw() {
        DrawRectangle(x, y, width, height, WHITE);
    }

    // Update paddle position based on input
    void Update() {
        if (IsKeyDown(KEY_UP)) {
            y -= speed;
        }
        if (IsKeyDown(KEY_DOWN)) {
            y += speed;
        }
        ConstrainMovement(); // Ensure the paddle stays within bounds
    }
};

// CPU Paddle class to control the CPU paddle behavior
class CpuPaddle : public Paddle {
public:
    // Update the CPU paddle's position based on the ball's Y position
    void Update(int ballY) {
        if (y + height / 2 > ballY)
            y -= speed; // Move up if the ball is above the paddle
        if (y + height / 2 <= ballY)
            y += speed; // Move down if the ball is below the paddle
        ConstrainMovement(); // Ensure the CPU paddle stays within bounds
    }
};

Ball ball; // Ball instance
Paddle playerPaddle; // Player paddle instance
CpuPaddle cpuPaddle; // CPU paddle instance

int main() {
    const int screenWidth = 1280;
    const int screenHeight = 800;

    cout << "Starting the game" << endl;

    // Initialize the game window
    InitWindow(screenWidth, screenHeight, "03 Pong Game");
    SetTargetFPS(60); // Set the target frames per second

    // Initialize ball properties
    ball.radius = 20;
    ball.x = screenWidth / 2;
    ball.y = screenHeight / 2;
    ball.speedX = 10;
    ball.speedY = 10;

    // Initialize player paddle properties
    playerPaddle.width = 25;
    playerPaddle.height = 120;
    playerPaddle.x = 10;
    playerPaddle.y = screenHeight / 2 - playerPaddle.height / 2;
    playerPaddle.speed = 6;

    // Initialize CPU paddle properties
    cpuPaddle.width = 25;
    cpuPaddle.height = 120;
    cpuPaddle.x = GetScreenWidth() - cpuPaddle.width - 10;
    cpuPaddle.y = screenHeight / 2 - cpuPaddle.height / 2;
    cpuPaddle.speed = 6;

    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw game elements
        ball.Draw();
        playerPaddle.Draw();
        cpuPaddle.Draw();

        // Draw Score
        DrawText(TextFormat("%i", playerScore), screenWidth / 4, 30, 75, WHITE);
        DrawText(TextFormat("%i", cpuScore), 3 * screenWidth / 4, 30, 75, WHITE);

        // Update game elements
        ball.Update();
        playerPaddle.Update();
        cpuPaddle.Update(ball.y);

        // Check for collisions between the ball and paddles
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius,
                                    Rectangle{playerPaddle.x, playerPaddle.y, playerPaddle.width,
                                              playerPaddle.height})) {
            ball.speedX *= -1; // Bounce back on collision
        }

        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius,
                                    Rectangle{cpuPaddle.x, cpuPaddle.y, cpuPaddle.width, cpuPaddle.height})) {
            ball.speedX *= -1; // Bounce back on collision
        }

        // Draw the horizontal line
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);

        // Draw the middle line
        DrawLine(0, screenHeight/2, screenWidth, screenHeight/2, WHITE);

        // Draw the middle circle
        DrawCircleLines(screenWidth/2, screenHeight/2,250,WHITE);

        EndDrawing();
    }

    CloseWindow(); // Close the window and exit
    return 0;
}

