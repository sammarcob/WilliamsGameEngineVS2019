#include "Explosion.h"

Explosion::Explosion(sf::Vector2f pos) //IM BOUT TA CUUUUUUUUUUUUUU
		 : AnimatedSprite(pos)
{
	AnimatedSprite::setTexture(GAME.getTexture("Resources/explosion-spritesheet.png"));//explosion sprite sheet go ghere :(
	SetUpExplosionAnimation();
	playAnimation("explosion", AnimationMode::OnceForwards);

}

void Explosion::SetUpExplosionAnimation()
{
	std::vector<sf::IntRect> frames;
	frames.push_back(sf::IntRect(0, 0, 64, 64));//1
	frames.push_back(sf::IntRect(64, 0, 64, 64));//2
	frames.push_back(sf::IntRect(128, 0, 64, 64));//3
	frames.push_back(sf::IntRect(192, 0, 64, 64));//4
	frames.push_back(sf::IntRect(256, 0, 64, 64));//5
	frames.push_back(sf::IntRect(320, 0, 64, 64));//6
	frames.push_back(sf::IntRect(384, 0, 64, 64));//7
	frames.push_back(sf::IntRect(448, 0, 64, 64));//8
	frames.push_back(sf::IntRect(512, 0, 64, 64));//9
	
	addAnimation("explosion", frames);
}

void Explosion::update(sf::Time& elapsed)
{
	AnimatedSprite::update(elapsed);

	if (!isPlaying())
	{
		makeDead();
	}
}