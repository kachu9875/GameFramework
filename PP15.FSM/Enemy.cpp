#include "Enemy.h"
#include <ctime>

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	/*m_velocity.setY(2);
	m_velocity.setX(0.001);*/
	srand(time(NULL));
	Xspeed = rand() % 10 + 4;
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
	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));
	/*if (m_position.getY() < 0) {
		m_velocity.setY(2);
	}
	else if (m_position.getY() > 400) {
		m_velocity.setY(-2);
	}*/
	if (m_position.getX() < 0)
	{
		m_velocity.setX(Xspeed);
	}
	SDLGameObject::update();
}

void Enemy::clean()
{

}