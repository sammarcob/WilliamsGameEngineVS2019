#pragma once

#include "Engine/GameEngine.h"

class GameScene : public Scene {
 public:
  // Creates our Scene.
  GameScene();

  //get current score
  int getScore();

  //increaqase scoere
  void increaseScore();

private:
	int score_ = 0;
};

typedef std::shared_ptr<GameScene> GameScenePtr;
