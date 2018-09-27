#pragma once
#include "Fighter.h"
class Cleric :
	public Fighter
{
public:
	Cleric();
	Cleric(std::string name, std::string type, int max_hitpoints, int strength, int speed, int magic);
	~Cleric();
	int getDamage();
	bool useAbility();
};