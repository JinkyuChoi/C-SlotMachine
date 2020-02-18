#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "Label.h"
#include "StartButton.h"
#include "Slot.h"

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
	std::string reels();
	int checkRange(int value, int lowerBounds, int upperBounds);
	
	// Game Objects
	Label* m_pStartLabel;
	StartButton* m_pStartButton;
	Slot* m_pSlot;

	// private data member
	glm::vec2 m_mousePosition;


	//datas
	int playerMoney = 1000;
	int winnings = 0;
	int jackpot = 5000;
	int turn = 0;
	int playerBet = 0;
	int winNumber = 0;
	int lossNumber = 0;
	int spinResult;
	std::string fruits = "";
	int winRatio = 0;
	int grapes = 0;
	int bananas = 0;
	int oranges = 0;
	int cherries = 0;
	int bars = 0;
	int bells = 0;
	int sevens = 0;
	int blanks = 0;

};

#endif /* defined (__START_SCENE__) */