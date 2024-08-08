#include "Room.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include "EmptyRoom.h"
#include "UpgradeRoom.h"
#include "MonsterRoom.h"

using std::vector;
using namespace std;


int Room::actionNumberGenerator() { 

	srand((unsigned)time(0)); //makes sure there's a different number every time the code runs. without it, num will always be the same.
	int randomNumber = rand(); //Set's random num every execution so num changes
	randomNumber = (rand() % 2) + 0; //Picks a random number between 0 and 1.
	//cout << randomNumber << endl; //Prints random number for test purposes

	return randomNumber;
}


void Room::play(Player *monkPtr, Monster *monsterPtr) {
	cout << "Play's room" << endl;

}



