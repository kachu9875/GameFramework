#include "PlayState.h"
#include "Game.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "Enemy.h"
#include "BackgroundManager.h"
#include "GameOverState.h"
#include "SDLGameObject.h"
#include <ctime>
const std::string PlayState::s_playID = "PLAY";
PlayState *PlayState::s_pInstance = NULL;


void PlayState::update()
{
	
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(PauseState::Instance());
	}
	else 
	{
		for (int i = 0; i < m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->update();

			if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[i])) && (i != 0))
			{
				TheGame::Instance()->getStateMachine()->pushState(GameOverState::Instance());
			}
			else if (checkOut(dynamic_cast<SDLGameObject*>(m_gameObjects[i])) && (i != 0))
			{
				m_gameObjects.erase(m_gameObjects.begin() + i);
				i--;
			}
		}
		adt++;
		if (adt % 30 == 0)
		{			
				call_enemy(-100, rand() % 670, 128, 55);
		}
		recscore();
		for (int j = 0; j < m_pbackground.size(); j++)
		{
			m_pbackground[j]->update();
		}
	}
	
}

void PlayState::render()
{
	// nothing for now
	for (int i = 0; i < m_pbackground.size(); i++)
	{
		m_pbackground[i]->draw();
	}
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	srand(time(NULL));
	if (!TheTextureManager::Instance()->load("Asset/helicopter.png", "helicopter", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Asset/helicopter2.png", "helicopter2", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Asset/Playbackground.png", "pbackground", TheGame::Instance()->getRenderer())) {
		return false;
	}
	GameObject* player = new Player(new LoaderParams(500, 100, 128, 55, "helicopter"));

	load_pBackground(1280, 0, 1280, 720);
	load_pBackground(0, 0, 1280, 720);
	m_gameObjects.push_back(player);
	call_enemy(-100, 360, 128, 55);
	std::cout << "entering PlayState\n";
	score = 0;
	return true;
}

void PlayState::call_enemy(int x, int y, int width, int height)
{
	GameObject* enemy = new Enemy(new LoaderParams(x, y, width, height, "helicopter2"));
	m_gameObjects.push_back(enemy);
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	std::cout << "exiting PlayState\n";
	return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;
	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();
	//Calculate the sides of rect B
	leftB = p2->getPosition().getX()+2;
	rightB = p2->getPosition().getX() + p2->getWidth()-2;
	topB = p2->getPosition().getY()+2;
	bottomB = p2->getPosition().getY() + p2->getHeight()-2;
	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}

bool PlayState::checkOut(SDLGameObject* p1)
{
	int x = p1->getPosition().getX();
	if (x > 1300)
	{
		return true;
	}
	return false;
}

void PlayState::load_pBackground(int x, int y, int w, int h)
{
	GameObject* pbackground = new BackgroundManager(new LoaderParams(x, y, w, h, "pbackground"));
	m_pbackground.push_back(pbackground);
}

void PlayState::recscore()
{
	score++;
	if (score % 500 == 0 && score != 0)
	{
		score += 1000;
	}
}

int PlayState::getrecscore()
{
	return score;
}