#include "Fighter.h"

string name, stringType;
int type, hitPoints, strength, speed, max_speed, magic, max_hitPoints, max_energy, energy, max_mana, mana;

Fighter::Fighter()
{
	name = "none";
	type = 0;
	max_hitPoints = 0;
	//don't use this constructor
}

Fighter::Fighter(string name, int type, int max_hitPoints)
{
	this->name = name;
	this->type = type;
	this->max_hitPoints = max_hitPoints;
	//or this one
}

Fighter::~Fighter()
{
}

std::string Fighter::getName()  const
{
	return name;
}

int Fighter::getMaximumHP() const
{
	return max_hitPoints;
}
int Fighter::getCurrentHP() const
{
	return hitPoints;
}
int Fighter::getStrength() const
{
	return strength;
}
int Fighter::getSpeed() const
{
	return speed;
}
int Fighter::getMagic() const
{
	return magic;
}

void Fighter::takeDamage(int damage)
{
	int damageTaken = damage - (speed / 4);

	if (damageTaken < 1)
	{
		damageTaken = 1;
	}

	hitPoints -= damageTaken;
}
void Fighter::reset()
{
	hitPoints = max_hitPoints;
	energy = max_energy;
	speed = max_speed;
	mana = max_mana;
}
void Fighter::regenerate()
{
	hitPoints += strength / 6;

	if (hitPoints > max_hitPoints)
		hitPoints = max_hitPoints;

	int manaIncrease = magic / 5;

	if (manaIncrease < 1)
		manaIncrease = 1;

	mana += manaIncrease;
	
	if (mana > max_mana)
		mana = max_mana;
}

/*
bool Fighter::useAbility()
{
	if (type = 1)
	{
		if (energy >= ROBOT_ABILITY_COST)
		{
			return true;
		}
	}
	else if (int Type = 2)
	{
		speed += 1;
		return true;
	}
	else if (type = 3)
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
	}
	return false;
}
*/
