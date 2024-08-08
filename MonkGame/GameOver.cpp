#include "GameOver.h"
#include <iostream>
#include <fstream>

using namespace std;


GameOver::GameOver() {
	//constructor
}

GameOver::~GameOver() {
	//destructor
}

void GameOver::play(Player * monkPtr, Monster * monsterPtr) {
	//end game

	string line;
	ifstream myfile("death.txt"); //displays skull ascii
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}

	cout << "GAME OVER" << endl;
	exit(0);
}