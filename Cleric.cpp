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
	this->max_mana = 5*magic;
	this->mana = max_mana;
}

Cleric::~Cleric()
{
}


int Cleric::getDamage()
{
	return this->magic;
}

bool Cleric::useAbility()
{
	if (this->mana >= CLERIC_ABILITY_COST)
	{
		int hitPointsIncrease = this->magic / 3;

		if (hitPointsIncrease < 1)
			hitPointsIncrease = 1;

		this->hitPoints += hitPointsIncrease;

		if (this->hitPoints > this->max_hitPoints)
			this->hitPoints = this->max_hitPoints;

		this->mana -= CLERIC_ABILITY_COST;

		return true;
	}
	return false;
}