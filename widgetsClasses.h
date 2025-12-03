#pragma once
#include "includes.h"

//класс для кнопок
class button : public Fl_Button
{
public:
	button(int x, int y, int w, int h, const char* l) :
		Fl_Button(x, y, w, h, l)
	{
		visible_focus(0);
		color(fl_rgb_color(235, 230, 230));
		selection_color(fl_rgb_color(94, 94, 94));
	}
};

//класс для виджктов предупреждений
class al_box : public Fl_Box
{
public:
	al_box(int x, int y, int w, int h, const char* l) :
		Fl_Box(x, y, w, h, l)
	{
		labelsize(20);
		box(FL_UP_BOX);
		color(fl_rgb_color(222, 47, 47));
		hide();
	}
};

class plus_button : public button
{
private:
	int X = x();
	int orgX = X;
public:
	plus_button(int x, int y, int w, int h, const char* l) :
		button(x, y, w, h, l)
	{

	}


	int handle(int event) override
	{
		switch (event)
		{
		case FL_ENTER:
		{
			position(X - 20, y());
			parent()->parent()->redraw();
			return 1;
		}break;
		case FL_LEAVE:
		{
			position(orgX, y());
			parent()->parent()->redraw();
			return 1;
		}break;
		case FL_RELEASE:
		{
			position(orgX, y());
			parent()->parent()->redraw();

			button::handle(event);
		}break;
		}
		return button::handle(event);
	}
		
};
