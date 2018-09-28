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
	this->max_energy = 2*magic;
}

int Robot::getDamage()
{

	return strength + (int) doubStrength;
	doubStrength = 0.0;
}
bool Robot::useAbility()
{
	doubStrength = 0.0;
	
	if (this->energy >= ROBOT_ABILITY_COST)
	{
		doubStrength = ((double) this->strength) * pow(((double) this->energy)/((double) this->max_energy), 4);
		this->energy -=ROBOT_ABILITY_COST;
		return true;
	}
	return false;
}