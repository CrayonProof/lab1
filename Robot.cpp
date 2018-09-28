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
	this->energy =max_energy;
	doubStrength = 0.0;
}

int Robot::getDamage()
{
		int bonusDamage = (int) doubStrength;
		return strength + bonusDamage;
		this->doubStrength = 0.0;
}
bool Robot::useAbility()
{
	doubStrength = 0.0;
	
	if (this->energy >= ROBOT_ABILITY_COST)
	{
		double dSt = (double) strength;
		double dEngy = (double) energy;
		double dMxEngy = (double) max_energy;
		this->doubStrength = (dSt * pow((dEngy/dMxEngy), 4));
		this->energy -=ROBOT_ABILITY_COST;
		return true;
	}
	return false;
}