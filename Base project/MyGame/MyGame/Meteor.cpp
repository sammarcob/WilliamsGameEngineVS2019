#include "Meteor.h"
#include "Laser.h"

const float SPEED = -0.10f;


Meteor::Meteor(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/meteor.png"));
	sprite_.setPosition(pos);
	assignTag("meteor");
}

void Meteor::draw()
{
	GAME.getRenderWindow().draw(sprite_);
	
}

void Meteor::timer()
{
	int ran = 1 + rand() % 2; //idk man bruuuuhhh
}

void Meteor::update(sf::Time& elapsed)
{
	
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		makeDead();
		
	}
	else if (ran == 2)
	{
		sprite_.setPosition(sf::Vector2f(pos.x + SPEED * msElapsed, pos.y + SPEED * msElapsed));
		
	}
	else if (ran == 1)
	{
		sprite_.setPosition(sf::Vector2f(pos.x + SPEED * msElapsed, pos.y));
	}
	//30 CHALLENGE 
}