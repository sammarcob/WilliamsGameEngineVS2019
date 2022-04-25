#include "GameScene.h"
#include "Ship.h"
#include "Meteor.h"

GameScene::GameScene() 
{
	ShipPtr ship = std::make_shared<Ship>();
	MeteorPtr meteor = std::make_shared<Meteor>();
	addGameObject(ship);
	addGameObject(meteor);
}
