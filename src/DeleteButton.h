#pragma once
#ifndef __DELETE_BUTTON__
#define __DELETE_BUTTON__

#include "Button.h"

class DeleteButton : public Button
{
public:
	DeleteButton();
	~DeleteButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__DELETE_BUTTON__) */