#pragma once
#include "includes.h"

struct helpData
{
	Fl_Input* path;
	Fl_Input* name;

	Fl_Box* alrt_path;
	Fl_Box* alrt_name;
	Fl_Box* alrt_NoFile;
};
extern helpData Data;

struct menues
{
	Fl_Group* newFile;
	Fl_Group* mainWin;

};
extern menues mens;

