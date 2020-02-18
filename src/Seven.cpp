#include "Seven.h"
#include "TextureManager.h"
#include "Game.h"

Seven::Seven()
{
	TheTextureManager::Instance()->load("../Assets/textures/seven.png",
		"seven", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("seven");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(0, 0));
	setType(GameObjectType::SLOTS);
}

Seven::~Seven()
{
}

void Seven::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("seven", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, false);
}

void Seven::update()
{
}

void Seven::clean()
{
}
