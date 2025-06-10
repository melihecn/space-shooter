#pragma once
#include "Common.h"
#include "Player.h"
#include "Ui.h"
#include "Enemy.h"


class Game
{
private:
	Player* player = nullptr;
	std::vector<Enemy*> enemies;
	Camera2D camera;
	Texture2D background;
	Ui* ui = nullptr;

public:
	Game();
	~Game();
	
	void checkCollisions(std::vector<Laser> &lasers, Enemy* enemy);
	void update();
	void draw();
};

