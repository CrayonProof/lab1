#include "Archer.h"



Archer::Archer()
{
}

Archer::Archer(std::string name, std::string type, int max_hitPoints, int strength, int speed, int magic)
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

Archer::~Archer()
{
}


int Archer::getDamage()
{
	return this->speed;
}
bool Archer::useAbility()
{
	this->speed += 1;
	return true;
}