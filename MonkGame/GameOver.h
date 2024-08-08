#pragma once
#include "Room.h"
#include "Player.h"
#include "Monster.h"

class GameOver : public Room
{

public:
	GameOver();
	~GameOver();
	void play(Player *, Monster *);


};

