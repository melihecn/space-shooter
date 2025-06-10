#include "Laser.h"
#include <iostream>

Texture2D Laser::texture;

Laser::Laser(Vector2 position, Vector2 direction, float speed)
    : position(position), direction(direction), speed(speed)
{
    this->drawScale = 3.f;
    this->bbox = { position.x, position.y, 19 * drawScale, 24 * drawScale};
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

    bbox.x = position.x + 25;
    bbox.y = position.y;
}

void Laser::draw() const
{
    DrawTextureEx(texture, { position.x + 25, position.y }, 0, 3, WHITE);
    DrawRectangleLines(bbox.x, bbox.y, bbox.width, bbox.height, RED);
}

bool Laser::isOffScreen() const
{
    return position.x < 0 || position.x > GetScreenWidth() || position.y < 0 || position.y > GetScreenHeight();
}

Vector2 Laser::getPosition() const
{
    return this->position;
}

void Laser::setPosition(Vector2 position)
{
    this->position = position;
}

Rectangle Laser::getBBox() const
{
    return this->bbox;
}

void Laser::setBBox(Rectangle bbox)
{
    this->bbox = bbox;
}