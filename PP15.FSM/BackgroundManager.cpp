#include "BackgroundManager.h"

BackgroundManager::BackgroundManager(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void BackgroundManager::draw()
{
	SDLGameObject::draw();
}

void BackgroundManager::handleInput()
{
	
}

void BackgroundManager::update()
{
	m_velocity.setX(3);
	if (m_position.getX() >= 1280)
	{
		m_position.setX(-1280);
	}
	SDLGameObject::update();
}

void BackgroundManager::clean()
{

}
