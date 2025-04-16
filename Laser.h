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

    static void initialize();
    static void unload();

private:
    Vector2 position;
    Vector2 direction;
    float speed;
    static Texture2D texture; 
};