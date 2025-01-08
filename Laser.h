#pragma once
#include "raylib.h"

class Laser
{
public:
    Laser(Vector2 position, Vector2 direction, float speed);
    ~Laser();

    void update();
    void draw() const;
    bool isOffScreen() const;

private:
    Vector2 position;
    Vector2 direction;
    float speed;
    Texture2D texture;
};