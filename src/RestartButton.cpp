#include "RestartButton.h"

RestartButton::RestartButton() : Button(
	"../Assets/textures/restartbutton.png",
	"restartbutton",
	RESTART_BUTTON, glm::vec2(100, 430.0f)), m_isClicked(false)
{
}

RestartButton::~RestartButton()
{
}

bool RestartButton::ButtonClick()
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
