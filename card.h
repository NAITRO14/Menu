#pragma once
#include "alerts.h"
#include "converts.h"

//тут опианны классы и структуры

//скелет карточки
class card
{
private:
	//тело карточки
	class cardBut : public Fl_Button
	{
	public:
		cardBut(int x, int y, int w, int h, const char* l) :
			Fl_Button(x, y, w, h, l)
		{
			color(FL_GREEN);
			box(FL_UP_BOX);
			visible_focus(0);

		}

		void del();

		int handle(int event) override {
			if (event == FL_PUSH && Fl::event_button() == 3)
			{
				del();
				mens.mainWin->parent()->redraw();
				return 1;
			}
			return Fl_Button::handle(event);
		}


	};

	string path;
	string name;
	int x, y;

	cardBut* cardBody;
	static int posX, posY;
	static int cardsCount;
public:
	

	card(string p, string n);
	~card();

	static void pos_plus();
	static void pos_minus();

	string get_name();
	string get_path();

	static void createCard(Fl_Widget* w, void* data);
	static void open_file(Fl_Widget* w, void* data);

	void del_card();
	void repos(int _x, int _y);

	

	Fl_Button* get_body();
};

extern vector<card*> cards;


