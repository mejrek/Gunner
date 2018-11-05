#pragma once
//#include "Game.h"
#include "SDL/include/SDL.h"
#include <string>

class Entity {
private:
	int posX, posY;
	int m_Width, m_Height;
public:
	SDL_Texture* m_Texture;
	SDL_Surface* m_Surface;
	Entity(const char* filepath, int width, int height, Game* game);
	~Entity();

	void RenderEntity(Game* game);
};

class Player: Entity{
private:
	int m_Width, m_Height;
public:

	void RenderPlayer(Game* game);
};