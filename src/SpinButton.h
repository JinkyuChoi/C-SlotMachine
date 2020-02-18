//301024988 Jinkyu Choi
//2020-02-18
//Button to spin the slots
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __SPIN_BUTTON__
#define __SPIN_BUTTON__

#include "Button.h"

class SpinButton : public Button
{
public:
	SpinButton();
	~SpinButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__SPIN_BUTTON__) */