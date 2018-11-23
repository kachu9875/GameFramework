#include "Game.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		m_pGameStateMachine = new GameStateMachine();
		m_pGameStateMachine->changeState(MenuState::Instance());

		if (m_pWindow != 0)
		{	
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (!TheTextureManager::Instance()->load("Asset/animate-alpha.png",
				"animate", m_pRenderer))
			{
				return false;
			}

			m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
			m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
			
			SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
		}
	}
	else
	{
		return false;
	}
	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	/*for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}*/
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	TheInputHandler::Instance()->clean();
	SDL_Quit();
}

void Game::handleEvents()
{
	/*SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}*/
	TheInputHandler::Instance()->update();
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(PlayState::Instance());
	}
}

void Game::quit()
{
	m_bRunning = false;
}
void Game::update()
{
	/*for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}*/
	m_pGameStateMachine->update();
}