#pragma once
#include "Header.h"
#include "structs.h"

//тут описаны функции, работающие с группами
helpData Data;

//====================================
//алерты
inline void hidePathAlert(void* data)
{
	Data.alrt_path->hide();
}
inline void showPathAlert(void* data)
{
	Data.alrt_path->show();
	Fl::add_timeout(3, hidePathAlert, nullptr);
}


inline void hideNameAlert(void* data)
{
	Data.alrt_name->hide();
}

inline void showNameAlert(void* data)
{
	Data.alrt_name->show();
	Fl::add_timeout(3, hideNameAlert, nullptr);
}

inline void hideNoFileAlert(void* data)
{
	Data.alrt_NoFile->hide();
}

inline void showNoFileAlert(void* data)
{
	Data.alrt_NoFile->show();
	Fl::add_timeout(3, hideNoFileAlert, nullptr);
}
//алерты
//====================================

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
	//Обработка ошибок

	//путь не указан
	if (strlen(Data.path->value()) == 0)
	{
		cout << "Ошибка. Путь не указан" << endl;
		Fl::add_timeout(0.1 , showPathAlert, nullptr);
		return;
	}
	//имя не указано
	if (strlen(Data.name->value()) == 0)
	{
		cout << "Ошибка. Имя не указано" << endl;
		Fl::add_timeout(0.1, showNameAlert, nullptr);
		return;
	}
	
	//файл не найден
	ifstream file(Data.path->value());
	if (!file.good())
	{
		cout << "Не удалось найти файл!" << endl;
		Fl::add_timeout(0.1, showNoFileAlert, nullptr);
		return;
	}

	for (short i = 0; i < cards.size(); i++)
	{
		if (strcmp(cards[i]->get_path().c_str(), Data.path->value()) == 0)
		{
			cout << "Ссылка на такой файл уже есть!" << endl;
			return;
		}
	}

	card* crd = new card(Data.path->value(), Data.name->value());
	mens.mainWin->add(crd->get_body());

	cards.push_back(crd);
}




