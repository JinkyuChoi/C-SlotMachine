//301024988 Jinkyu Choi
//2020-02-18
//Main Scene of entire SlotMachine, has most functions inside to make game run
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __MAIN_SCENE__
#define __MAIN_SCENE__
#include "Scene.h"
#include "Label.h"
#include "SpinButton.h"
#include "SlotMachine.h"
#include "One.h"
#include "Three.h"
#include "Five.h"
#include "Seven.h"
#include "QuitButton.h"
#include "IncreaseBetButton.h"
#include "DecreaseBetButton.h"
#include "RestartButton.h"

class MainScene : public Scene
{
public:
	// constructor
	MainScene();
	// destructor
	~MainScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	// Game Objects

	//Buttons
	SlotMachine* m_pSlotMachine;
	SpinButton* m_pSpinButton;
	QuitButton* m_pQuitButton;
	IncreaseBetButton* m_pIncreaseBetButton;
	DecreaseBetButton* m_pDecreaseBetButton;
	RestartButton* m_pRestartButton;

	//Labels
	Label* m_pCurrentBetLabel;
	Label* m_pCurrentMoneyLabel;
	Label* m_pResultLabelLabel;
	Label* m_pJackpotMoneyLabel;
	Label* m_pJackpotResultLabel;

	//Slots
	std::list<One*> m_pOnes;
	std::list<Three*> m_pThrees;
	std::list<Five*> m_pFives;
	std::list<Seven*> m_pSevens;

	
	//Properties
	int playerMoney = 1000;
	int jackpot = 5000;
	int playerBet = 0;
	int spinResult[3] = { 0,0,0 };
	int ones = 0;
	int threes = 0;
	int fives = 0;
	int sevens = 0;
	std::string result = "Not played yet";
	std::string jackpotResult = "Not wined yet";

	//Methods
	void Spin();
	void ResetSlot();
	void Restart();
	void WinCheck();
	void JackpotCheck();
	void bettingUp();
	void bettingDown();

	bool checkRange(int value, int lowerBounds, int upperBounds);
	
	// private data member
	glm::vec2 m_mousePosition;

};

#endif /* defined (__MAIN_SCENE__) */
