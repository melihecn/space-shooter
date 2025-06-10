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
    
    Vector2 getPosition() const;
    void setPosition(Vector2 position);

    Rectangle getBBox() const;
    void setBBox(Rectangle bbox);

    static void initialize();
    static void unload();

private:
    Vector2 position;
    Vector2 direction;
    Rectangle bbox;
    float speed;
    static Texture2D texture;
    float drawScale;

};