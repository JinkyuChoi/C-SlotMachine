//301024988 Jinkyu Choi
//2020-02-18
//Button to quit the game
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __QUIT_BUTTON__
#define __QUIT_BUTTON__

#include "Button.h"

class QuitButton : public Button
{
public:
	QuitButton();
	~QuitButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__QUIT_BUTTON__) */