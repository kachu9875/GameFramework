#pragma once
#include "MenuState.h"

class GameStateMachine
{
public:
	void changeState(GameState* pState);
	void popState();
	void update();
	void render();
private:
	GameState* m_currentState;
	GameState* m_prevState;
};
