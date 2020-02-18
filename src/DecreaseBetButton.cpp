//301024988 Jinkyu Choi
//2020-02-18
//Button to decrease the Betting
//Referenced from Tom Tsiliopoulos


#include "DecreaseBetButton.h"

DecreaseBetButton::DecreaseBetButton() : Button(
	"../Assets/textures/deletebutton.png",
	"deletebutton",
	DELETE_BUTTON, glm::vec2(575, 350.0f)), m_isClicked(false)
{
}

DecreaseBetButton::~DecreaseBetButton()
{
}

bool DecreaseBetButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
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
