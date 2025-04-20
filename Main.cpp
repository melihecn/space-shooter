#include "game.h"

int main(void)
{
	InitWindow(WIDTH, HEIGHT, "Space Shooter");
	SetExitKey(KEY_NULL);
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(144);

	Game *game = new Game();
	
	bool closeRequest = false;
	bool shouldExit = false;

	while (!shouldExit)
	{	
		if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE))
		{
			closeRequest = true;
		}

		if (closeRequest == true)
		{
			DrawText("Quit Game?", WIDTH / 2 - 200, HEIGHT / 2 - 100, 30, BLACK);
			DrawText("(Y)es (N)o", WIDTH / 2 - 200, HEIGHT / 2 - 40, 30, BLACK);
			if (IsKeyPressed(KEY_N)) closeRequest = false;
			if (IsKeyPressed(KEY_Y)) shouldExit = true;
		}

		game->update();
		game->draw();
	}
	
	// destructor closes window
	delete game;
	game = nullptr;

	return EXIT_SUCCESS;
}

