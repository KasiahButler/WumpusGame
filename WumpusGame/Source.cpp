#include <iostream>
#include <time.h>
#include "Header.h"

int chkValidRoom(int & p, int & c)
{
	for (int i = 0; i < 3; ++i)
	{
		if (rooms[c][i] == p) 
		{
			std::cout << "That is valid" << std::endl;
			return true; 
		}
	}
	std::cout << "Entery is invalid" << std::endl;
	return false;
}

//Moves the player to the next room (currentRoom, pChoice)
void Player::move(int & a)
{
	currentRoom = a;
}

//Fires an arrow into the players choice of room
//checks if the player hits the wumpus
void Player::fire(int & a, int & b)
{
	if (arrows > 0 && chkValidRoom(currentRoom, a))
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