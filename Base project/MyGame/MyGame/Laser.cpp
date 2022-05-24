#include "Laser.h"
#include <iostream>

const float SPEED = 1.2f;

sf::FloatRect Laser::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}

Laser::Laser(sf::Vector2f pos)
{
	
	sprite_.setTexture(GAME.getTexture("Resources/laser.png"));
	sprite_.setPosition(pos);
	assignTag("laser");
	
	pew.setBuffer(GAME.getSoundBuffer("Resources/pew.wav"));
	pew.play();
}

void Laser::draw()
{
	GAME.getRenderWindow().draw(sprite_);

	
}

void Laser::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.x > GAME.getRenderWindow().getSize().x)
	{
		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x + SPEED * msElapsed, pos.y));
	}
}