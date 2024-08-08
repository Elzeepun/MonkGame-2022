#include "DungeonGenerator.h"
#include "Room.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include "EmptyRoom.h"
#include "UpgradeRoom.h"
#include "MonsterRoom.h"
 
using namespace std;



int DungeonGenerator::randomRoomGenerator() { 
	
	srand((unsigned)time(0) + rand()); //makes sure there's a different number every time the code runs. without it, num will always be the same.
	int randomNumber = rand(); //Set's random num every execution so num changes
	randomNumber = (rand() % 3) + 1; //Picks a random number between .
	return randomNumber;
	
	
}


void DungeonGenerator::dungeonGenerator(vector <Room*>& roomVector, int numOfRooms) { 
	//random order then push back at end of each room/iterate through vector

	//For prototype purposes
    roomVector.push_back(new MonsterRoom()); //Starts with a monster room
	roomVector.push_back(new EmptyRoom()); //Atleast 1 empty room
	roomVector.push_back(new UpgradeRoom()); //Atleast 1 upgrade room

	for (int i = 0; i < numOfRooms; ++i) { //iterates through number of rooms required and pushes new room to vector
		

		if (randomRoomGenerator() == 1) {
			roomVector.push_back(new EmptyRoom()); //Add empty room
			//cout << "added empty room" << endl; //TESTING PURPOSES
			
		}
		else if (randomRoomGenerator() == 2) {
			roomVector.push_back(new UpgradeRoom()); //Add upgrade room
			//cout << "added upgrade room" << endl; //TESTING PURPOSES
			
		
		}
		else if (randomRoomGenerator() == 3) {
			roomVector.push_back(new MonsterRoom()); //Add monster Room
			//cout << "added monster room" << endl; //TESTING PURPOSES
			
			
		}


		roomVector.push_back(new MonsterRoom()); //Atleast 2 monster rooms
		

	}
 

}