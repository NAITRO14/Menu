#pragma once
#include "includes.h"
//тут опианны классы и структуры

class card;
extern vector<card*> cards;

struct helpData
{
	Fl_Input* path;
	Fl_Input* name;
};
extern helpData Data;



struct menues
{
	Fl_Group* newFile;
	Fl_Group* mainWin;

};
extern menues mens;


class cardBut : public Fl_Button
{
public:
	cardBut(int x, int y, int w, int h, const char* l):
		Fl_Button(x, y, w, h, l) 
	{
		color(FL_GREEN);
		box(FL_UP_BOX);
		
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
	friend class card;


};

class card
{
	string path;
	string name;
	

	cardBut* cardBody;
	
	

public:
	int x, y;
	static int posX, posY;
	static int cardsCount;
	card(string p, string n);
	~card();

	void pos_plus();
	static void pos_minus();

	string get_name();
	string get_path();
	void change_pos();
	void del_card();
	void repos(int _x, int _y);

	Fl_Button* get_body();
};



