#include "Five.h"
#include "TextureManager.h"
#include "Game.h"

Five::Five()
{
	TheTextureManager::Instance()->load("../Assets/textures/five.png",
		"five", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("five");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(0, 0));
	setType(GameObjectType::SLOTS);
}

Five::~Five()
{
}

void Five::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("five", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, false);
}

void Five::update()
{
}

void Five::clean()
{
}
