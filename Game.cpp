#include "game.h"
#include <iostream>

Game::Game()
{	
	ui = new Ui();
	ui->Init();

	player = new Player(Vector2{ SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f });
	camera = { 0 };
	camera.target = Vector2{player->getPosition().x + 20.f, player->getPosition().y + 20.f};
	camera.zoom = 1.0f;
	camera.rotation = 0.0f;
	camera.offset = Vector2{ SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f };
	background = LoadTexture("./assets/environment/PNG/bg1080p.png");
	Laser::initialize();

	enemies.push_back(new Enemy(0, { SCREEN_WIDTH / 2.f, 100 }, LoadTexture("./assets/enemy/PNG/sprites/enemy-01/idle.png"), 2, 500, 10));
}

Game::~Game()
{
	Laser::unload();
	delete player;

	UnloadTexture(background);

	ui->Unload();
	delete ui;

	CloseWindow();
}

void Game::checkCollisions(std::vector<Laser>& lasers, Enemy* enemy)
{
	for (auto it = lasers.begin(); it != lasers.end(); )
	{
		if (CheckCollisionRecs(it->getBBox(), enemy->getBBox()))
		{
			enemy->getHit();
			it = lasers.erase(it); 
			break;
		}
		else
		{
			++it;
		}
	}
}

void Game::update()
{
	ui->Update();

	player->update();
	
	for (auto enemy : enemies) 
	{
		enemy->update();

		checkCollisions(player->getLasersRef(), enemy);

		if (enemy->isDead) 
		{
			enemies.pop_back();
		}
	}

}

void Game::draw()
{
	// draw game
	BeginDrawing();
	ClearBackground(LIGHTGRAY);

	ui->Draw();

	if (ui->currentScreen == Ui::GAME) {

		BeginMode2D(camera);

		DrawTexture(background, SCREEN_WIDTH / 3, 0, WHITE);

		player->draw();

		for (const auto& laser : player->getLasers())
		{
			laser.draw();
		}

		for (auto enemy : enemies) {
			enemy->draw();
		}

		EndMode2D();
	}
		
	EndDrawing();
}
