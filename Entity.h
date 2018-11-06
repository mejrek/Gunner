#pragma once
#include "SDL/include/SDL.h"
#include <iostream>

class Entity
{
private:
	int posX = 400;
	int	posY = 320;
	int sx = 0;
	int sy = 0;
	int m_Width, m_Height;
	int speed = 1;
public:
	SDL_Rect m_Rect;
	SDL_Surface* m_Surface;
	SDL_Texture* m_Texture;
	Entity(const char* filepath, int width, int height);
	~Entity();

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	void Update();
};

