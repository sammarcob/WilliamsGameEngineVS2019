#include "Score.h"
#include "GameScene.h"
#include <sstream>

Score::Score(sf::Vector2f pos)
{
	text_.setFont(GAME.getFont("Resources//Courneuf-Regular.tff"));
	text_.setPosition(pos);
	text_.setCharacterSize(24);
	text_.setColor(sf::Color::White);
	assignTag("score");
}

void Score::draw()
{
	GAME.getRenderWindow().draw(text_);
}

void Score::update(sf::Time& elapsed)
{
	
	GameScene& scene = (GameScene&)GAME.getCurrentScene(); // bruhj

	std::stringstream stream;
	stream << "Score: " << scene.getScore();

	/*if (scene.getScore() > 50)
	{
		text_.setColor(sf::Color::Red);
	}*/

	text_.setString(stream.str());
}