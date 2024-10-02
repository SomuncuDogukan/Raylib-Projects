//
// Created by Doğukan Somuncu on 2.10.2024.
//

#include <iostream>
#include "creeper.h++" // Header file

Creeper::Creeper() {
    // Load the texture for the Creeper from a relative path.
    image = LoadTexture("Asset/Creeper.png"); // If relative path does not work, check the working directory.

    //std::cout << "Loading texture from: Asset/Creeper.png" << std::endl;



    // Set the initial position of the Creeper.
    position.x = 50;
    position.y = 50;

    // Set the movement speed of the Creeper.
    speed = 10;
}

Creeper::~Creeper() {
    // Unload the texture to free resources when the Creeper is destroyed.
    UnloadTexture(image);
}

void Creeper::Draw() {
    // Draw the Creeper texture at its current position.
    DrawTextureV(image, position, WHITE);
}

void Creeper::Update() {
    // Update the position of the Creeper based on keyboard input.
    if (IsKeyDown(KEY_RIGHT)) position.x += speed; // Move right
    if (IsKeyDown(KEY_LEFT)) position.x -= speed;  // Move left
    if (IsKeyDown(KEY_UP)) position.y -= speed;    // Move up
    if (IsKeyDown(KEY_DOWN)) position.y += speed;  // Move down
}

Rectangle Creeper::GetRect() {
    // Returns the bounding rectangle of the Creeper for collision detection.
    return Rectangle{position.x, position.y, float(image.width), float(image.height)};
}

void Creeper::DrawHitbox(bool isColliding) {
    // Draw the hitbox of the Creeper. If colliding, it will be red; otherwise, it is not drawn.
    if (isColliding) {
        DrawRectangleLinesEx(GetRect(), 3, RED); // Draw a red outline if colliding.
    }
}
