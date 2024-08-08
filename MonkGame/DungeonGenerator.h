#pragma once
#include <algorithm>
#include <vector>
#include "Player.h"
#include "Monster.h"
#include "Room.h"
#include <Array>
using std::array;

class DungeonGenerator
{
private:
	//DungeonGenerator();

public:
	
	void dungeonGenerator(vector <Room*>&, int);
	int randomRoomGenerator();

	//ATTEMPT AT SINGLETON CLASS
	//DungeonGenerator(const DungeonGenerator&) = delete;
	//DungeonGenerator& operator = (const DungeonGenerator&) = delete;

	//static DungeonGenerator& Get() {

	//	static DungeonGenerator inst_random;
	//	return inst_random;
	//}
 /*
	void Seed() {
		srand(time(NULL));
	}

	int GenInt() {
		return rand() % 100;
	}
	*/

};

