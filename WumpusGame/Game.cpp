#include <iostream>
#include "Header.h"

STATE mainMenu()
{
	int choice = 0;

	system("cls");
	std::cout << "      Welcome to Hunt the Wumpus!       " << std::endl;
	std::cout << "A Text game by SniperCorgii Productions!" << std::endl;
	std::cout << "1: Play" << std::endl;
	std::cout << "2: Exit" << std::endl;
	choice = chkValidEntry(1, 2);
	if (choice == 1)
	{
		return UPDATE;
	}
	else if (choice == 2)
	{
		return EXIT;
	}
	else return MENU;

}

void upGame()
{
	Player player;
	Enemy wumpus;
	Enemy bat;

	int pChoice = 0;

	player.currentRoom = 1;
	wumpus.move();
	bat.move();

	system("cls");

	std::cout << wumpus.currentRoom << bat.currentRoom << std::endl;

	wumpus.chkNearMonsters(player.currentRoom);
	bat.chkNearMonsters(player.currentRoom);

	std::cout << "There are 3 Tunnels leading from this cave" << std::endl;
	std::cout << "Would you like to \n1:Fire\n2:Move"         << std::endl;
	switch (chkValidEntry(1, 2))
	{
	case 1:
		std::cout << "Choose a room to fire into!" << std::endl;

		for (int i = 0; i < 3; ++i)
		{
			std::cout << rooms[player.currentRoom - 1][i] << std::endl;
		}

		std::cin >> pChoice;
		player.fire(pChoice, wumpus.currentRoom);
		std::cout << player.currentRoom << " & " << player.arrows << std::endl;
		std::cout << wumpus.currentRoom << " & " << bat.currentRoom << std::endl;
		system("pause");
		break;

	case 2:
		std::cout << "Choose a room to move to!" << std::endl;

		for (int i = 0; i < 3; ++i)
		{
			std::cout << rooms[player.currentRoom - 1][i] << std::endl;
		}

		std::cin >> pChoice;
		player.move(pChoice);
		std::cout << player.currentRoom << " & " << player.arrows << std::endl;
		std::cout << wumpus.currentRoom << " & " << bat.currentRoom << std::endl;
		system("pause");
		break;
	}
	wumpus.monsAction(player.currentRoom);
	bat.monsAction(player.currentRoom);
}

STATE mainGame()
{
	return EXIT;
}