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
	this->hitPoints = this->max_hitPoints;
	this->energy = this->max_energy;
	this->speed = this->max_speed;
	this->mana = this->max_mana;
}
void Fighter::regenerate()
{
	int hitPointsIncrease = (this->strength / 6);
	
	if (hitPointsIncrease < 1)
		hitPointsIncrease = 1;
		
		hitPoints += hitPointsIncrease;

	if (this->hitPoints > this->max_hitPoints)
		this->hitPoints = this->max_hitPoints;

	int manaIncrease = this->magic / 5;

	if (manaIncrease < 1)
		manaIncrease = 1;

	this->mana += manaIncrease;
	
	if (this->mana > this->max_mana)
		this->mana = this->max_mana;
}

