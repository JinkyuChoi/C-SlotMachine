//301024988 Jinkyu Choi
//2020-02-18
//Main Scene of entire SlotMachine, has most functions inside to make game run
//Referenced from Tom Tsiliopoulos


#include "MainScene.h"
#include "Game.h"
#include <ctime>
#include <algorithm>
#include <iomanip>

MainScene::MainScene()
{
	MainScene::start();
}

MainScene::~MainScene()
{
}

void MainScene::draw()
{
	m_pSlotMachine->draw();
	
	m_pSpinButton->draw();
	m_pQuitButton->draw();
	m_pIncreaseBetButton->draw();
	m_pDecreaseBetButton->draw();
	m_pRestartButton->draw();

	m_pCurrentBetLabel->draw();
	m_pCurrentMoneyLabel->draw();
	m_pResultLabelLabel->draw();
	m_pJackpotMoneyLabel->draw();
	m_pJackpotResultLabel->draw();

	if (ones >= 1)
	{
		for (int i = 0; i < ones; i++)
		{
			m_pOnes.push_back(new One());
			for (One* one : m_pOnes)
			{
				if (spinResult[0] == 1)
				{
					one->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.10, Config::SCREEN_HEIGHT * 0.12));
					one->draw();
				}
				if (spinResult[1] == 1)
				{
					one->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.43, Config::SCREEN_HEIGHT * 0.12));
					one->draw();
				}
				if (spinResult[2] == 1)
				{
					one->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.75, Config::SCREEN_HEIGHT * 0.12));
					one->draw();
				}
			}
		}
	}
	if (threes >= 1)
	{
		for (int i = 0; i < threes; i++)
		{
			m_pThrees.push_back(new Three());
			for (Three* three : m_pThrees)
			{
				if (spinResult[0] == 3)
				{
					three->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.10, Config::SCREEN_HEIGHT * 0.12));
					three->draw();
				}
				if (spinResult[1] == 3)
				{
					three->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.43, Config::SCREEN_HEIGHT * 0.12));
					three->draw();
				}
				if (spinResult[2] == 3)
				{
					three->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.75, Config::SCREEN_HEIGHT * 0.12));
					three->draw();
				}
			}
		}
	}
	if (fives >= 1)
	{
		for (int i = 0; i < fives; i++)
		{
			m_pFives.push_back(new Five());
			for (Five* five : m_pFives)
			{
				if (spinResult[0] == 5)
				{
					five->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.10, Config::SCREEN_HEIGHT * 0.12));
					five->draw();
				}
				if (spinResult[1] == 5)
				{
					five->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.43, Config::SCREEN_HEIGHT * 0.12));
					five->draw();
				}
				if (spinResult[2] == 5)
				{
					five->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.75, Config::SCREEN_HEIGHT * 0.12));
					five->draw();
				}
			}
		}
	}
	if (sevens >= 1)
	{
		for (int i = 0; i < sevens; i++)
		{
			m_pSevens.push_back(new Seven());
			for (Seven* seven : m_pSevens)
			{
				if (spinResult[0] == 7)
				{
					seven->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.10, Config::SCREEN_HEIGHT * 0.12));
					seven->draw();
				}
				if (spinResult[1] == 7)
				{
					seven->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.43, Config::SCREEN_HEIGHT * 0.12));
					seven->draw();
				}
				if (spinResult[2] == 7)
				{
					seven->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.75, Config::SCREEN_HEIGHT * 0.12));
					seven->draw();
				}
			}
		}
	}
}

void MainScene::update()
{
	m_pSpinButton->setMousePosition(m_mousePosition);
	if(m_pSpinButton->ButtonClick())
	{
		Spin();
		m_pSpinButton->setMouseButtonClicked(false);
	}

	m_pQuitButton->setMousePosition(m_mousePosition);
	m_pQuitButton->ButtonClick();

	m_pIncreaseBetButton->setMousePosition(m_mousePosition);
	if (m_pIncreaseBetButton->ButtonClick())
	{
		bettingUp();
		m_pIncreaseBetButton->setMouseButtonClicked(false);
	}
	
	m_pDecreaseBetButton->setMousePosition(m_mousePosition);
	if (m_pDecreaseBetButton->ButtonClick())
	{
		bettingDown();
		m_pDecreaseBetButton->setMouseButtonClicked(false);
	}

	m_pRestartButton->setMousePosition(m_mousePosition);
	if(m_pRestartButton->ButtonClick())
	{
		Restart();
		m_pRestartButton->setMouseButtonClicked(false);
	}


}

void MainScene::clean()
{
	removeAllChildren();
}

