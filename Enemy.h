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
	void playAnimation(const char* animationName);
	void initEnemies();

	Vector2 getPosition() const;
	void setPosition(Vector2 position);

	Rectangle getBBox() const;
	void setBBox(Rectangle bbox);

	int getPoint();
	bool isDead;
	bool playedAnimation;

private:
	Texture2D idleTexture;
	Texture2D currentTexture;
	Texture2D deathSpriteSheet;
	Vector2 position;
	Rectangle bbox;

	int point;
	int health;
	int type;
	float speed;
	float drawScale;
	bool gotHit;
};

