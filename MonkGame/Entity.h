#pragma once

#ifndef ENTITY_H_
#define ENTITY_H_
#include <string>

using namespace std;


class Entity
{
public:
	Entity() = default;
	Entity(const string& newname, const string& newdescription, int hp, int mhp, int ap);
	~Entity();

	void setName(const string); 
	string getName() const;

	void setDescription(const string);
	string getDescription() const;

	void setHealthPoints(int);
	int getHealthPoints();


	void setMaxHealthPoints(int);
	int getMaxHealthPoints() const;

	void setAttackPoints(int);
	int getAttackPoints() const;
	
	void setImageFile(string);
	string getImageFile() const;


	virtual void die()  const = 0;

	

protected:
	string name;
	string description;
	string imageFile;
	int healthPoints;
	int maxHealthPoints;
	int attackPoints;
	


};



#endif /*ENTITY_H_*/