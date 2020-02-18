#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "Label.h"
#include "SpinButton.h"
#include "SlotMachine.h"
#include "One.h"
#include "Three.h"
#include "Five.h"
#include "Seven.h"
#include "QuitButton.h"
#include "BetButton.h"
#include "AddButton.h"
#include "DeleteButton.h"
#include "RestartButton.h"

class StartScene : public Scene
{
public:
	// constructor
	StartScene();
	// destructor
	~StartScene();

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
	BetButton* m_pBetButton;
	AddButton* m_pAddButton;
	DeleteButton* m_pDeleteButton;
	RestartButton* m_pRestartButton;

	//Labels
	Label* m_pCurrentBetLabel;
	Label* m_pCurrentMoneyLabel;
	Label* m_pResultLabelLabel;
	Label* m_pJackpotMoneyLabel;
	Label* m_pJackpotResultLabel;


	One* m_pOne;
	Three* m_pThree;
	Five* m_pFive;
	Seven* m_pSeven;

	//properties
	int playerMoney = 1000;
	int jackpot = 5000;
	int playerBet = 0;
	std::string spinResult[3] = { "","","" };
	std::string slots = "";
	float winRatio = 0.0f;
	int one = 0;
	int three = 0;
	int five = 0;
	int seven = 0;
	std::string result = "Not played yet";
	std::string jackpotResult = "Not played yet";
	
	// private data member
	glm::vec2 m_mousePosition;

};

#endif /* defined (__START_SCENE__) */