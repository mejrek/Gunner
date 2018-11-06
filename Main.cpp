#include "Entity.h"
#include "Game.h"

int main()
{
	Entity player("../Res/Textures/ship.png", 64, 64);
	Game game(&player);
	game.GameLoop();
}