#include "card.h"

#ifdef _UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

bool FolderExists(const wchar_t* wpath) 
{
	// Проверяем существование
	DWORD attribs = GetFileAttributesW(wpath);
	delete[] wpath;

	if (attribs == INVALID_FILE_ATTRIBUTES) {
		return false;
	}
	return (attribs & FILE_ATTRIBUTE_DIRECTORY) != 0;
}


vector<card*> cards;

card::card(string p, string n)
{
	path = p;
	name = n;
	cardsCount += 1;

	x = posX;
	y = posY;

	pos_plus();

	cardBody = new cardBut(x, y, 100, 50, name.c_str());
	cardBody->callback(card::open_file, &path);

	
}

card::~card()
{
	delete cardBody;
	
}

void card::pos_plus()
{
	posX += 110;
	if (posX >= 600)
	{
		posX = 10;
		posY += 60;
	}
}

void card::pos_minus()
{
	posX -= 110;
	if (posX <= 0)
	{
		posX = 560;
		posY -= 60;
	}
}

string card::get_name()
{
	return name;
}

string card::get_path()
{
	return path;
}

void card::createCard(Fl_Widget* w, void* data)
{
	SetConsoleOutputCP(CP_UTF8);

	string tmp = inps::path->value();

	//Обработка ошибок

	//путь не указан
	if (strlen(inps::path->value()) == 0)
	{
		cout << "Ошибка. Путь не указан" << endl;
		Fl::add_timeout(0.1, showPathAlert, nullptr);
		return;
	}
	//имя не указано
	if (strlen(inps::name->value()) == 0)
	{
		cout << "Ошибка. Имя не указано" << endl;
		Fl::add_timeout(0.1, showNameAlert, nullptr);
		return;
	}

	
	for (short i = 0; i < cards.size(); i++)
	{
		if (strcmp(cards[i]->get_path().c_str(), inps::path->value()) == 0)
		{
			cout << "Ссылка на такой файл уже есть!" << endl;
			Fl::add_timeout(0.1, ShowAlreadyHere, nullptr);
			return;
		}
	}

	
	if (Data::mode == 0)
	{
		tmp = "\"" + tmp + "\"";
		//файл не найден
		ifstream file(inps::path->value());
		if (!file.good())
		{
			cout << "Не удалось найти файл!" << endl;
			Fl::add_timeout(0.1, showNoFileAlert, nullptr);
			return;
		}
	}
	else
	{
		tmp = inps::path->value();

		wstring line = UTF8ToWide(tmp);

		if (FolderExists(line.c_str()) == false)
		{
			cout << "Папка не обнаружена!" << endl;
			Fl::add_timeout(0.1, showNoFileAlert, nullptr);
			return;
		}


		tmp = "\"" + WideToUTF8(line) + "\"";
	}

	card* crd = new card(tmp, inps::name->value());
	mens.mainWin->add(crd->get_body());

	cards.push_back(crd);
}

void card::open_file(Fl_Widget* w, void* data)
{
	string* st = (string*)data;

	string line = st->c_str();


	thread opening([line]()
		{
			try
			{
				int s = system(line.c_str());
				if (s != 0)
				{
					throw s;
				}
			}
			catch (int er)
			{
				Fl::add_timeout(0.1, ShowOpenErrorAlert, nullptr);
			}
			

		});
	opening.detach();
}


void card::del_card()
{
	for (short i = 0; i < cards.size(); i++)
	{
		if (cards[i]->cardBody == cardBody)
		{
			cards[i]->get_body()->parent()->remove(cards[i]->get_body());
				
		}
	}
}

void card::repos(int _x, int _y)
{
	x -= 110;
	if (x <= 0)
	{
		x = 560;
		y -= 60;

		cardBody->resize(x, y, 100, 50);

	}
	else
	{

		cardBody->resize(x, y, 100, 50);
	}

}


Fl_Button* card::get_body()
{
	return cardBody;
}

void card::cardBut::del()
{
	card::cardsCount -= 1;
	card::pos_minus();
	for (short i = 0; i < cards.size(); i++)
	{
		if (cards[i]->get_body() == this)
		{
			cards[i]->del_card();


			for (short j = i + 1; j < cards.size(); j++)
			{
				cards[j]->repos(1, 1);
			}

			cards.erase(cards.begin() + i);
			break;
		}
	}
}
