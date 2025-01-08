#include "Laser.h"
#include <iostream>

Laser::Laser(Vector2 position, Vector2 direction, float speed)
    : position(position), direction(direction), speed(speed)
{
    texture = LoadTexture("./assets/ship/PNG/sprites/ship01/laser.png");
    if (texture.id == 0) {
        std::cerr << "Failed to load laser texture!" << std::endl;
    }
}

Laser::~Laser()
{
    UnloadTexture(texture);
}

void Laser::update()
{
    position.x += direction.x * speed * GetFrameTime();
    position.y += direction.y * speed * GetFrameTime();
}

void Laser::draw() const
{
    DrawTextureEx(texture, position, 0, 1, WHITE);
}

bool Laser::isOffScreen() const
{
    return position.x < 0 || position.x > GetScreenWidth() || position.y < 0 || position.y > GetScreenHeight();
}