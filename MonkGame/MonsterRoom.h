#pragma once
#include "Room.h"
#include "Player.h"
#include "Monster.h"

class MonsterRoom: public Room
{
	
public:
	MonsterRoom();
	~MonsterRoom();
	void play(Player *, Monster *) override;
	void printAction(int);
	void monsterScreen(Player *, Monster *);
	void monkScreen(Player*, Monster*);
	int monsterType; //each monstser is assigned a number when generated
private:
	
};

