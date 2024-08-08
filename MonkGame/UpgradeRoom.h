#pragma once
#include "Player.h"
#include "Room.h"
#include <string>




class UpgradeRoom : public Room
{
	

private:
	

public:
	void play(Player*, Monster*) override;
	void displayImage();
	UpgradeRoom();
	~UpgradeRoom();
};

