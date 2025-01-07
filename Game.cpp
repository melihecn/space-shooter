#include "game.h"

#include <iostream>
#include <vector>

Game::Game()
{
	std::cout << "game init\n";
}

Game::~Game()
{
	CloseWindow();
}

void Game::start()
{
	// init game stuff
	LoadTexture("./assets/environment/PNG/bgnew.png");
}

void Game::update()
{
	// update game stuff
}

void Game::draw()
{
	// draw game stuff
	BeginDrawing();
	ClearBackground(LIGHTGRAY);


	EndDrawing();
}
