#include <iostream>
#include "Header.h"

int main()
{
	STATE current = MENU;

	while (true)
	{
		switch (current)
		{
		case MENU: current = mainMenu(); break;
		case UPDATE: upGame();
		case GAME: current = mainGame(); break;
		case EXIT: return false;
		}
	}
}