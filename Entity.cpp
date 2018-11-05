#include "Entity.h"
#include "Game.h"

Game* m_Game;

Entity::Entity(const char* filepath, int width, int height, Game* game)
	: m_Width(width), m_Height(height)
{
	m_Surface = SDL_LoadBMP(filepath);
	m_Texture = SDL_CreateTextureFromSurface(game->m_Renderer, m_Surface);
	SDL_FreeSurface(m_Surface);
}

Entity::~Entity()
{

}

void Entity::RenderEntity(Game* game)
{
	SDL_Rect tmp_Rect;
	tmp_Rect.x = m_Width;
	tmp_Rect.y = m_Height;
	SDL_RenderCopyEx(game->m_Renderer, m_Texture, NULL, &tmp_Rect, 90, NULL, SDL_RendererFlip::SDL_FLIP_NONE);
}

void Player::RenderPlayer(Game* game)
{
	SDL_Rect tmp_Rect;
	tmp_Rect.x = m_Width;
	tmp_Rect.y = m_Height;
	SDL_RenderCopyEx(game->m_Renderer, m_Texture, NULL, &tmp_Rect, 90, NULL, SDL_RendererFlip::SDL_FLIP_NONE);
}