#pragma once
#include "structs.h"

//====================================
//алерты
inline void hidePathAlert(void* data)
{
	Data.alrt_path->hide();
}
inline void showPathAlert(void* data)
{
	Data.alrt_path->show();
	Fl::add_timeout(3, hidePathAlert, nullptr);
}


inline void hideNameAlert(void* data)
{
	Data.alrt_name->hide();
}

inline void showNameAlert(void* data)
{
	Data.alrt_name->show();
	Fl::add_timeout(3, hideNameAlert, nullptr);
}


inline void hideNoFileAlert(void* data)
{
	Data.alrt_NoFile->hide();
}

inline void showNoFileAlert(void* data)
{
	Data.alrt_NoFile->show();
	Fl::add_timeout(3, hideNoFileAlert, nullptr);
}


inline void HideAlreadyHere(void* data)
{
	Data.alrt_alreadyHave->hide();
}

inline void ShowAlreadyHere(void* data)
{
	Data.alrt_alreadyHave->show();
	Fl::add_timeout(3, HideAlreadyHere, nullptr);
}


inline void HideOpenErrorAlert(void* data)
{
	Data.alrt_operErr->hide();
}

inline void ShowOpenErrorAlert(void* data)
{
	Data.alrt_operErr->show();
	Fl::add_timeout(3, HideOpenErrorAlert, nullptr);
}

//алерты
//====================================
