#include "EmptyRoom.h"
#include "iostream"
#include "Player.h"
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;


EmptyRoom::EmptyRoom() {
	//constructor
}

EmptyRoom::~EmptyRoom() {
	//destructor
}

void EmptyRoom::displayScreen() {

	//Opens the monk image
	string line;
	ifstream myfile("pray.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}

}

void EmptyRoom::play(Player* monkPtr, Monster * monsterPtr) {
	//can pray
	displayScreen();
	cout << "Entered room: Empty Room" << endl << "Would you like to pray and restore your health?" << endl;
	cout << "[0]Yes" << endl << "[1]No" << endl;
	
	string option;
	cin >> option;

	if (option == "0") {
		//Pray
		monkPtr->setHealthPoints(monkPtr->getMaxHealthPoints());
		cout << "Health recovered: " << monkPtr->getHealthPoints() << endl;
		system("pause");
	}
	else if (option == "1") {
		//don't pray and move on
		cout << "Decided not to pray" << endl;
		system("pause");
		
	}
	else {
		cout << "Invalid Option... Decided not to pray" << endl;

	}
	//clear console
	system("cls");
	return;
}