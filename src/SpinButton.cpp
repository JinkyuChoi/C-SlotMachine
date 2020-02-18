//301024988 Jinkyu Choi
//2020-02-18
//Button to spin the slots
//Referenced from Tom Tsiliopoulos


#include "SpinButton.h"
#include "Game.h"

SpinButton::SpinButton()
	// call super constructor
	:Button(
		"../Assets/textures/SpinButton.png",
		"startButton",
		START_BUTTON, glm::vec2(320.0f, 430.0f)), m_isClicked(false)
{
	
}

SpinButton::~SpinButton()
{
}

bool SpinButton::ButtonClick()
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


