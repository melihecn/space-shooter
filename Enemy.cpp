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
}

Enemy::~Enemy()
{
}

void Enemy::die()
{

}

void Enemy::move()
{

}
