#pragma once
#include "TextureManager.h"

class Game
{
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
private:
	int m_currentFrame;
	TextureManager m_textureManager;
	SDL_Texture * m_pTexture;
	//SDL_Texture * m_pTexture2;
	//SDL_Texture * m_pTexture3;
	//SDL_Rect m_sourceRectangle;
	//SDL_Rect m_destinationRectangle;
	//SDL_Rect m_sourceRectangle2;
	//SDL_Rect m_destinationRectangle2;
	//SDL_Rect m_sourceRectangle3;
	//SDL_Rect m_destinationRectangle3;
	SDL_Window * m_pWindow = 0;
	SDL_Renderer*m_pRenderer = 0;
	//SDL_Renderer*m_pRenderer2 = 0;
	//SDL_Renderer*m_pRenderer3 = 0;
	bool m_bRunning = true;
};