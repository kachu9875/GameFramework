#include "Enemy.h"

/*void Enemy::load(int x, int y, int width, int height,
	std::string textureID)
{
	 
}

void Enemy::draw(SDL_Renderer* pRenderer)
{
	
}
void Enemy::update()
{
	GameObject::update();
	m_y += 1;
	//m_x += 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}*/
Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Enemy::handleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(10);
	}
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	//m_velocity = (*vec - m_position) / 100;
}

void Enemy::update()
{
	m_position.setX(m_position.getX() );
	m_position.setY(m_position.getY() );
	handleInput();
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();
}

void Enemy::clean()
{

}