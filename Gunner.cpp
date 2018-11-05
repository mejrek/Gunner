#include "Game.h"
#include "Entity.h"

bool isClosed = false;

int main()
{
	Game game;
	Entity entity("../Res/Textures/ship.png", 64, 64, game);
	game.GameLoop();
	
	return 0;
}