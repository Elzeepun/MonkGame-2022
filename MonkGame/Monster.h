#pragma once
#include "Entity.h"
#include <string>

class Monster: public Entity
{
public:
	Monster();
	~Monster();
	Monster(string, string, int, int, int, string);
	void die() const;


private:



};

