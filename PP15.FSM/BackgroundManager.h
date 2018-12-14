#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"

class BackgroundManager : public SDLGameObject
{
private:
	void handleInput();
public:
	BackgroundManager(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};
