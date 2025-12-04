#pragma once
#include "widgetsClasses.h"

//struct helpData
//{
//	short mode;
//
//	Fl_Input* path;
//	Fl_Input* name;
//
//	al_box* alrt_path;
//	al_box* alrt_name;
//	al_box* alrt_NoFile;
//	al_box* alrt_alreadyHave;
//	al_box* alrt_operErr;
//};
//extern helpData Data;

namespace inps
{
	extern Fl_Input* path;
	extern Fl_Input* name;
}

namespace alrts
{
	extern al_box* alrt_path;
	extern al_box* alrt_name;
	extern al_box* alrt_NoFile;
	extern al_box* alrt_alreadyHave;
	extern al_box* alrt_operErr;
}

struct menues
{
	Fl_Group* newFile;
	Fl_Group* mainWin;

};
extern menues mens;

