#pragma once

#include "Engine/GameEngine.h"

class GameOverScene : public Scene
{
public:
	//creates scewne
	GameOverScene(int score);
private:

};

typedef std::shared_ptr<GameOverScene> GameOverScenePtr;