#include "Header.h"
vector<card*> cards;

inline void open_file(Fl_Widget* w, void* data)
{
	string* st = (string*)data;

	string line = st->c_str();

	thread opening([line]() {system(line.c_str()); });
	opening.detach();
}

card::card(string p, string n)
{
	path = p;
	name = n;
	cardsCount += 1;

	x = posX;
	y = posY;

	pos_plus();

	cardBody = new cardBut(x, y, 100, 50, name.c_str());
	cardBody->callback(open_file, &path);

	
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

void card::change_pos()
{
	cardBody->resize(x, y + 50, 100, 50);
}

void card::del_card()
{
	for (short i = 0; i < cards.size(); i++)
	{
		if (cards[i]->cardBody == cardBody)
		{
			cards[i]->get_body()->parent()->remove(cards[i]->get_body());

			/*for (short j = i; j < cards.size() - 1; j++)
			{
				cards[j] = cards[j + 1];
				cards.pop_back();
			}*/
				
		}
	}
}

void card::repos(int _x, int _y)
{
	cardBody->resize(_x, _y, 100, 50);
}

Fl_Button* card::get_body()
{
	return cardBody;
}

void cardBut::del()
{

	card::cardsCount -= 1;
	card::pos_minus();
	for (short i = 0; i < cards.size(); i++)
	{
		if (cards[i]->get_body() == this)
		{
			cards[i]->del_card();
			

			for (short j = i+1; j < cards.size(); j++)
			{	
				short _x = cards[j]->x;
				short _y = cards[j]->y;

				_x -= 110;
				if (_x <= 0)
				{
					_x = 560;
					cards[j]->x = 560;
					cards[j]->y -= 60;

					_y -= 60;

					cards[j]->repos(_x, _y);

				}
				else
				{
					cards[j]->x -= 110;

					cards[j]->repos(_x, _y);
				}

			}

			


			cards.erase(cards.begin() + i);
			break;
		}
	}
}
