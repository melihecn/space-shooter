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
}

Enemy::~Enemy()
{
	UnloadTexture(currentTexture);
}

void Enemy::move()
{

}

void Enemy::update()
{
	if (this->health <= 0) {
		die();
	}
}

void Enemy::die()
{
	isDead = true;
}

void Enemy::getHit()
{
	this->health -= 10;
	std::cout << this->health << std::endl;
}

Vector2 Enemy::getPosition() const
{
	return this->position;
}

void Enemy::setPosition(Vector2 position)
{
	this->position = position;
}

void Enemy::draw()
{
	DrawTextureEx(currentTexture, position, 0, 2, WHITE);
	DrawRectangleLines(bbox.x, bbox.y, bbox.width, bbox.height, RED);
}

Rectangle Enemy::getBBox() const
{
	return this->bbox;
}

void Enemy::setBBox(Rectangle bbox)
{
	this->bbox = bbox;
}
