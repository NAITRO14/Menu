#include "widgets.h"

int card::posX = 10;
int card::posY = 10;

int main(int argc, char* argv[])
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	try
	{
		Fl_Double_Window* win = new Fl_Double_Window(800, 600, "win");

		alertsBoxes();

		newFile();

		mainWin();


		win->end();
		win->show(argc, argv);
		return Fl::run();
	}
	catch (...)
	{
		cout << "Возникла непредвиденная ошибка" << endl;
		exit(0);
	}
	
}