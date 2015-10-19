#pragma once

const int rooms[20][3]{ { 2, 5 ,8 },{ 1, 10, 3 },{ 2, 12, 4 },{ 2, 12, 4 },{ 3, 14, 5 },{ 4, 6, 1 },{ 5, 7, 15 },{ 6, 17, 8 },{ 7, 1, 9 },{ 8, 18, 10 },{ 9, 2, 11 },{ 10, 19, 12 },
{ 11, 3, 13 },{ 12, 20 ,14 },{ 14, 16, 6 },{ 20, 15, 17 },{ 16, 7, 18 },{ 17, 9, 19 },{ 18, 11, 20 },{ 19, 13, 16 } };

int chkValidRoom(int & p, int & c);

class Player
{
public:
	int currentRoom = 1;
	int arrows = 3;

	void move(int & a);
	void fire(int & a, int & b);
};

class Enemy
{
public:
	int currentRoom;

	void move();
};