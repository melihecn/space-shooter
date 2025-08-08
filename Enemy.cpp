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

void Enemy::move()
{

}

void Enemy::update()
{
	if (this->health <= 0) {
		isDead = true;
		playedAnimation = false;
	}
	this->gotHit = false;
}

void Enemy::playAnimation(const char* animationName)
{
	if (animationName == "death") {
	
		int frameCounter = 7;
		int currentFrame = 0;
		Rectangle rect = { this->position.x, this->position.y, deathSpriteSheet.width / (frameCounter - 1), deathSpriteSheet.height };
		

		rect.x = float(currentFrame) * deathSpriteSheet.width / (frameCounter - 1);
		DrawTextureRec(this->deathSpriteSheet, rect, this->position, WHITE);
		currentFrame++;
		
	}
	playedAnimation = true;
}

void Enemy::die()
{
	isDead = true;
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

void Enemy::draw()
{
	Color color = WHITE;
	if (gotHit) {
		color = RED;
	}

	DrawTextureEx(currentTexture, position, 0, 2, color);

	if (isDead) {
		playAnimation("death");
		playedAnimation = true;
	}
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

