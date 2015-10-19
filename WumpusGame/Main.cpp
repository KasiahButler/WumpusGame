#include <iostream>
#include "Header.h"

int main()
{
	Player player;
	Enemy wumpus;
	int pChoice = 1;

	player.move(pChoice);
	wumpus.move();

	std::cout << "There are 3 rooms in front of you, where would you like to move?" << std::endl;

	for (int i = 0; i < 3; ++i)
	{
		std::cout << rooms[player.currentRoom][i] << std::endl;
	}

	std::cin >> pChoice;
	if (chkValidRoom(pChoice, player.currentRoom))
	{
		player.move(pChoice);
	}

	std::cout << wumpus.currentRoom << " & " << player.currentRoom << std::endl;

	system("pause");
	return 0;

}