//301024988 Jinkyu Choi
//2020-02-18
//Button to add the Betting
//Referenced from Tom Tsiliopoulos


#include "IncreaseBetButton.h"

IncreaseBetButton::IncreaseBetButton() : Button(
	"../Assets/textures/addbutton.png",
	"addbutton",
	ADD_BUTTON, glm::vec2(525, 350.0f)), m_isClicked(false)
{
}

IncreaseBetButton::~IncreaseBetButton()
{
}

bool IncreaseBetButton::ButtonClick()
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
