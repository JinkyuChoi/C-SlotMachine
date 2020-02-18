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
	SlotMachine* m_pSlotMachine;
	SpinButton* m_pSpinButton;
	QuitButton* m_pQuitButton;
	BetButton* m_pBetButton;
	AddButton* m_pAddButton;
	DeleteButton* m_pDeleteButton;
	RestartButton* m_pRestartButton;
	One* m_pOne;
	Three* m_pThree;
	Five* m_pFive;
	Seven* m_pSeven;
	
	// private data member
	glm::vec2 m_mousePosition;

};

#endif /* defined (__START_SCENE__) */