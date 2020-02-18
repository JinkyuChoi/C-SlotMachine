//301024988 Jinkyu Choi
//2020-02-18
//Visual Slot for Three
//Referenced from Tom Tsiliopoulos


#include "Three.h"
#include "TextureManager.h"
#include "Game.h"

Three::Three()
{
	TheTextureManager::Instance()->load("../Assets/textures/three.png",
		"three", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("three");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(0, 0));
	setType(GameObjectType::SLOTS);
}

Three::~Three()
{
}

void Three::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("three", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, false);
}

void Three::update()
{
}

void Three::clean()
{
}
