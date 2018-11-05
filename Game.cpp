#include "Game.h"

Game::Game()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		SDL_Quit();
	}

	m_Window = SDL_CreateWindow("Gunner", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_Width, m_Height, SDL_WindowFlags::SDL_WINDOW_SHOWN);
	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);

}

Game::~Game()
{
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}

void Game::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_Renderer);
	m_Player.RenderPlayer();
	//m_Entity.RenderEntity(this);
	SDL_RenderPresent(m_Renderer);
}

void Game::GameLoop()
{
	while (!isClosed)
	{
		Render();
		HandleInput();
	}
}

void Game::HandleInput()
{
	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_EventType::SDL_QUIT)
		{
			isClosed = true;
		}
		else if (event.type == SDL_EventType::SDL_KEYDOWN && event.key.keysym.scancode == SDL_Scancode::SDL_SCANCODE_ESCAPE)
		{
			isClosed = true;
		}
		if (event.type == SDL_EventType::SDL_KEYDOWN && event.key.keysym.scancode == SDL_Scancode::SDL_SCANCODE_UP)
		{

		}
	}
}