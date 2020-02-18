#include "StartScene.h"
#include "Game.h"
#include <ctime>
#include <algorithm>
#include <iomanip>

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
{
}

void StartScene::draw()
{
	//m_pStartLabel->draw();
	m_pSlotMachine->draw();
	m_pOne->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.10, Config::SCREEN_HEIGHT * 0.12));
	m_pOne->draw();
	m_pFive->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.43, Config::SCREEN_HEIGHT * 0.12));
	m_pFive->draw();
	m_pSeven->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.75, Config::SCREEN_HEIGHT * 0.12));
	m_pSeven->draw();
	m_pSpinButton->draw();
	
}

void StartScene::update()
{
	m_pSpinButton->setMousePosition(m_mousePosition);
	m_pSpinButton->ButtonClick();
}

void StartScene::clean()
{
	removeAllChildren();
}

void StartScene::handleEvents()
{
	int wheel = 0;
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pSpinButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pSpinButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;





			
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			}
			break;

		default:
			break;
		}
	}
}

// this function is used for initialization
void StartScene::start()
{

	m_pSpinButton = new SpinButton();
	addChild(m_pSpinButton);

	m_pSlotMachine = new SlotMachine();
	m_pOne = new One();
	m_pThree = new Three();
	m_pFive = new Five();
	m_pSeven = new Seven();

}

glm::vec2 StartScene::getMousePosition()
{
	return m_mousePosition;
}
