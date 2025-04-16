#include "Laser.h"
#include <iostream>

// Statik texture tanýmý
Texture2D Laser::texture;

Laser::Laser(Vector2 position, Vector2 direction, float speed)
    : position(position), direction(direction), speed(speed)
{
}

Laser::~Laser()
{
}

void Laser::initialize()
{
    texture = LoadTexture("./assets/ship/PNG/sprites/ship01/laser.png");
    if (texture.id == 0) {
        std::cerr << "Failed to load laser texture!" << std::endl;
    }   
}

void Laser::unload()
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
    DrawTextureEx(texture, { position.x + 25, position.y }, 0, 3, WHITE);
}

bool Laser::isOffScreen() const
{
    return position.x < 0 || position.x > GetScreenWidth() || position.y < 0 || position.y > GetScreenHeight();
}