#include "Explosion.h"

Explosion::Explosion(sf::Vector2 pos)
		 : AnimatedSprite(pos)
{
	AnimatedSprite::setTexture(GAME.getTexture("Resources"))//explosion sprite sheet go ghere :(
}