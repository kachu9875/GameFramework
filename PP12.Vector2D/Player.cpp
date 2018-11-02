#include "Player.h"

/*void Player::load(int x, int y, int width, int height,
	std::string textureID)
{

}

void Player::draw(SDL_Renderer* pRenderer)
{
	
}

void Player::update()
{
	m_x -= 1;
}
*/
Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}
void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Player::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	m_acceleration.setX(1);
	SDLGameObject::update();
}
void Player::clean()
{

}
