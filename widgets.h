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

	Fl_Button* Do = new Fl_Button(530, 270, 100, 50, "Создать");
	Fl_Button* back = new Fl_Button(10, 540, 100, 50, "Назад");

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

	Fl_Button* New = new Fl_Button(675, 10, 120, 50, "Создать . . .");
	New->callback(showNewMenu, nullptr);


	mW->end();
	mW->show();
	mens.mainWin = mW;
}

inline void alertsBoxes()
{
	Fl_Box* al_box_path = new Fl_Box(150, 30, 500, 70, "Укажите путь!");
	al_box_path->labelsize(20);
	al_box_path->box(FL_UP_BOX);
	al_box_path->color(FL_RED);
	al_box_path->hide();
	Data.alrt_path = al_box_path;

	Fl_Box* al_box_name = new Fl_Box(150, 30, 500, 70, "Укажите имя!");
	al_box_name->labelsize(20);
	al_box_name->box(FL_UP_BOX);
	al_box_name->color(FL_RED);
	al_box_name->hide();

	Fl_Box* al_NoSuchFile = new Fl_Box(150, 30, 500, 70, "По указанному пути файл не найден!");
	al_NoSuchFile->labelsize(20);
	al_NoSuchFile->box(FL_UP_BOX);
	al_NoSuchFile->color(FL_RED);
	al_NoSuchFile->hide();

	Data.alrt_NoFile = al_NoSuchFile;
}


