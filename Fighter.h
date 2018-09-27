#pragma once
#include "FighterInterface.h"
#include <string>
using namespace std;

class Fighter :
	public FighterInterface
{
public:
	Fighter();
	Fighter(string name, int intType, int max_hitPoints);
	Fighter(string name, string type, int max_hitPoints);
	~Fighter();
	string getName() const;
	int getMaximumHP() const;
	int getCurrentHP() const;
	int getStrength() const;
	int getSpeed() const;
	int getMagic() const;
	void takeDamage(int damage);
	void reset();
	void regenerate();
protected:
	string name, stringType;
	int type; //1 = robot, 2 = archer, 3 = cleric
	int hitPoints, strength, speed, max_speed, magic, max_hitPoints, max_energy, max_mana, mana, energy;
	const int ROBOT_ABILITY_COST = 5;
	const int CLERIC_ABILITY_COST = 25;
};

