#include <iostream>
#include "Header.h"
#include <string>
#include <cstring>
#include <sstream>


//Provides a main menu that allows the player to enter name and choose to play or 
//exit
STATE mainMenu()
{
	int choice = 0;
	
	std::cout << "      Welcome to Hunt the Wumpus!      " << std::endl;
	std::cout << "A Text game by CodeCorgii Productions! " << std::endl;
	std::cout << "        Please enter your name!        " << std::endl;
	std::cout << "        ";
	writeFile();
	std::cout << "        " << std::endl;


	system("cls");
	std::cout << "Now pick what you'd like to do ";
	printFile();
	std::cout << std::endl;
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

//sets the starting numbers for the player, wumpus, and bat
STATE gameState::playGame()
{
	system("cls");

	int pChoice = 0;

	player.currentRoom = 1;
	wumpus.monsNum = 1;
	wumpus.currentRoom = 8;
	bat.monsNum = 2;
	bat.currentRoom = 15;
	return GAME;
}

//loops through letting the player move through the cave system and fire
//exits if the player hits the wumpus, runs out of arrows, or dies;
STATE gameState::mainGame()
{

	system("cls");

	std::cout << "You are in room : " << player.currentRoom << std::endl;
	std::cout << std::endl;
	std::cout << "Information:" << std::endl;
	wumpus.chkNearMonsters(player.currentRoom);
	bat.chkNearMonsters(player.currentRoom);
	std::cout << std::endl;

	std::cout << "There are 3 Tunnels leading from this cave" << std::endl;
	std::cout << "Would you like to \n1:Fire\n2:Move"         << std::endl;

	switch (chkValidEntry(1, 2))
	{
	case 1:
		std::cout << std::endl;
		std::cout << "Choose a room to fire into!" << std::endl;

		for (int i = 0; i < 3; ++i)
		{
			std::cout << rooms[player.currentRoom][i] << ": ";
		}

		std::cin >> pChoice;
		if (player.fire(pChoice, wumpus.currentRoom) == 1)
		{
			system("pause");
			return EXIT;
		}
		else if (player.fire(pChoice, wumpus.currentRoom) == 2)
		{
			system("pause");
			return GAME;
		}
		system("pause");
		break;

	case 2:
		std::cout << std::endl;
		std::cout << "Choose a room to move to!" << std::endl;

		for (int i = 0; i < 3; ++i)
		{
			std::cout << rooms[player.currentRoom][i] << ": ";
		}

		std::cin >> pChoice;
		player.move(pChoice);
		system("pause");
		break;
	}
	wumpus.monsAction(player.currentRoom);
	bat.monsAction(player.currentRoom);

	if (player.currentRoom == wumpus.currentRoom)
	{
		std::cout << "Oh no the Wumpus ate you!" << std::endl;
		printFile();
		std::cout << " Has fallen in battle" << std::endl;
		system("pause");
		return EXIT;
	}
	return GAME;
}