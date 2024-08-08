#pragma once
#include "Entity.h"
#include <string>


class Player: public Entity
{

private:
	
	
	

public:
	
	Player();
	void die() const;
	Player(string, string, int, int, int, string);
	~Player();
};

