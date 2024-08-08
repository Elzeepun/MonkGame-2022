#include "Player.h"
#include <iostream>
using namespace std;
 
Player::Player() { //Default constructor

}
Player::Player(string n, string d, int m, int h, int k, string i) {
	name = n;
	description = d;
	attackPoints = m;
	healthPoints = h;
	maxHealthPoints = k;
	imageFile = i;
}

Player::~Player() {
	//destructor
}


void Player::die() const
{
	cout << "player is dead" << endl;
}


