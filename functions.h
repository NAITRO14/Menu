#pragma once
#include "card.h"

//тут описаны функции, работающие с группами
helpData Data;

inline void showNewMenu(Fl_Widget* w, void* data)
{
	if (mens.mainWin->visible())
	{
		mens.mainWin->hide();
		mens.newFile->show();
	}
	else
	{
		mens.mainWin->show();
		mens.newFile->hide();
	}
}





