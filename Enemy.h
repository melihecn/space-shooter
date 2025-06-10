#pragma once
#include "Common.h"

class Enemy
{
public:
	Enemy();
	Enemy(int type, Vector2 position, Texture2D idleTexture, float drawScale, int health, float speed);
	~Enemy();

	void die();
	void getHit();
	void move();
	void draw();
	void update();

	Vector2 getPosition() const;
	void setPosition(Vector2 position);

	Rectangle getBBox() const;
	void setBBox(Rectangle bbox);

	bool isDead;

private:
	Texture2D idleTexture;
	Texture2D currentTexture;
	Vector2 position;
	Rectangle bbox;
	int health;
	int type;
	float speed;
	float drawScale;
};

