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
	this->lasers = {};
	
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

std::vector<Laser> Player::getLasers() const
{
	return lasers;
}

std::vector<Laser>& Player::getLasersRef()
{
	return lasers;
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
	this->isMoving = false;

	bool left = IsKeyDown(KEY_A);
	bool right = IsKeyDown(KEY_D);
	bool up = IsKeyDown(KEY_W);
	bool down = IsKeyDown(KEY_S);

	if (left || right || up || down)
	{
		this->isMoving = true;
		move(left, right, up, down);
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

void Player::move(bool left, bool right, bool up, bool down)
{
    
    Vector2 movement = { 0.0f, 0.0f };

    if (left)
    {
		if (position.x <= 0)
		{
			movement.x += 1.0f;
		}
		else {
			movement.x -= 1.0f;
		}

        currentSprite = moveLeftT;
    }
    if (right)
    {
		if (position.x >= SCREEN_WIDTH - 100)
		{
			movement.x -= 1.0f;
		}
		else 
		{
			movement.x += 1.0f;
		}

        currentSprite = moveRightT;
    }
    if (up)
    {
		if (position.y <= 0)
		{
			movement.y += 1.0f;
		}
		else
		{
			movement.y -= 1.0f;
		}
    }
    if (down)
    {
		if (position.y >= SCREEN_HEIGHT - 100)
		{
			movement.y -= 1.0f;
		}
		else 
		{
			movement.y += 1.0f;
		}

    }

    if (movement.x != 0.0f || movement.y != 0.0f)
    {
        float length = sqrtf(movement.x * movement.x + movement.y * movement.y);
        movement.x /= length;
        movement.y /= length;
    }

    position.x += movement.x * speed * GetFrameTime();
    position.y += movement.y * speed * GetFrameTime();

	std::cout << position.x << " " << position.y << "\n";
}

void Player::shoot()
{
	float currentTime = GetTime();
	if (currentTime - lastShotTime >= shootCooldown)
	{
		Vector2 direction = { 0, -1 };
		lasers.push_back(Laser(position, direction, 800));
		lastShotTime = currentTime;
	}
}
void Player::draw() const
{
	DrawTextureEx(currentSprite, position, 0, 3, WHITE);
}

void Player::die()
{
}
