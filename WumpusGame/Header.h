#pragma once

const int rooms[21][3]{ {0, 0, 0}, { 2, 5 ,8 },{ 1, 10, 3 },{ 2, 12, 4 },{ 2, 12, 4 },{ 3, 14, 5 },{ 4, 6, 1 },{ 5, 7, 15 },{ 6, 17, 8 },{ 7, 1, 9 },{ 8, 18, 10 },{ 9, 2, 11 },{ 10, 19, 12 },
{ 11, 3, 13 },{ 12, 20 ,14 },{ 14, 16, 6 },{ 20, 15, 17 },{ 16, 7, 18 },{ 17, 9, 19 },{ 18, 11, 20 },{ 19, 13, 16 } };

enum STATE {MENU, UPDATE, GAME, EXIT};

//checks if the players choice is a valid room in the rooms array
int chkValidRoom(int p, int c);
int chkValidEntry(int min, int max);
STATE mainMenu();
void upGame();
STATE mainGame();

void printFile();
void writeFile();
void clearFile();



class Player
{
public:
	int currentRoom = 1;
	int arrows = 3;

	//moves the player to a new room
	void move(int & a);
	//fires an arrow and checks to see if it hits the Wumpus
	int fire(int a, int b);
};

class Enemy
{
public:
	//Determines Monster Type (1 = Wump, 2 = Bat, 3 = Pit)
	int monsNum;
	int currentRoom;

	//Checks player location against currentRoom and outputs warning if needed
	void chkNearMonsters(int pCur);
	//Sets Obstacles room to a random room
	void move();
	//checks if player is in the same room as monster and takes appropriate action if true
	int monsAction(int & pRoom);
};

class gameState
{
	int pChoice;
	Player player;
	Enemy wumpus;
	Enemy bat;

public:
	STATE playGame();
	STATE mainGame();
};