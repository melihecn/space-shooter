#include "game.h"

int main(void)
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Shooter");
	SetExitKey(KEY_NULL);
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(144);

	Game *game = new Game();

	game->shouldClose = false;

	bool closeRequest = false;

	while (!game->shouldClose)
	{	
		if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE))
		{
			closeRequest = true;
		}

		if (closeRequest == true)
		{
			DrawText("Quit Game?", SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 - 100, 30, BLACK);
			DrawText("(Y)es (N)o", SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 - 40, 30, BLACK);
			if (IsKeyPressed(KEY_N)) closeRequest = false;
			if (IsKeyPressed(KEY_Y)) game->shouldClose = true;
		}

		game->update();
		game->draw();
	}
	
	delete game;
	game = nullptr;

	return EXIT_SUCCESS;
}

