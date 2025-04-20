#pragma once
#include "raylib.h"
#include "raymath.h"
#include "Player.h"
#include "Ui.h"
#include "Enemy.h"
#include <vector>

class Game
{
private:
	Player* player = nullptr;
	std::vector<Enemy*> enemies = { 0 };
	Camera2D camera;
	Texture2D background;
	Ui* ui = nullptr;

public:
	Game();
	~Game();
	
	void update();
	void draw();
};

