#pragma once
#include "includes.h"
#include "Header.h"
#include "functions.h"
#include "structs.h"
int card::cardsCount = 0;

menues mens;
//тут описанны группы

inline void newFile()
{
	Fl_Group* nF = new Fl_Group(0, 0, 800, 600);

	Fl_Input* inp_path = new Fl_Input(300, 250, 200, 50, "Путь к файлу");
	Fl_Input* inp_name = new Fl_Input(300, 310, 200, 50, "Название карточки");

	inp_path->when(FL_WHEN_ENTER_KEY);
	inp_path->callback(createCard, nullptr);

	inp_name->when(FL_WHEN_ENTER_KEY);
	inp_name->callback(createCard, nullptr);


	button* Do = new button(530, 270, 100, 50, "Создать");
	button* back = new button(10, 540, 100, 50, "Назад");

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

	plus_button* New = new plus_button(760, 10, 75, 30, "+\t  ");
	New->callback(showNewMenu, nullptr);


	mW->end();
	mW->show();
	mens.mainWin = mW;
}

inline void alertsBoxes()
{
	al_box* al_box_path = new al_box(150, 30, 500, 70, "Укажите путь!");
	Data.alrt_path = al_box_path;

	al_box* al_box_name = new al_box(150, 30, 500, 70, "Укажите имя!");
	Data.alrt_name = al_box_name;

	al_box* al_NoSuchFile = new al_box(150, 30, 500, 70, "По указанному пути файл не найден!");
	Data.alrt_NoFile = al_NoSuchFile;
}


