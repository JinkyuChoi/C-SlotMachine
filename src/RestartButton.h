//301024988 Jinkyu Choi
//2020-02-18
//Button to restart the game
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __RESTART_BUTTON__
#define __RESTART_BUTTON__

#include "Button.h"

class RestartButton : public Button
{
public:
	RestartButton();
	~RestartButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__RESTART_BUTTON__) */
