#include "UpgradeRoom.h"
#include "iostream"
#include "Player.h"
#include <cstdio>
#include <fstream>

using namespace std;

UpgradeRoom::UpgradeRoom() { //constructor

}
UpgradeRoom::~UpgradeRoom() { //destructor

}

void UpgradeRoom::displayImage() {
	//Opens the monk image
	string line;
	ifstream myfile("upgrade.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}

}
void UpgradeRoom::play(Player *monkPtr, Monster *monsterPtr) {
	displayImage();

	string option; //Keeps track of option

	cout << "You have entered: Upgrade Room" << endl;
	cout << "[0] Upgrade health" << endl << "[1] upgrade attack" << endl;

	cin >> option;

	if (option == "0") {
		//upgrade max health
		//*monkMaxHealth += 5
		monkPtr->setMaxHealthPoints(monkPtr->getMaxHealthPoints() + 5);
		cout << "MAX HEALTH POINTS: " << monkPtr->getMaxHealthPoints() << endl; 
	}
	else if (option == "1") {
		//upgrade attack
		
		monkPtr->setAttackPoints(monkPtr->getAttackPoints() + 2);
		cout << "Max attack points increased by 2." << endl << "Attack Points: " << monkPtr->getAttackPoints() << endl;
	}
	else {
		cout << "invalid option" << endl;
	}

	system("pause");
	system("cls");

}

