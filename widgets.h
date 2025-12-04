#pragma once
#include "functions.h"
int card::cardsCount = 0;

namespace inps
{
	Fl_Input* path = nullptr;
	Fl_Input* name = nullptr;
}

namespace alrts {
	al_box* alrt_path = nullptr;
	al_box* alrt_name = nullptr;
	al_box* alrt_NoFile = nullptr;
	al_box* alrt_alreadyHave = nullptr;
	al_box* alrt_operErr = nullptr;
}

namespace Data
{
	short mode = 0;
}

menues mens;
//тут описанны группы

inline void newFile()
{
	Fl_Group* nF = new Fl_Group(0, 0, 800, 600);

	Fl_Box* Text = new Fl_Box(225, 152, 350, 60, "Добавление файла");
	Text->box(FL_UP_BOX);
	Text->labelsize(20);
	mens.T = Text;

	Fl_Input* inp_path = new Fl_Input(100, 250, 200, 30, "Путь к файлу");
	Fl_Input* inp_name = new Fl_Input(500, 250, 200, 30, "Название карточки");

	inp_path->when(FL_WHEN_ENTER_KEY);
	inp_path->callback(card::createCard, nullptr);

	inp_name->when(FL_WHEN_ENTER_KEY);
	inp_name->callback(card::createCard, nullptr);


	button* Do = new button(320, 451, 100, 30, "Создать");
	folder_but* fldr = new folder_but(430, 451, 50, 30, "Папка");

	button* back = new button(10, 540, 100, 50, "Назад");

	inps::path = inp_path;
	inps::name = inp_name;

	Do->callback(card::createCard, nullptr);
	back->callback(showNewMenu, nullptr);
	fldr->callback(changeMode, nullptr);

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
	alrts::alrt_path = al_box_path;

	al_box* al_box_name = new al_box(150, 30, 500, 70, "Укажите имя!");
	alrts::alrt_name = al_box_name;

	al_box* al_NoSuchFile = new al_box(150, 30, 500, 70, "По указанному пути файл не найден!");
	alrts::alrt_NoFile = al_NoSuchFile;

	al_box* al_alreadyHave = new al_box(150, 30, 500, 70, "Этот файл уже добавлен в программу!");
	alrts::alrt_alreadyHave = al_alreadyHave;

	al_box* al_openError = new al_box(175, 480, 450, 75, "Ошибка во время открытия файла!");
	alrts::alrt_operErr = al_openError;
}


