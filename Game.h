#pragma once
#include "SDL/include/SDL.h"
#include "Entity.h"

class Game {
private:
	SDL_Window* m_Window;
	int m_Width = 800;
	int m_Height = 600;
	bool isClosed = false;
	SDL_Event event;
	SDL_KeyboardEvent keyEvent;
public:
	SDL_Renderer* m_Renderer;
	Player m_Player;
	 Game();
	~Game();

	void Render();
	void GameLoop();
	void HandleInput();
};