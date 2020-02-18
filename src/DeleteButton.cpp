#include "DeleteButton.h"

DeleteButton::DeleteButton() : Button(
	"../Assets/textures/deletebutton.png",
	"deletebutton",
	DELETE_BUTTON, glm::vec2(450, 350.0f)), m_isClicked(false)
{
}

DeleteButton::~DeleteButton()
{
}

bool DeleteButton::ButtonClick()
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
