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
	this->deathSprite;
	this->isMoving = false;
	
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

void Player::update()
{
	handleInput();

	for (auto it = lasers.begin(); it != lasers.end();)
	{
		it->update();

		if (it->isOffScreen())
		{
			it = lasers.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void Player::handleInput()
{
	if (IsKeyDown(KEY_D))
	{
		this->isMoving = true;
		moveRight();
	}
	if (IsKeyDown(KEY_A)) 
	{
		this->isMoving = true;
		moveLeft();
	}
	if (IsKeyDown(KEY_W)) 
	{
		this->isMoving = true;
		moveUp();
	}
	if (IsKeyDown(KEY_S)) 
	{
		this->isMoving = true;
		moveDown();
	}

	if (IsKeyDown(KEY_SPACE)) 
	{
		shoot();
	}

	if (!this->isMoving) {
		resetAnimation();
	}
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
	//currentSprite = idleSprite;
	position.y -= speed * GetFrameTime();
}

void Player::moveDown()
{
	//currentSprite = idleSprite;
	position.y += speed * GetFrameTime();
}

void Player::shoot()
{
	Vector2 direction = { 0, -1 }; // Shooting upwards
	lasers.push_back(Laser(position, direction, 800)); // Adjust speed as needed
}

void Player::draw() const
{
	DrawTextureEx(currentSprite, position, 0, 3, WHITE);

	for (const auto& laser : lasers)
	{
		laser.draw();
	}
}

void Player::die()
{
}
