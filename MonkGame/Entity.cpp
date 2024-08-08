#include "Entity.h"
#include "string"
#include "iostream"

Entity::Entity(const string& newname, const string& newdescription, int hp, int mhp, int ap) {

	name = newname;
	description = newdescription;
	healthPoints = hp;
	maxHealthPoints = mhp;
	attackPoints = ap;

}


Entity::~Entity() {
	//destructer deletes memory allocation

}



//SETTERS
void Entity::setName(string n) {
	name = n;
}

void Entity::setDescription(string d) {
	description = d;
}

void Entity::setHealthPoints(int h) {
	healthPoints = h;
}

void Entity::setMaxHealthPoints(int h) {
	maxHealthPoints = h;
}

void Entity::setAttackPoints(int a) {
	attackPoints = a;
}

void Entity::setImageFile(string a) {
	imageFile = a;
}



//GETTERS
string Entity::getName() const {
	return name;
}

string Entity::getDescription() const {
	return description;
}

int Entity::getHealthPoints() {
	return healthPoints;
}

int Entity::getMaxHealthPoints() const {
	return maxHealthPoints;
}

int Entity::getAttackPoints() const {
	return attackPoints;
}

string Entity::getImageFile() const {
	return imageFile;
}

