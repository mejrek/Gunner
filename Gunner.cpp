/*#include "SDL/include/SDL.h"
#include "SDL/include/SDL_image.h"
#include <iostream>

bool isClosed = false;
SDL_Event event;


void HandleInput()
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

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		SDL_Quit();
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		SDL_Quit();
	}

	SDL_Window* window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);

	SDL_Rect rect;
	rect.x = 400;
	rect.y = 300;
	rect.w = 40;
	rect.h = 40;

	SDL_Surface* surface;
	surface = IMG_Load("../Res/Textures/ship.png");
	if (!surface)
	{
		std::cout << "SDL_LoadBMP() failed: Failed to load the image '" << "'.\nSDL_LoadBMP() : " << SDL_GetError() << std::endl;
		std::cin.get();
		return 0;
	}
	//SDL_BlitSurface(surface, rect, )
	SDL_Texture* texture;
	texture = SDL_CreateTextureFromSurface(renderer, surface);


	while (!isClosed)
	{
		HandleInput();
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, &rect);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
*/