#pragma once
#include "raylib.h"

class Enemy
{
public:

	Enemy();
	Enemy(int type, Vector2 position, Texture2D idleTexture, int health, float speed);
	~Enemy();

	void die();
	void move();
	void draw();
	void update();

	void checkCollision();

	bool isDead;

private:

	Texture2D idleTexture;
	Texture2D currentTexture;
	Vector2 m_pos;
	int health;
	int type;
	float speed;
};

