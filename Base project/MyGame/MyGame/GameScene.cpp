#include "GameScene.h"
#include "Ship.h"
#include "Meteor.h"

GameScene::GameScene() 
{
	ShipPtr ship = std::make_shared<Ship>();
	addGameObject(ship);
	MeteorPtr meteor = std::make_shared<Meteor>(sf::Vector2f(500.0, 100.0));
	addGameObject(meteor);
}