void MainScene::handleEvents()
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
				m_pIncreaseBetButton->setMouseButtonClicked(true);
				m_pDecreaseBetButton->setMouseButtonClicked(true);
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
				m_pIncreaseBetButton->setMouseButtonClicked(false);
				m_pDecreaseBetButton->setMouseButtonClicked(false);
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
void MainScene::start()
{
	m_pSpinButton = new SpinButton();
	addChild(m_pSpinButton);

	m_pQuitButton = new QuitButton();
	addChild(m_pQuitButton);

	m_pIncreaseBetButton = new IncreaseBetButton();
	addChild(m_pIncreaseBetButton);

	m_pDecreaseBetButton = new DecreaseBetButton();
	addChild(m_pDecreaseBetButton);

	m_pRestartButton = new RestartButton();
	addChild(m_pRestartButton);
	
	m_pSlotMachine = new SlotMachine();

	SDL_Color black = { 0,0,0,255 };
	m_pCurrentBetLabel = new Label("Player bet : " + std::to_string(playerBet), "OpenSans-Regular", 17,
		black, glm::vec2(300, 335), true, false);
	m_pCurrentMoneyLabel = new Label("Player Money : " + std::to_string(playerMoney), "OpenSans-Regular", 17,
		black, glm::vec2(10,335), true, false);;
	m_pResultLabelLabel = new Label("Result : " + result, "OpenSans-Regular", 15,
		black, glm::vec2(10,300), true, false);;
	m_pJackpotMoneyLabel = new Label("Jackpot Money : " + std::to_string(jackpot), "OpenSans-Regular", 15,
		black, glm::vec2(250,0), true, false);;
	m_pJackpotResultLabel = new Label("Jackpot Result : " + jackpotResult, "OpenSans-Regular", 17,
		black, glm::vec2(300,300), true, false);;
}

glm::vec2 MainScene::getMousePosition()
{
	return m_mousePosition;
}

void MainScene::Spin()
{
	ResetSlot();
	if (playerBet != 0 )
	{
		if (playerMoney <= 0 || playerBet > playerMoney)
		{
			m_pResultLabelLabel->setText("Not enough money");
		}
		else
		{
			int betLine[3] = { 0,0,0 };
			int outCome[3] = { 0,0,0 };

			for (auto spin = 0; spin < 3; spin++) {
				outCome[spin] = rand() % 50 + 1;
				if (checkRange(outCome[spin], 1, 25)) // 50% probability
				{
					betLine[spin] = 1;
					ones++;
				}
				else if (checkRange(outCome[spin], 26, 40)) // 30% probability
				{
					betLine[spin] = 3;
					threes++;
				}
				else if (checkRange(outCome[spin], 41, 48))  // 18% probability
				{
					betLine[spin] = 5;
					fives++;
				}
				else if (checkRange(outCome[spin], 49, 50))// 2% probability
				{
					betLine[spin] = 7;
					sevens++;
				}
			}
			spinResult[0] = betLine[0];
			spinResult[1] = betLine[1];
			spinResult[2] = betLine[2];

			WinCheck();
		}
	}
	else
	{
		m_pResultLabelLabel->setText("Must Bet");
	}
	
}

void MainScene::ResetSlot()
{
	ones = 0;
	m_pOnes.clear();
	threes = 0;
	m_pThrees.clear();
	fives = 0;
	m_pFives.clear();
	sevens = 0;
	m_pSevens.clear();
}

void MainScene::Restart()
{
	playerMoney = 1000;
	jackpot = 5000;
	playerBet = 0;
	start();
}

void MainScene::WinCheck()
{
	if (ones == 0)
	{
		int winMoney;
		if (threes == 3) {
			winMoney = playerBet * 10;
		}
		else if (fives == 3) {
			winMoney = playerBet * 20;
		}
		else if (sevens == 3) {
			winMoney = playerBet * 30;
		}
		else if (threes == 2) {
			winMoney = playerBet * 2;
		}
		else if (fives == 2) {
			winMoney = playerBet * 2;
		}
		else if (sevens == 2) {
			winMoney = playerBet * 3;
		}
		else if (sevens == 1) {
			winMoney = playerBet * 5;
		}
		else {
			winMoney = playerBet * 1;
		}
		playerMoney += winMoney;
		m_pResultLabelLabel->setText("Win! $" + std::to_string(winMoney));
		JackpotCheck();
		m_pCurrentMoneyLabel->setText(std::to_string(playerMoney));
	}
	else
	{
		m_pResultLabelLabel->setText("Lose");
		playerMoney -= playerBet;
		m_pCurrentMoneyLabel->setText(std::to_string(playerMoney));
	}

}

void MainScene::JackpotCheck()
{
	int jackPotTry = rand() % 51 + 1;
	int jackPotWin = rand() % 51 + 1;
	if (jackPotTry == jackPotWin) {
		playerMoney += jackpot;
		jackpot = 1000;
		m_pJackpotMoneyLabel->setText("Jackpot Money : " + std::to_string(jackpot));
		m_pJackpotResultLabel->setText("JACKPOT!!!!!!");
	}
	else
	{
		m_pJackpotResultLabel->setText("Maybe Next time...");
	}
}

void MainScene::bettingUp()
{
	if (playerBet < playerMoney)
	{
		playerBet += 10;
		m_pCurrentBetLabel->setText("Player Bet: " + std::to_string(playerBet));
	}
	else
	{
		m_pResultLabelLabel->setText("Betting cannot exceed your money");
	}
	
}

void MainScene::bettingDown()
{
	if (playerBet >= 10)
	{
		playerBet -= 10;
		m_pCurrentBetLabel->setText("Player Bet: " + std::to_string(playerBet));
	}
	else
	{
		m_pResultLabelLabel->setText("Betting cannot be negative");
	}
}


bool MainScene::checkRange(int value, int lowerBounds, int upperBounds)
{
	if (value >= lowerBounds && value <= upperBounds)
	{
		return true;
	}
	else
	{
		return false;
	}
}