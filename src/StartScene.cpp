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
	m_pQuitButton->draw();
	m_pBetButton->draw();
	m_pAddButton->draw();
	m_pDeleteButton->draw();
	m_pRestartButton->draw();
	
}

void StartScene::update()
{
	m_pSpinButton->setMousePosition(m_mousePosition);
	m_pSpinButton->ButtonClick();

	m_pQuitButton->setMousePosition(m_mousePosition);
	m_pQuitButton->ButtonClick();

	m_pBetButton->setMousePosition(m_mousePosition);
	m_pBetButton->ButtonClick();

	m_pAddButton->setMousePosition(m_mousePosition);
	m_pAddButton->ButtonClick();
	
	m_pDeleteButton->setMousePosition(m_mousePosition);
	m_pDeleteButton->ButtonClick();

	m_pRestartButton->setMousePosition(m_mousePosition);
	m_pRestartButton->ButtonClick();
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
				m_pQuitButton->setMouseButtonClicked(true);
				m_pBetButton->setMouseButtonClicked(true);
				m_pAddButton->setMouseButtonClicked(true);
				m_pDeleteButton->setMouseButtonClicked(true);
				m_pRestartButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pSpinButton->setMouseButtonClicked(false);
				m_pQuitButton->setMouseButtonClicked(false);
				m_pBetButton->setMouseButtonClicked(false);
				m_pAddButton->setMouseButtonClicked(false);
				m_pDeleteButton->setMouseButtonClicked(false);
				m_pRestartButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
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


	m_pQuitButton = new QuitButton();
	addChild(m_pQuitButton);


	m_pBetButton = new BetButton();
	addChild(m_pBetButton);

	m_pAddButton = new AddButton();
	addChild(m_pAddButton);

	m_pDeleteButton = new DeleteButton();
	addChild(m_pDeleteButton);

	m_pRestartButton = new RestartButton();
	addChild(m_pRestartButton);
	
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
