#include <iostream>
#include "Header.h"

int main()
{
	STATE current = MENU;
	gameState game;

	while (true)
	{
		switch (current)
		{
		case MENU: current = mainMenu(); break;
		case UPDATE: game.playGame();
		case GAME: current = game.mainGame(); break;
		case EXIT: clearFile();  return false;
		}
	}
}