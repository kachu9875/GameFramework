#include "MenuState.h"
const std::string MenuState::s_menuID = "MENU";
MenuState *MenuState::s_pInstance = NULL;

void MenuState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	m_gameback->draw();
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	if (!TheTextureManager::Instance()->load("Asset/button.png", "playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Asset/exit.png", "exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Asset/HOS.jpg", "background", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	m_gameback = new SDLGameObject(new LoaderParams(-35, -100, 1366, 768, "background"));
	GameObject* button1 = new MenuButton(new LoaderParams(440, 200, 400, 100, "playbutton"), s_menuToPlay);
	GameObject* button2 = new MenuButton(new LoaderParams(440, 400, 400, 100, "exitbutton"), s_exitFromMenu);

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()
		->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("exitbutton");
	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}

void MenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
}