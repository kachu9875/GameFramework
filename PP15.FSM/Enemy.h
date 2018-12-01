#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"

class Enemy : public SDLGameObject
{
private:
	void handleInput();
	int m_numFrames = 5;
public:
	Enemy(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};