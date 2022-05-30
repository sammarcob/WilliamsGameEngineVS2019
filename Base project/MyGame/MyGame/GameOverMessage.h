#pragma once

#include "Engine/GameEngine.h"

class GameOverMessage : public GameObject
{
public:
	// creat game over messsgwe display 
	GameOverMessage(int score);

	//functuiojn overriddeb from gameobject
	void draw();
	void update(sf::Time& elapsed);

private:
	sf::Text text_;
};

typedef std::shared_ptr<GameOverMessage> GameOverMessagePtr;