#include "Enemy.h"
#include <iostream>

Enemy::Enemy()
{

}

Enemy::Enemy(int type, Vector2 position, Texture2D idleTexture, float drawScale, int health, float speed)
{
	this->type = type;
	this->position = position;
	this->idleTexture = idleTexture;
	this->health = health;
	this->speed = speed;
	this->isDead = false;
	this->currentTexture = idleTexture;
	this->drawScale = drawScale;
	this->bbox = { position.x, position.y, idleTexture.width * drawScale, idleTexture.height * drawScale};
	this->point = 10;
	this->gotHit = false;
	this->deathSpriteSheet = LoadTexture("./assets/enemy/PNG/spritesheets/enemy-explosion.png");
	this->playedAnimation = false;
}

Enemy::~Enemy()
{
	UnloadTexture(currentTexture);
	UnloadTexture(deathSpriteSheet);
}

void Enemy::initEnemies()
{
}

void Enemy::move()
{

}

void Enemy::update()
{
	if (this->health <= 0) {
		isDead = true;
	}
	this->gotHit = false;
}

void Enemy::playAnimation(const char* animationName)
{
 // implemente edilecek ilerde
}



void Enemy::die()
{
	// animasyon burada olabilir
}

void Enemy::getHit()
{
	this->health -= 10;
	this->gotHit = true;
}

Vector2 Enemy::getPosition() const
{
	return this->position;
}

void Enemy::setPosition(Vector2 position)
{	
	this->position = position;
}

void Enemy::draw() const
{
	Color color = WHITE;
	if (gotHit) {
		color = RED;
	}

	DrawTextureEx(currentTexture, position, 0, 2, color);
}

Rectangle Enemy::getBBox() const
{
	return this->bbox;
}

void Enemy::setBBox(Rectangle bbox)
{
	this->bbox = bbox;
}

int Enemy::getPoint()
{
	return this->point;
}

