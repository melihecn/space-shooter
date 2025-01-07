#include "game.h"

int main(void)
{
	InitWindow(WIDTH, HEIGHT, "Space Shooter");

	SetWindowState(FLAG_FULLSCREEN_MODE + FLAG_VSYNC_HINT + FLAG_WINDOW_RESIZABLE);
	
	SetTargetFPS(144);

	Game *game = new Game();

	while (!WindowShouldClose())
	{	
		game->update();
		game->draw();
	}
	
	// destructor closes window
	delete game;
	game = nullptr;

	return EXIT_SUCCESS;
}

