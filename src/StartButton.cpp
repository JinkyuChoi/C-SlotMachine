#include "StartButton.h"
#include "Game.h"

StartButton::StartButton()
	// call super constructor
	:Button(
		"../Assets/textures/StartButton.png",
		"startButton",
		START_BUTTON, glm::vec2(320.0f, 430.0f)), m_isClicked(false)
{
	
}

StartButton::~StartButton()
{
}

bool StartButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if(!m_isClicked)
		{
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}


