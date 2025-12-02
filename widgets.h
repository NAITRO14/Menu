#pragma once
#include "includes.h"
#include "Header.h"
#include "functions.h"
int card::cardsCount = 0;

menues mens;
//тут описанны группы

inline void newFile()
{
	Fl_Group* nF = new Fl_Group(0, 0, 800, 600);

	Fl_Input* inp_path = new Fl_Input(300, 175, 200, 50, "Enter path to file");
	Fl_Input* inp_name = new Fl_Input(300, 375, 200, 50, "Enter name");

	Fl_Button* Do = new Fl_Button(530, 270, 100, 50, "Do");
	Fl_Button* back = new Fl_Button(10, 540, 100, 50, "Back");

	Data.path = inp_path;
	Data.name = inp_name;

	Do->callback(createCard, nullptr);
	back->callback(showNewMenu, nullptr);

	nF->end();
	nF->hide();
	mens.newFile = nF;
}

inline void mainWin()
{
	Fl_Group* mW = new Fl_Group(0, 0, 800, 600);

	Fl_Button* New = new Fl_Button(675, 10, 120, 50, "New");
	New->callback(showNewMenu, nullptr);

	Fl_Button* testB = new Fl_Button(680, 550, 120, 50, "test");
	testB->callback(all_pos_change, nullptr);


	mW->end();
	mW->show();
	mens.mainWin = mW;
}


