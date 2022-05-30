#include "Ship.h"
using namespace std;
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include "Laser.h"


const float SPEED = 0.5f;
const int FIRE_DELAY = 200;

void Ship::update(sf::Time& elapsed)
{

	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;



	int msElapsed = elapsed.asMilliseconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		y -= SPEED * msElapsed;
		if (y < 0)
		{
			y = 0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		y += SPEED * msElapsed;
		float yMax = GAME.getRenderWindow().getSize().y - 120;
		if (y > yMax)
		{
			y = yMax;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		x -= SPEED * msElapsed;
		if (x < 0)
		{
			x = 0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		x += SPEED * msElapsed;
		float xMax = GAME.getRenderWindow().getSize().x - 85;
		if (x > xMax)
		{
			x = xMax;
		}
	}


	sprite_.setPosition(sf::Vector2f(x, y));
	
	if (fireTimer_ > 0)
	{
		fireTimer_ -= msElapsed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireTimer_ <= 0)
	{
		fireTimer_ = FIRE_DELAY;

		sf::FloatRect bounds = sprite_.getGlobalBounds();

		float laserX = x + bounds.width;
		float laserY = y + (bounds.height / 6.0f);

		float laserX2 = x + bounds.width;
		float laserY2 = y + (bounds.height / 2.0f);

		float laserX3 = x + bounds.width;
		float laserY3 = y + (bounds.height / 1.1f);
		

		LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY));
		GAME.getCurrentScene().addGameObject(laser);

		LaserPtr laser2 = std::make_shared<Laser>(sf::Vector2f(laserX2, laserY2));
		GAME.getCurrentScene().addGameObject(laser2);

		LaserPtr laser3 = std::make_shared<Laser>(sf::Vector2f(laserX3, laserY3));
		GAME.getCurrentScene().addGameObject(laser3);
	}
	
}

Ship::Ship()
{
	sprite_.setTexture(GAME.getTexture("Resources/ship.png"));
	sprite_.setPosition(sf::Vector2f(100, 100));
}

void Ship::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}
// bottom of 22 (challenge) needs to be done