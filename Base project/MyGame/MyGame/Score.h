#pragma once
#include "Engine/GameEngine.h"


class Score : public GameObject
{
public:
	//create score instance 
	Score(sf::Vector2f pos);

	//fnctions overriden deom gameobject 
	void draw();
	void update(sf::Time& elapsed);
	
private:
	sf::Text text_;
};

typedef std::shared_ptr<Score> ScorePtr;