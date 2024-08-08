#pragma once
#include <algorithm>
#include <vector>
#include "Player.h"
#include "Monster.h"

using std::vector;

class Room
{
protected:



public:
	void dungeonGenerator( vector <Room*> &, int);
	int actionNumberGenerator();
	int randomRoomGenerator();
	virtual void play(Player *, Monster *) = 0;
	
};

