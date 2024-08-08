#pragma once
#ifndef MONKGAME_H //Prevents code from being defined twice.
#define MONKGAME_H
#include "Player.h"

class MonkGame
{
private:
	

public:
	MonkGame();
	~MonkGame();

	void startGame(Player *);
	void printStartGame();
	


};

#endif /*MONKGAME_H_*/