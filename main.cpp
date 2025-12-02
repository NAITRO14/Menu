#include "includes.h"
#include "Header.h"
#include "widgets.h"

int card::posX = 10;
int card::posY = 10;

int main(int argc, char* argv[])
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	Fl_Double_Window* win = new Fl_Double_Window(800, 600, "win");

	newFile();

	mainWin();
	alertsBoxes();

	win->end();
	win->show(argc, argv);
	return Fl::run();
}