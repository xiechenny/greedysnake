#include "printer.hpp"
#include <curses.h>

void CursesPrinter::init()
{
	initscr();
};

int CursesPrinter::getKey()
{
	char key;
	key = getch();
	return key;
};
