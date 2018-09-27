#include "Robot.h"
#include <math.h>
using namespace std;


Robot::Robot()
{
}


Robot::~Robot()
{
}

Robot::Robot(std::string name, std::string type, int max_hitPoints, int strength, int speed, int magic)
{
	//cout << endl << "ABUDABI BODABI BODO: " << max_hitPoints << endl;
	this->name = name;
	this->max_hitPoints = max_hitPoints;
	this->hitPoints = max_hitPoints;
	this->strength = strength;
	this->max_speed = speed;
	this->speed = speed;
	this->magic = magic;
	max_energy = 2*magic;
}

int Robot::getDamage()
{
	double doubStrength;
	if (useAbility())
	{
		doubStrength = (double) strength + (double) strength * pow((double) energy/(double) max_energy, 4);
		return (int) doubStrength;
	}

	return strength + (int) doubStrength;
}
bool Robot::useAbility()
{
	if (energy >= ROBOT_ABILITY_COST)
	{
		return true;
	}
	return false;
}