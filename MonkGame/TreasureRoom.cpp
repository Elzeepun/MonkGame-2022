#include "TreasureRoom.h"
#include <iostream>
#include <fstream>

using namespace std;

void TreasureRoom::play(Player * monkPtr, Monster * monsterPtr) {
	//displays treasure room
	string line;
	ifstream myfile("treasure.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}

	cout << "Congratulations!! You have found the treasure room!!" << endl;
	exit(0);
}




