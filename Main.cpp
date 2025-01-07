
#include "game.h"

int main(void)
{
	Game *game = new Game();

	InitWindow(800, 600, "Space Shooter");

	game->start();

	while (!WindowShouldClose())
	{	
		game->update();
		game->draw();
	}
	

	// destructor closes window
	delete game;
	game = nullptr;

}

