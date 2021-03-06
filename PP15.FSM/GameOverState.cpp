#include "GameOverState.h"
const std::string GameOverState::s_gameOverID = "GAMEOVER";
GameOverState* GameOverState::s_pInstance = NULL;

void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(MenuState::Instance());
}

void GameOverState::s_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
}

bool GameOverState::onEnter()
{
	if (!TheTextureManager::Instance()->load("Asset/gameover.png",
		"gameovertext", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Asset/main.png",
		"mainbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Asset/restart.png",
		"restartbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* gameOverText = new AnimatedGraphic(
		new  LoaderParams(550, 200, 190, 30, "gameovertext"), 2);
	GameObject* button1 = new MenuButton(
		new LoaderParams(540, 300, 200, 80, "mainbutton"),
		s_gameOverToMain);
	GameObject* button2 = new MenuButton(
		new LoaderParams(540, 400, 200, 80, "restartbutton"),
		s_restartPlay);
	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering GameOverState\n";
	std::cout << "Score : " << ThePlayState::Instance()->getrecscore() << "\n";
	return true;
}

bool GameOverState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	std::cout << "exiting GameOverState\n";
	return true;
}

void GameOverState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void GameOverState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}