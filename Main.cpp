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
		if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) closeRequest = true;

		if (closeRequest == true)
		{
			if (IsKeyPressed(KEY_ENTER)) shouldExit = true;
		}
		game->update();
		game->draw();
	}
	
	// destructor closes window
	delete game;
	game = nullptr;

	return EXIT_SUCCESS;
}

