#pragma once
#include "includes.h"
#include "widgetsClasses.h"

struct helpData
{
	Fl_Input* path;
	Fl_Input* name;

	al_box* alrt_path;
	al_box* alrt_name;
	al_box* alrt_NoFile;
	al_box* alrt_operErr;
};
extern helpData Data;

struct menues
{
	Fl_Group* newFile;
	Fl_Group* mainWin;

};
extern menues mens;

