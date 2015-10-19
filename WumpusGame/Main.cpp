#include <iostream>
#include "Header.h"

int main()
{
	Player player;
	player.currentRoom = 1;
	Enemy wumpus;
	wumpus.monsNum = 1;
	wumpus.currentRoom = 5;
	Enemy bat;
	bat.monsNum = 2;
	bat.currentRoom = 2;
	int pMovCh = 1;
	int pChoice = 0;
	int pFire = 0;

	wumpus.chkNearMonsters(player.currentRoom);
	bat.chkNearMonsters(player.currentRoom);

	std::cout << "There are 3 rooms in front of you" << std::endl;

	for (int i = 0; i < 3; ++i)
	{
		std::cout << rooms[player.currentRoom - 1][i] << std::endl;
	}

	std::cout << "Do you want to:" << std::endl << "1: Move" << std::endl << "2: Fire Arrow" << std::endl;

	switch (chkValidEntry(1, 2))
	{
	case 1:
		std::cout << "Which room would you like to move to?" << std::endl;
		std::cin >> pMovCh;
		player.move(pMovCh);
		break;
	case 2:
		std::cout << "Which room would you like to fire into?" << std::endl;
		std::cin >> pFire;
		player.fire(pFire, wumpus.currentRoom);
		break;
	}


	bat.monsAction(player.currentRoom);
	wumpus.monsAction(player.currentRoom);

	std::cout << wumpus.currentRoom << " & " << player.currentRoom << " & " << bat.currentRoom << std::endl;

	system("pause");
	return 0;

}