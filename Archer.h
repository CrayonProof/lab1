#pragma once
#include "Fighter.h"
class Archer :
	public Fighter
{
public:
	Archer();
	Archer(std::string name, std::string type, int max_hitpoints, int strength, int speed, int magic);
	~Archer();
	int getDamage();
	bool useAbility();
};