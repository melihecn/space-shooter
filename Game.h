#pragma once
#include "raylib.h"
#include "raymath.h"
#include "Player.h"
#include "Ui.h"
#include "Enemy.h"
#include <vector>

#define WIDTH 1920
#define HEIGHT 1080

class Game
{
private:
	Player* player = nullptr;
	std::vector<Enemy*> enemies = { 0 };
	Camera2D camera;
	Texture2D background;
	Ui* ui;

public:
	Game();
	~Game();

	bool shouldClose;
	
	void update();
	void draw();
};

