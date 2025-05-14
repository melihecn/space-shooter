#include "Enemy.h"

Enemy::Enemy()
{

}

Enemy::Enemy(int type, Vector2 position, Texture2D idleTexture, int health, float speed)
{
	this->type = type;
	this->m_pos = position;
	this->idleTexture = idleTexture;
	this->health = health;
	this->speed = speed;
	this->isDead = false;
	this->currentTexture = idleTexture;
}

Enemy::~Enemy()
{
}

void Enemy::die()
{
	isDead = true;
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

void Enemy::checkCollision()
{
	BoundingBox a = { 200, 300 };
}

void Enemy::draw()
{
	DrawTextureEx(currentTexture, m_pos, 0, 1, WHITE);
}