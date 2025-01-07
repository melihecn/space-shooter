#pragma once
#include "raylib.h"

class Player
{
private:
	Vector2 position;
	Texture2D idleSprite;
	Texture2D moveLeftT;
	Texture2D moveRightT;

	Texture2D shootSprite;
	Texture2D deathSprite;
	Texture2D currentSprite;

	int health;
	int shootPower;
	int speed;

public:
	Player();
	Player(Vector2 position);

	~Player();
	
	Vector2 getPosition() const;
	void setPosition(Vector2 position);
	int getSpeed() const;
	void setSpeed(int speed);

	void resetAnimation();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void shoot();
	void draw() const;
	void die();
};

