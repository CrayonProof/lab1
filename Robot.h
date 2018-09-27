#pragma once
#include "Fighter.h"
class Robot :
	public Fighter
{
public:
	Robot();
	Robot(std::string name, std::string type, int max_hitpoints, int strength, int speed, int magic);
	int getDamage();
	bool useAbility();
	~Robot();
};

