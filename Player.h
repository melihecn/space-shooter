#pragma once
#include "raylib.h"
#include "Laser.h"
#include <vector>

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
	bool isMoving;
	std::vector<Laser> lasers;

public:
	Player();
	Player(Vector2 position);

	~Player();
	
	Vector2 getPosition() const;
	void setPosition(Vector2 position);
	int getSpeed() const;
	void setSpeed(int speed);

	void update();
	void handleInput();

	void resetAnimation();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void shoot();
	void draw() const;
	void die();
};

