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
	float lastShotTime = 0.0f;
	float shootCooldown = 0.5f;
	std::vector<Laser> lasers;

public:
	Player();
	Player(Vector2 position);

	~Player();
	
	Vector2 getPosition() const;
	void setPosition(Vector2 position);
	int getSpeed() const;
	void setSpeed(int speed);
	std::vector<Laser> getLasers() const;

	void update();
	void handleInput();

	void resetAnimation();

	void move(bool left, bool right, bool up, bool down);

	void shoot();
	void draw() const;
	void die();
};

