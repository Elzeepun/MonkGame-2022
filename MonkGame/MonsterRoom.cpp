#include "MonsterRoom.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Player.h"
#include "Monster.h"
#include "GameOver.h"
#include <cstdio>

using namespace std;

MonsterRoom::MonsterRoom() { //constuctor

}

MonsterRoom::~MonsterRoom() {
	//Destructor
}

void MonsterRoom::monsterScreen(Player * monkPtr, Monster * monsterPtr) { //display's monster ASCII
	//references for health points
	int monkHealth = monkPtr->getHealthPoints();
	int monkMaxHealth = monkPtr->getMaxHealthPoints();
	int monsterHealth = monsterPtr->getHealthPoints();
	int monsterMaxHealth = monsterPtr->getMaxHealthPoints();
	

	 //Opens the monster image
	string line;
	ifstream myfile(monsterPtr->getImageFile());
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}
	cout << endl << "Name: " << monkPtr->getName() << " | Health:" << monkHealth << "/" << monkMaxHealth;
	cout << " | Attack: " << monkPtr->getAttackPoints();
	cout << " || Monster: " << monsterPtr->getName() << " | Health: " << monsterHealth << "/" << monsterMaxHealth;
	cout << " | Attack: " << monsterPtr->getAttackPoints() << endl;

}

void MonsterRoom::monkScreen(Player * monkPtr, Monster *monsterPtr){
	//references for healthpoints
	int monkHealth = monkPtr->getHealthPoints();
	int monkMaxHealth = monkPtr->getMaxHealthPoints();
	int monsterHealth = monsterPtr->getHealthPoints();
	int monsterMaxHealth = monsterPtr->getMaxHealthPoints();

	//Opens the monk image
	string line;
	ifstream myfile(monkPtr->getImageFile());
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}
	//Display stats
	cout << endl << "Name: " << monkPtr->getName() << " | Health:" << monkHealth << "/" << monkMaxHealth;
	cout << " | Attack: " << monkPtr->getAttackPoints();
	cout << " || Monster: " << monsterPtr->getName() << " | Health: " << monsterHealth << "/" << monsterMaxHealth;
	cout << " | Attack: " << monsterPtr->getAttackPoints() << endl;


}


void MonsterRoom::printAction(int turn)
{
	
	//Peints monster and monk rturns
	if (turn == 0) {
		cout << "Monk's turn" << endl;
		cout << "[1] Attack" << endl << "[2] Defend" << endl;
	}

	else if (turn == 1) {
		cout << "Monster's turn" << endl;
	}
	else {
		cout << "Invalid" << endl;
	}
	
}

/*
Turn 0 = Monk
Turn 1 = Monster

Attack 0 = successful
Attack 1 = Failed
*/


void MonsterRoom::play(Player *monkPtr, Monster *monsterPtr)
{ 
	GameOver GO;
	//references for getters.
	int monsterHealth = monsterPtr->getHealthPoints();
	int monkHealth = monkPtr->getHealthPoints();
	int monsterAttack = monsterPtr->getAttackPoints();
	int monkAttack = monkPtr->getAttackPoints();
	string monkName = monkPtr->getName();
	string monsterName = monsterPtr->getName();

	

	string nextStep; //Keeps track of user input
	int turn = 0;

	system("cls");
	cout << monkPtr->getName() << " has entered a Monster room" << endl;
	system("pause");

	do {
		//Monk's turn
		if (turn == 0) {
			//print actions
			system("cls");
			monkScreen(monkPtr, monsterPtr);
			printAction(turn);
			cin >> nextStep;
			//ATTACK
			if (nextStep == "1") { //if input is 1 - attack
				//randomnumber generator to determine wether successful
				if (actionNumberGenerator() == 0) {
					cout << "attack successful" << endl;
					monsterPtr->setHealthPoints(monsterPtr->getHealthPoints() - monkPtr->getAttackPoints()); //change monster pointer
					cout << monkName << " did " << monkAttack << " damage to " << monsterName << endl; //print healthpoints
					system("pause");
					turn = 1;
				}
				else {
					cout << "attack failed" << endl; //attack fails
					turn = 1;
					system("pause");
				}

			}//DEFEND
			if (nextStep == "2") { //if input is 2 - DEFEND
				//randomnumber generator to determine wether successful
				if (actionNumberGenerator() == 0) {
					cout << "defence successful" << endl;
					if (monkPtr->getHealthPoints() == monkPtr->getMaxHealthPoints()) { //If health is max, do nothing
						cout << "Monk Health already full" << monkPtr->getHealthPoints() << endl;
						system("pause");
						turn = 1;
					}
					else {
						monkPtr->setHealthPoints(monkPtr->getHealthPoints() + 1); 
						cout << monkName << "'s health increased by 1" << endl;
						system("pause");
						turn = 1;
					}
				}
				else {
					cout << "defence failed" << endl;
					turn = 1;
					system("pause");
				}
			}
		}

		//Monster's turn
		else if (turn == 1) {
			//print actions	
			system("cls");
			monsterScreen(monkPtr, monsterPtr);
			printAction(turn);
			if (actionNumberGenerator() == 0) { //if number is 0 then attack
				if (actionNumberGenerator() == 0) {//attack successful
					cout << "Monster decided to attack" << endl;
					cout << "Attack Successful" << endl;
					monkHealth -= monsterAttack;  
					monkPtr->setHealthPoints(monkHealth);
					cout << monsterName << " did " << monsterAttack << " damage to " << monkName << endl;
					turn = 0;
					system("pause");

				}
				else {
					cout << "Attack unsuccessful";
					turn = 0;
					system("pause");

				}
			}
			else { //DEFENCE
				if (actionNumberGenerator() == 1) {
					cout << "Monster decided to defend" << endl;
					cout << "defence Successful." << endl;
					if (monsterPtr->getHealthPoints() == monsterPtr->getMaxHealthPoints()) {
						cout << "Monster Health already full " << monsterPtr->getHealthPoints() << endl;
						turn = 0;
						system("pause");
					}
					else {
						monsterPtr->setHealthPoints(monsterPtr->getHealthPoints() + 1); 
						cout << "Monster's Health increased by 1 " << endl;
						turn = 0;
						system("pause");
					}


				}
				else {
					cout << "Monster decided to defend" << endl;
					cout << "Defence unsuccessful..." << endl;
					turn = 0;
					system("pause");

				}

			}
		}
	}while (monsterPtr->getHealthPoints() > 0 && monkPtr->getHealthPoints() > 0);

	if (monsterPtr->getHealthPoints() < 1) { 
					
		system("cls");
		cout << "Monster has been defeated!" << endl;
		system("pause");
		system("cls");
		monsterPtr->setHealthPoints(monsterPtr->getMaxHealthPoints()); //Resets health points, as I was unable to make new monsters
		return;
	}
	else if (monkPtr->getHealthPoints() < 1) {
					//Game over		
		system("cls");
		cout << monkName << " has been defeated..." << endl;
		system("pause");
		system("cls");
		GO.play(monkPtr, monsterPtr);
		return;
	}
}

