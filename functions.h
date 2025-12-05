#pragma once
#include "card.h"

//тут описаны функции, работающие с группами

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

inline void changeMode(Fl_Widget* w, void* data)
{
	SetConsoleOutputCP(CP_UTF8);

	if (Data::mode == 0)
	{
		Data::mode = 1;
		mens.T->label("Добавление папки");
		inps::path->label("Путь к папке");
		cout << "Добавление папки" << endl;
	}
	else
	{
		Data::mode = 0;
		mens.T->label("Добавление приложения");
		inps::path->label("Путь к файлу");
		cout << "Добавление приложения" << endl;
	}
	
}











