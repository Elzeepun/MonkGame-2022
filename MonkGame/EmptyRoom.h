#pragma once
#include "Room.h"
#include "Player.h"
#include "Monster.h"

class EmptyRoom: public Room
{

public: 
	EmptyRoom();
	~EmptyRoom();

	
	void play(Player *, Monster *) override;
	void displayScreen();
};

