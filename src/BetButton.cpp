#include "BetButton.h"

BetButton::BetButton() :Button(
	                        "../Assets/textures/betbutton.png",
	                        "betbutton",
	                        BET_BUTTON, glm::vec2(530, 350.0f)), m_isClicked(false)
{
}

BetButton::~BetButton()
{
}

bool BetButton::ButtonClick()
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
