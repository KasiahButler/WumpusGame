#include <iostream>
#include <time.h>
#include "Header.h"

//Moves the player to the next room (currentRoom, pChoice)
void Player::move(int & a)
{
	if (chkValidRoom(a, currentRoom))
	{
		currentRoom = a;
	}
}

//Fires an arrow into the players choice of room
//checks if the player hits the wumpus
void Player::fire(int a, int b)
{
	if (arrows > 0 && chkValidRoom(a, currentRoom))
	{
		if (a == b)
		{
			std::cout << "You got the wumpus! Congratulations!" << std::endl;
		}
		else std::cout << "Woops, you missed!" << std::endl;
	}
}

//Sets new enemy currentRoom (currentRoom)
void Enemy::move()
{
	srand(time(NULL));
	currentRoom = rand() % 20 + 1;
}

//Checks monster type and outputs warning message if nearby
void Enemy::warnMons()
{
	switch (monsNum)
	{
	case 1:
		std::cout << "You smell a wumpus!" << std::endl;
		break;
	case 2:
		std::cout << "You feel a breeze" << std::endl;
		break;
	case 3:
		std::cout << "You hear squeaking" << std::endl;
		break;
	}
}

//Checks if players choice of room is valid compared to
//their current location
int chkValidRoom(int pChoice, int curRm)
{
	for (int i = 0; i < 3; ++i)
	{
		if (rooms[curRm - 1][i] == pChoice)
		{
			std::cout << "That is valid" << std::endl;
			return true;
		}
	}
	std::cout << "Entry is invalid" << std::endl;
	return false;
}

//Checks if the player is near a monster
int Enemy::chkNearMonsters(int pCur)
{
	for (int i = 0; i < 3; ++i)
	{
		if (rooms[pCur - 1][i] == currentRoom) { warnMons(); return true; }
	}
	std::cout << "All is quiet" << std::endl;
	return false;
}