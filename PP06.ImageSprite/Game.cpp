#include "Game.h"

bool Game::init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			SDL_Surface* pTempSurface = IMG_Load("Asset/animate-alpha.png");
			SDL_Surface* pTempSurface2 = IMG_Load("Asset/animate-alpha.png");
			SDL_Surface* pTempSurface3 = IMG_Load("Asset/New Piskel.png");
			m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
			m_pTexture2 = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface2);
			m_pTexture3 = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface3);
			SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
			SDL_QueryTexture(m_pTexture2, NULL, NULL, &m_sourceRectangle2.w, &m_sourceRectangle2.h);
			SDL_QueryTexture(m_pTexture3, NULL, NULL, &m_sourceRectangle3.w, &m_sourceRectangle3.h);
			SDL_SetRenderDrawColor(m_pRenderer, 100, 100, 100, 100);
			SDL_FreeSurface(pTempSurface);
			SDL_FreeSurface(pTempSurface2);
			SDL_FreeSurface(pTempSurface3);

			m_sourceRectangle.w = 128;
			m_sourceRectangle.h = 82;

			m_sourceRectangle2.w = 128;
			m_sourceRectangle2.h = 82;

			m_sourceRectangle3.w = 128;
			m_sourceRectangle3.h = 128;
		
			m_destinationRectangle.x = 150; m_sourceRectangle.x = 0;
			m_destinationRectangle.y = 100; m_sourceRectangle.y = 0;
			m_destinationRectangle.w = m_sourceRectangle.w;
			m_destinationRectangle.h = m_sourceRectangle.h;

			m_destinationRectangle2.x = 250; m_sourceRectangle2.x = 0;
			m_destinationRectangle2.y = 100; m_sourceRectangle2.y = 0;
			m_destinationRectangle2.w = m_sourceRectangle2.w;
			m_destinationRectangle2.h = m_sourceRectangle2.h;

			m_destinationRectangle3.x = 200; m_sourceRectangle3.x = 0;
			m_destinationRectangle3.y = 100; m_sourceRectangle3.y = 0;
			m_destinationRectangle3.w = m_sourceRectangle3.w;
			m_destinationRectangle3.h = m_sourceRectangle3.h;
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
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
	SDL_RenderCopy(m_pRenderer, m_pTexture3, &m_sourceRectangle3, &m_destinationRectangle3);
	SDL_RenderCopy(m_pRenderer, m_pTexture2, &m_sourceRectangle2, &m_destinationRectangle2);
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
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
	}
}

void Game::update()
{
	m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) & 6));
	m_sourceRectangle2.x = 128 * int(((SDL_GetTicks() / 50) & 6));
}