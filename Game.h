#pragma once
#include "SDL/include/SDL.h"
#include "Entity.h"

class Game {
private:
	SDL_Window* m_Window;
	int m_Width = 800;
	int m_Height = 600;
	bool isClosed = false;
	int targetFPS = 60;
	int LoopDelay = 1000 / targetFPS;
	SDL_Event m_Event;
	SDL_KeyboardEvent keyEvent;
public:
	SDL_Renderer* m_Renderer;
	Entity* m_Player;
	SDL_Texture* m_Texture;
	 Game(Entity* entity);
	~Game();

	void Render();
	void GameLoop();
	void HandleInput();

	void DrawEntity(Entity* entity);
};