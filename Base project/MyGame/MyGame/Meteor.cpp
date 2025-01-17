#include "Meteor.h"
#include "Explosion.h"
#include "GameScene.h"
#include <conio.h>
#include <iostream>
#include "GameScene.h"





//AAAAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHHHHHHHHHHH


sf::FloatRect Meteor::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}

void Meteor::handleCollision(GameObject& otherGameObject)
{
	sf::Vector2f pos = sprite_.getPosition();


	if (otherGameObject.hasTag("laser"))
	{
		std::cout << "hit" << std::endl;
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.increaseScore();
		otherGameObject.makeDead();
	}

	ExplosionPtr explosion = std::make_shared<Explosion>(sprite_.getPosition());
	GAME.getCurrentScene().addGameObject(explosion);

	makeDead();
}

Meteor::Meteor(sf::Vector2f pos)
{

	sprite_.setTexture(GAME.getTexture("Resources/meteor.png"));
	sprite_.setPosition(pos);
	assignTag("meteor");
	float speedRan = (float)rand() / (float)RAND_MAX + 0.05f;
	mSpeed *= speedRan;

	int ran = 1 + rand() % 3;

	if (ran == 1)
	{
		// straight
		yVel = 0;
	}
	else if (ran == 2)
	{
		// down and left
		yVel = 0.10f;
	}
	else if (ran == 3)
	{
		// up and left
		yVel = -0.10f;
	}
	/*sf::FloatRect test = getCollisionRect();
	std::cout << test.height << std::endl;*/
	setCollisionCheckEnabled(true);
}

void Meteor::draw()
{
	GAME.getRenderWindow().draw(sprite_);

}

void Meteor::update(sf::Time& elapsed)
{

	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.decreaseLives();

		makeDead();

	}
	else if (pos.y >= GAME.getRenderWindow().getSize().y - 10 || pos.y <= 10)
	{
		makeDead();
	}
	
	

	sprite_.setPosition(sf::Vector2f(pos.x + mSpeed * msElapsed, pos.y + yVel * mSpeed * msElapsed));
}