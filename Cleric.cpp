#include "Cleric.h"



Cleric::Cleric()
{
}

Cleric::Cleric(std::string name, std::string type, int max_hitPoints, int strength, int speed, int magic)
{
	//cout << endl << "ABUDABI BODABI BODO: " << max_hitPoints << endl;
	this->name = name;
	this->max_hitPoints = max_hitPoints;
	this->hitPoints = max_hitPoints;
	this->strength = strength;
	this->max_speed = speed;
	this->speed = speed;
	this->magic = magic;
}

Cleric::~Cleric()
{
}


int Cleric::getDamage()
{
	return magic;
}
bool Cleric::useAbility()
{
	if (mana >= CLERIC_ABILITY_COST)
	{
		int hitPointsIncrease = magic / 3;

		if (hitPointsIncrease < 1)
			hitPointsIncrease = 1;

		hitPoints += hitPointsIncrease;

		if (hitPoints > max_hitPoints)
			hitPoints = max_hitPoints;

		mana -= CLERIC_ABILITY_COST;

		return true;
	}
	return false;
}