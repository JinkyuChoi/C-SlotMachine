//301024988 Jinkyu Choi
//2020-02-18
//Visual Frame for the Slots
//Referenced from Tom Tsiliopoulos


#include "SlotMachine.h"
#include "TextureManager.h"
#include "Game.h"

SlotMachine::SlotMachine()
{
	TheTextureManager::Instance()->load("../Assets/textures/slotmachine.png",
		"slotmachine", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("slotmachine");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(0, 0));
	setType(GameObjectType::SLOT_MACHINE);
}

SlotMachine::~SlotMachine()
{
}

void SlotMachine::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("slotmachine", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, false);
}

void SlotMachine::update()
{
}

void SlotMachine::clean()
{
}
