#include "Score.h"
#include "GameScene.h"
#include <sstream>


Score::Score(sf::Vector2f pos)
{
	text_.setFont(GAME.getFont("Resources/Courneuf-Regular.ttf"));
	text_.setPosition(pos);
	text_.setCharacterSize(24);
	text_.setOutlineColor(sf::Color::White);
	text_.setFillColor(sf::Color::White);
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

	if (scene.getScore() >= 10)
	{
		text_.setOutlineColor(sf::Color::Red);
		text_.setFillColor(sf::Color::Red);
	}

	text_.setString(stream.str());
}



