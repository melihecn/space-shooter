#include "game.h"
#include <iostream>


Game::Game()
{
	std::cout << "game init\n";
	player = new Player(Vector2{ WIDTH / 2.f, HEIGHT / 2.f });
	camera = { 0 };
	camera.target = Vector2{player->getPosition().x + 20.f, player->getPosition().y + 20.f};
	camera.zoom = 1.0f;
	camera.rotation = 0.0f;
	camera.offset = Vector2{ WIDTH / 2.0f, HEIGHT / 2.0f };
	background = LoadTexture("./assets/environment/PNG/bg1080p.png");
}

Game::~Game()
{
	delete player;

	UnloadTexture(background);
	
	CloseWindow();
}

void Game::start()
{
	// init game stuff
}

void Game::update()
{

	if (IsKeyDown(KEY_D)) {
		player->moveRight();
	}
	if (IsKeyDown(KEY_A))
	{
		player->moveLeft();
	}
	if (IsKeyDown(KEY_W))
	{
		player->moveUp();
	}
	if (IsKeyDown(KEY_S))
	{
		player->moveDown();
	}
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) 
	{
		player->shoot();
	}
	if (IsKeyDown(KEY_LEFT_SHIFT))
	{
		
	}
	else {
		player->resetAnimation();
	}
	
	//camera.zoom += float(GetMouseWheelMove() * 0.5f);
}

void Game::draw()
{
	// draw game stuff
	BeginDrawing();

	ClearBackground(LIGHTGRAY);
	BeginMode2D(camera);
		
		DrawTexture(background, WIDTH / 3, 0, WHITE);

		player->draw();
		
		
	EndMode2D();

	EndDrawing();
}
