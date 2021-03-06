#include <iostream>
#include <time.h>
#include "Header.h"


//Checks if players choice of room is valid compared to
//their current location
int chkValidRoom(int pChoice, int curRm)
{
	for (int i = 0; i < 3; ++i)
	{
		if (rooms[curRm][i] == pChoice)
		{
			return true;
		}
	}
	std::cout << "Invalid Room Choice" << std::endl;
	return false;
}

//Requests user input and checks if its a valid number
int chkValidEntry(int min, int max)
{
	int choice;
	do
	{
		std::cout << "Enter a valid choice (" << min << "-" << max << "): ";
		std::cin >> choice;

		if (choice < min || choice > max)
		{
			std::cin.clear();
			std::cin.ignore(80, '\n');
			std::cout << "Invalid Entry." << std::endl;
		}
		else break;
	} while (true);
	return choice;
}

//Moves the player to the next room (currentRoom, pChoice)
void Player::move(int & a)
{
	if (chkValidRoom(a, currentRoom))
	{
		currentRoom = a;
	}
	else std::cout << "Invalid entry" << std::endl;
}

//Fires an arrow into the players choice of room
//checks if the player hits the wumpus
int Player::fire(int arrow, int mons)
{
	if (arrows > 0 && chkValidRoom(arrow, currentRoom))
	{
		if (arrow == mons)
		{
			std::cout << "Congratulations ";
			printFile();
			std::cout << " You got the Wumpus!" << std::endl;
			--arrows;
			return 1;
		}
		else std::cout << "Woops, you missed!" << std::endl;
		--arrows;
		if (arrows == 0)
		{
			std::cout << "You've run out of arrows! Try again after you restock!" << std::endl;
			return 1;
		}
		return 2;
	}

}

//Sets new enemy currentRoom (currentRoom)
void Enemy::move()
{
	srand(time(NULL));
	currentRoom = rand() % 20 + 1;
}

//Checks if the player is near a monster
void Enemy::chkNearMonsters(int pCur)
{
	bool success = false;

	for (int i = 0; i < 3; ++i)
	{
		if (rooms[pCur][i] == currentRoom) 
		{
			switch (monsNum)
			{
			case 1:
				std::cout << "You smell a wumpus!" << std::endl;
				break;
			case 2:
				std::cout << "You hear squeaking coming from nearby" << std::endl;
				break;
			case 3:
				std::cout << "You feel a slight breeze" << std::endl;
				break;
			}

			success = true;
		}
	}

	if (success == false)
	{
		switch (monsNum)
		{
		case 1:
			std::cout << "It smells like a cave" << std::endl;
			break;
		case 2:
			std::cout << "The room is quiet" << std::endl;
			break;
		case 3:
			std::cout << "The air is still" << std::endl;
			break;
		}
	}
}

//checks if the player is in the same room as monster and takes appropriate action
int Enemy::monsAction(int & pRoom)
{
	srand(0);
	if (currentRoom == pRoom)
	{
		switch (monsNum)
		{
		case 1:
			std::cout << "You've encountered the Wumpus!" << std::endl;
			break;
		case 2:
			std::cout << "You ran into the bat!! Bye Bye!!" << std::endl;
			pRoom = rand() % 20;
			move();
			std::cout << "You are now in " << pRoom << std::endl;
			system("pause");
			break;
		case 3:
			std::cout << "You've fallen in a pit! You lay there dying slowly" << std::endl;
			break;
		}
	}
	return false;
}