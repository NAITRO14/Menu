#pragma once
#include "includes.h"

//класс для кнопок
class button : public Fl_Button
{
protected:
	Fl_Color base_color = fl_rgb_color(235, 235, 235);
	Fl_Color hover_color = fl_rgb_color(173, 173, 173);
	Fl_Color sel_color = fl_rgb_color(94, 94, 94);

public:
	button(int x, int y, int w, int h, const char* l) :
		Fl_Button(x, y, w, h, l)
	{
		visible_focus(0);
		color(base_color);
		selection_color(sel_color);
	}

	int handle(int event)
	{
		switch (event)
		{
		case FL_ENTER:
		{
			color(hover_color);
			redraw();
		}break;
		case FL_LEAVE:
		{
			color(base_color);
			redraw();
		}break;
		case FL_RELEASE:
		{
			color(base_color);
			redraw();
		}break;
		}
		return Fl_Button::handle(event);
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
		}break;
		case FL_LEAVE:
		{
			position(orgX, y());
			parent()->parent()->redraw();
		}break;
		case FL_RELEASE:
		{
			
			position(orgX, y());
			parent()->parent()->redraw();
			
		}break;
		}
		return button::handle(event);
	}
		
};

class folder_but : public button
{
private:
	int Y = y();
	int orgY = Y;
	Fl_Color selected_color = fl_rgb_color(255, 199, 59);
public:
	folder_but(int x, int y, int w, int h, const char* l) :
		button(x, y, w, h, l)
	{
		selection_color(fl_rgb_color(117, 182, 255));
	}


	int handle(int event) override
	{
		switch (event)
		{
		case FL_ENTER:
		{
			position(x(), Y - 5);
			parent()->parent()->redraw();
			return 1;
		}break;
		case FL_LEAVE:
		{
			position(x(), orgY);
			parent()->parent()->redraw();
			return 1;
		}break;
		case FL_RELEASE:
		{
			if (color() == base_color)
			{
				color(selected_color);
			}
			else
			{
				color(base_color);
			}
			parent()->parent()->redraw();
			return Fl_Button::handle(event);
		}break;
		}
		return button::handle(event);
	}

};
