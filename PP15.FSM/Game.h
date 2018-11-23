#pragma once
#include "TextureManager.h"
#include "SDLGameObject.h"
#include "GameStateMachine.h"
#include "PlayState.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
public:
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	void quit();
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
private:
	Game() {}
	static Game* s_pInstance;
	bool m_bRunning = true;
	int m_currentFrame;
	SDL_Renderer*m_pRenderer = 0;
	SDL_Texture * m_pTexture;
	SDL_Window * m_pWindow = 0;
	std::vector<GameObject*> m_gameObjects;
	GameStateMachine* m_pGameStateMachine;
	/*GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;*/
};
typedef Game TheGame;