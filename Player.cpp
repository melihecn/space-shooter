#include "Player.h"

Player::Player()
{

}

Player::Player(Vector2 position)
{
	this->position = position;
	this->health = 100;
	this->shootPower = 20;
	this->idleSprite = LoadTexture(".\\assets\\ship\\PNG\\sprites\\ship01\\idle.png");
	this->moveLeftT = LoadTexture(".\\assets\\ship\\PNG\\sprites\\ship01\\left.png");
	this->moveRightT = LoadTexture(".\\assets\\ship\\PNG\\sprites\\ship01\\right.png");
	this->currentSprite = idleSprite;
	this->speed = 500;
}

Player::~Player()
{
	UnloadTexture(idleSprite);
	UnloadTexture(moveLeftT);
	UnloadTexture(moveRightT);
}

Vector2 Player::getPosition() const
{
	return this->position;
}

void Player::setPosition(Vector2 position)
{
	this->position = position;
}

int Player::getSpeed() const
{
	return this->speed;
}

void Player::setSpeed(int speed)
{
	this->speed = speed;
}

void Player::resetAnimation()
{
	currentSprite = idleSprite;
}

void Player::moveLeft()
{
	currentSprite = moveLeftT;
	position.x -= speed * GetFrameTime();
}

void Player::moveRight()
{
	currentSprite = moveRightT;
	position.x += speed * GetFrameTime();
}

void Player::moveUp()
{
	currentSprite = idleSprite;
	position.y -= speed * GetFrameTime();
}

void Player::moveDown()
{
	currentSprite = idleSprite;
	position.y += speed * GetFrameTime();
}

void Player::shoot()
{

}

void Player::draw() const
{
	DrawTextureEx(currentSprite, position, 0, 3, WHITE);
}

void Player::die()
{
}
