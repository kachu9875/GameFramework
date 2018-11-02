#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
	/*Player() {}
	~Player() {}
	Player(const LoaderParams* pPap) { }
	void load(int x, int y, int width, int height,
		std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean() { }*/
	Player(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};

