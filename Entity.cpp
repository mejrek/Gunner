#include "Entity.h"
#include "SDL/include/SDL_image.h"


Entity::Entity(const char* filepath, int width, int height)
{
	m_Rect.w = width;
	m_Rect.h = height;
	m_Rect.x = posX;
	m_Rect.y = posY;

	m_Surface = IMG_Load(filepath);
	if (!m_Surface)
	{
		std::cout << "SDL_LoadBMP() failed: Failed to load the image '" << "'.\nSDL_LoadBMP() : " << SDL_GetError() << std::endl;
	}
}

Entity::~Entity()
{
	SDL_FreeSurface(m_Surface);
}

void Entity::MoveUp()
{
	m_Rect.y -= speed;
}

void Entity::MoveDown()
{
	m_Rect.y += speed;
}

void Entity::MoveLeft()
{
	m_Rect.x -= speed;
}

void Entity::MoveRight()
{
	m_Rect.x += speed;
}

void Entity::Update()
{
//	m_Rect.x = posX + sx;
//	m_Rect.y = posY + sy;
}