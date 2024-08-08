#include "Monster.h"

Monster::Monster() { //constructor

}

Monster::~Monster() { //destructor

}

Monster::Monster(string n, string d, int a, int r, int h, string i) {
	name = n;
	description = d;
	attackPoints = a;
	healthPoints = r;
	maxHealthPoints = h;
	imageFile = i;
}

void Monster::die() const {


}