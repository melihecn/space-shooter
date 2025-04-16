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
    // Hareket vektörü
    Vector2 movement = { 0.0f, 0.0f };

    // Hareket yönlerini kontrol et
    if (left)
    {
        movement.x -= 1.0f; // Sola hareket
        currentSprite = moveLeftT;
    }
    if (right)
    {
        movement.x += 1.0f; // Saða hareket
        currentSprite = moveRightT;
    }
    if (up)
    {
        movement.y -= 1.0f; // Yukarý hareket
    }
    if (down)
    {
        movement.y += 1.0f; // Aþaðý hareket
    }

    // Hareket vektörünü normalize et
    if (movement.x != 0.0f || movement.y != 0.0f)
    {
        float length = sqrtf(movement.x * movement.x + movement.y * movement.y);
        movement.x /= length;
        movement.y /= length;
    }

    // Hareketi uygula
    position.x += movement.x * speed * GetFrameTime();
    position.y += movement.y * speed * GetFrameTime();
}

void Player::shoot()
{
	Vector2 direction = { 0, -1 }; // Shooting upwards
	lasers.push_back(Laser(position, direction, 800)); // Adjust speed as needed
}

void Player::draw() const
{
	DrawTextureEx(currentSprite, position, 0, 3, WHITE);
}

void Player::die()
{
}
