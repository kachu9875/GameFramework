#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"

class Enemy : public SDLGameObject
{
private:
	void handleInput();
public:
	/*Enemy() {}
	~Enemy() {}
	Enemy(const LoaderParams* pPap) { }
	void load(int x, int y, int width, int height,
		std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean() { }*/
	Enemy(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};