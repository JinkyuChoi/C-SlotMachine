#include "Slot.h"
#include "TextureManager.h"
#include "Game.h"

Slot::Slot()
{
	TheTextureManager::Instance()->load("../Assets/textures/slot1.png",
		"slot1", TheGame::Instance()->getRenderer());

	TheTextureManager::Instance()->load("../Assets/textures/slot2.png",
		"slot2", TheGame::Instance()->getRenderer());

	TheTextureManager::Instance()->load("../Assets/textures/slot3.png",
		"slot3", TheGame::Instance()->getRenderer());
	
	TheTextureManager::Instance()->load("../Assets/textures/slot4.png",
		"slot4", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("slot1");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f));
	setIsColliding(false);
	setType(GameObjectType::ISLAND);
	//setVelocity(glm::vec2(0.0f, 0.0f));

	//TheSoundManager::Instance()->load("../Assets/audio/yay.ogg", "yay", SOUND_SFX);
}

Slot::~Slot()
{
}

void Slot::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("island", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Slot::update()
{

}

void Slot::clean()
{
}

void Slot::Change()
{
	int slotchange = rand() % 4 + 1;
	switch (slotchange)
	{
	case 1:
		TextureManager::Instance()->draw("slot1", getPosition().x, getPosition().y,
			TheGame::Instance()->getRenderer(), 0, 255, true);
		std::cout << "slot1" << std::endl;
		break;
	case 2:
		TextureManager::Instance()->draw("slot2", getPosition().x, getPosition().y,
			TheGame::Instance()->getRenderer(), 0, 255, true);
		std::cout << "slot2" << std::endl;
		break;
	case 3:
		TextureManager::Instance()->draw("slot3", getPosition().x, getPosition().y,
			TheGame::Instance()->getRenderer(), 0, 255, true);
		std::cout << "slot3" << std::endl;
		break;
	case 4:
		TextureManager::Instance()->draw("slot4", getPosition().x, getPosition().y,
			TheGame::Instance()->getRenderer(), 0, 255, true);
		std::cout << "slot4" << std::endl;
		break;
	}
}

