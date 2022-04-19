#include "Ship.h"
using namespace std;
#include <conio.h>
#include <stdio.h>
#include <iostream>

const float SPEED = 0.3f;

void Ship::update(sf::Time& elapsed)
{
	
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;

	int msElapsed = elapsed.asMilliseconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))		y -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))		y += SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))		x -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))	x += SPEED * msElapsed;

	sprite_.setPosition(sf::Vector2f(x, y));
	
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