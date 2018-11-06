#include "Game.h"

Game::Game(Entity* player)
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		SDL_Quit();
	}

	m_Player = player;
	m_Window = SDL_CreateWindow("Gunner", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_Width, m_Height, SDL_WindowFlags::SDL_WINDOW_SHOWN);
	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
}

Game::~Game()
{
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}

void Game::Render()
{
	SDL_RenderClear(m_Renderer);
	DrawEntity(m_Player);
	SDL_RenderPresent(m_Renderer);
}

void Game::GameLoop()
{
	while (!isClosed)
	{
		HandleInput();
		//m_Player->Update();
		Render();
		//SDL_Delay(LoopDelay);
	}
}

void Game::HandleInput()
{
	
	while (SDL_PollEvent(&m_Event) != 0)
	{
		if (m_Event.type == SDL_EventType::SDL_QUIT)
		{
			isClosed = true;
		}
		else if (m_Event.type == SDL_EventType::SDL_KEYDOWN && m_Event.key.keysym.scancode == SDL_Scancode::SDL_SCANCODE_ESCAPE)
		{
			isClosed = true;
		}

		if (m_Event.type == SDL_EventType::SDL_KEYDOWN && m_Event.key.keysym.scancode == SDL_Scancode::SDL_SCANCODE_UP)
		{
			m_Player->MoveUp();
		}

		if (m_Event.type == SDL_EventType::SDL_KEYDOWN && m_Event.key.keysym.scancode == SDL_Scancode::SDL_SCANCODE_DOWN)
		{
			m_Player->MoveDown();
		}

		if (m_Event.type == SDL_EventType::SDL_KEYDOWN && m_Event.key.keysym.scancode == SDL_Scancode::SDL_SCANCODE_LEFT)
		{
			m_Player->MoveLeft();
		}

		if (m_Event.type == SDL_EventType::SDL_KEYDOWN && m_Event.key.keysym.scancode == SDL_Scancode::SDL_SCANCODE_RIGHT)
		{
			m_Player->MoveRight();
		}
	}
}

void Game::DrawEntity(Entity* entity)
{
	m_Texture = SDL_CreateTextureFromSurface(m_Renderer, entity->m_Surface);
	//SDL_FreeSurface(entity->m_Surface);
	SDL_RenderCopy(m_Renderer, m_Texture, NULL, &entity->m_Rect);
}