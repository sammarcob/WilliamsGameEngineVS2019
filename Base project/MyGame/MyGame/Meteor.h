#pragma once

#include "Engine/GameEngine.h"

class Meteor : public GameObject
{
public:
	Meteor(sf::Vector2f pos);

	void draw();
	void update(sf::Time& elapsed);
	
	sf::FloatRect getCollisionRect();																							
	void handleCollision(GameObject& otherGameObject);
private:
	sf::Sprite sprite_;
	float yVel;
	float mSpeed = -0.50;
};

typedef std::shared_ptr<Meteor> MeteorPtr;