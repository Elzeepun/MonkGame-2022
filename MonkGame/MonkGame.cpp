// MonkGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "MonkGame.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"
#include "Room.h"
#include "Observer.h"
#include "MonsterRoom.h"
#include "TreasureRoom.h"
#include "UpgradeRoom.h"
#include "EmptyRoom.h"
#include "GameOver.h"
#include <vector>
#include "DungeonGenerator.h"

using namespace std;

MonkGame::MonkGame() {
    //constructor
}

MonkGame::~MonkGame() {
    //destructor
}


void MonkGame::printStartGame() {
    cout << "Welcome to this dungeon game" << endl;
    cout << "Please create a Monk character!" << endl;
    system("pause");
}

void MonkGame :: startGame(Player *monkPtr)
{
    string name; //name and description for monk
    string description;
    


    printStartGame();


    while (name.empty()){ //while name is empty, prompted to enter a name

        while (name.length() < 3) { //checks name has atleast 3 characters
            cout << "Name must contain at least 3 characters" << endl << "Enter name: ";
            getline(cin, name);
            if (name.length() < 3) {
                cout << "name must consist of atleast 3 characters!" << endl;
                system("cls");
            }
        }


        if (!name.empty()) {
            while (description.empty()) { //while description is empty, prompted to enter description
                cout << "Enter description: ";
                getline(cin, description);
                if (!description.empty()) {
                    //Player* player = new Player(name, description);//testing ints
                    monkPtr->setName(name);
                    monkPtr->setDescription(description);

                }
                else {
                    cout << "Description cannot be empty!" << endl;
                    system("pause");
                }
            }
           
        }
        else {
            cout << "Name cannot be empty!" << endl;
            system("pause");

        }
    }
   

}





int main()
{
    //initialize all relevant classes
    MonkGame MG;
    Player PL;
    MonsterRoom MR;
    UpgradeRoom UR;
    EmptyRoom ER;
    DungeonGenerator DG;
    vector<Room*> rooms; //vector that stores rooms. 
    
    DG.dungeonGenerator(rooms, 3); //generates 6 rooms to put in room vector
    

    //initialise monk
    Player monk("", "",3,15,15, "monk.txt"); 
    Player *monkPtr; //declaring pointer for monk
    monkPtr = &monk;

    //initialise monster
    Monster goblin("Goblin", "A monster guarding the dungeon", 2, 10, 10, "goblin.txt");
    Monster* goblinPtr;
    goblinPtr = &goblin;

    MG.startGame(monkPtr); //creates monk
   
    //Play rooms
    for (auto& Room : rooms) //iterate through rooms vector through it's pointers
    {
        Room->play(monkPtr, goblinPtr);
        delete Room; //delete room once used
    
    }
    if (monk.getHealthPoints() == 0)
    {
        GameOver  room; //create 
        room.play(monkPtr, goblinPtr);
    }
    else
    {
        TreasureRoom room;
        room.play(monkPtr, goblinPtr);
    }
    rooms.clear(); //clears room vector

    

}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
