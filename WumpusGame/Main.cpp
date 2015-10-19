#include <iostream>
#include "Header.h"

int main()
{
	Player player;
	Enemy wumpus;
	wumpus.monsNum = 1;
	int pMovCh = 1;
	player.currentRoom = 1;
	wumpus.currentRoom = 5;

	wumpus.chkNearMonsters(player.currentRoom);

	std::cout << "There are 3 rooms in front of you, where would you like to move?" << std::endl;

	for (int i = 0; i < 3; ++i)
	{
		std::cout << rooms[player.currentRoom - 1][i] << std::endl;
	}

	std::cin >> pMovCh;
	player.move(pMovCh);

	wumpus.warnMons();

	std::cout << wumpus.currentRoom << " & " << player.currentRoom << std::endl;

	system("pause");
	return 0;

}