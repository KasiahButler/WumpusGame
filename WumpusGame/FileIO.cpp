#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include"Header.h"


//prints out the name of the player saved to the file
void printFile()
{


	std::fstream fin;
	fin.open("MyLog.txt", std::ios_base::out | std::ios_base::in);
	char input[128];
	while (fin.getline(input, 128))
	{
		std::cout << input;
		fin.close();
	}
}

//saves the player name to a file
void writeFile()
{
	std::fstream fout;
	fout.open("MyLog.txt", std::ios_base::out | std::ios_base::app);
	char input[128];

	if (fout.is_open())
	{
		std::cin.getline(input, 128);	// accepts user input and puts it into a buffer
		fout << input << std::endl;	// write to the file
		fout.flush();	// flush the write buffer, writing everything we haven't
		fout.close();	// close the file stream

	}
}

//clears the file so that a new name can be saved for a new game
void clearFile()
{
	std::fstream file;
	file.open("MyLog.txt", std::ios_base::out);
	if (file.is_open())
	{

	}
	file.close();
}