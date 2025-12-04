#pragma once
#include "widgetsClasses.h"

namespace Data
{
	extern short mode;
}

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

	Fl_Box* T;

};
extern menues mens;

