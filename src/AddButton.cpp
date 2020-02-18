#include "AddButton.h"

AddButton::AddButton() : Button(
	"../Assets/textures/addbutton.png",
	"addbutton",
	ADD_BUTTON, glm::vec2(400, 350.0f)), m_isClicked(false)
{
}

AddButton::~AddButton()
{
}

bool AddButton::ButtonClick()
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
