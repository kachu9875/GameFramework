#pragma once
#include "GameState.h"
class SDLGameObject;

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }
	static PlayState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PlayState();
			return s_pInstance;
		}
		return s_pInstance;
	}
	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
	void call_enemy(int x, int y, int width, int height);
	int getrecscore();
	
	//int totscore;
private:
	static const std::string s_playID;
	static PlayState* s_pInstance;
	std::vector<GameObject*> m_gameObjects;
	PlayState() {}
	void recscore();
	int score;
	int adt = 0;
};
typedef PlayState ThePlayState;
