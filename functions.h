#pragma once
#include "Header.h"
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

inline void createCard(Fl_Widget * w, void* data)
{
	
	card* crd = new card(Data.path->value(), Data.name->value());

	mens.mainWin->add(crd->get_body());

	cards.push_back(crd);
}

inline void all_pos_change(Fl_Widget* w, void* data)
{
	for (short i = 0; i < cards.size(); i++)
	{
		cards[i]->change_pos();
		
	}
}


