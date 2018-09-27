#include "Arena.h"
#include "Fighter.h"
#include "Robot.h"
#include "Cleric.h"
#include "Archer.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;

vector<Fighter*> fighters;

Arena::Arena()
{
}


Arena::~Arena()
{
}

bool has_only_digits(const string s){
  return s.find_first_not_of( "0123456789" ) == string::npos;
}

bool vecContains(vector<Fighter*> fightersToCheck, std::string nameToCheck)
{
	for (int i = 0; i < fighters.size(); i++)
	{
		if ((*(fightersToCheck.at(i))).getName() == nameToCheck)
		{
			return true;
		}
	}
	return false;
}

bool Arena::addFighter(std::string info)
{
	vector<std::string> infoVector = splitString(info, ' ');
	int name;
	int type;
	int max_hitpoints;
	int strength;
	int speed;
	int magic;

infoVector.erase(infoVector.begin());

	for (int i = 2; i < infoVector.size(); i++)
	{
		if (!has_only_digits(infoVector.at(i)))
		{
			return false;
		}
	}

	try
	{
		istringstream(infoVector.at(2)) >> max_hitpoints;
		istringstream(infoVector.at(3)) >> strength;
		istringstream(infoVector.at(4)) >> speed;
		istringstream(infoVector.at(5)) >> magic;
	}
	catch (exception e)
	{
		cout << "Error. Bad argument types" << endl;
		//return false;
	}


	for (string s : infoVector)
	{
		//cout << endl << s << endl;
	}

	//cout << endl << "MAXHP MAXHP MAXHP" << max_hitpoints << endl;

	if (infoVector.size() == 6)
	{
		if (!vecContains(fighters, infoVector.at(0)))
		{
			//fighters.push_back(new Robot("Josh", "A", 2, 3, 4, 5));
			if (infoVector.at(1) == "R")
			{
				fighters.push_back(new Robot(infoVector.at(0), infoVector.at(1), max_hitpoints, strength, speed, magic));

			}
			else if (infoVector.at(1) == "A")
			{
				fighters.push_back(new Archer(infoVector.at(0), infoVector.at(1), max_hitpoints, strength, speed, magic));
			}
			else if (infoVector.at(1) == "C")
			{
				fighters.push_back(new Cleric(infoVector.at(0), infoVector.at(1), max_hitpoints, strength, speed, magic));
			}
			return true;
		}
		else
		{
			cout << "Error. Duplicate fighter name" << endl;
			return false;
		}
		
	}
	else
	{
		cout << "Error. Wrong number of arguments for fighter" << endl;
		return false;
	}
}

bool Arena::removeFighter(std::string name)
{
	for (int i = 0; i < fighters.size(); i++)
	{
		if ((*(fighters.at(i))).getName() == name)
			delete fighters.at(i);
			fighters.erase(fighters.begin() + (i));
		return true;
	}
	return false;
}

int indexOf(vector<Fighter> fightersToCheck, std::string nameToCheck)
{
	for (int i = 0; i < fighters.size(); i++)
	{
		if (fightersToCheck.at(i).getName() == nameToCheck)
		{
			return i;
		}
	}
	return -1;
}

FighterInterface* Arena::getFighter(std::string name)
{
	//cout << endl << fighters.size() << endl;
	for (int i = 0; i < fighters.size(); i++)
	{
		if ((*(fighters.at(i))).getName() == name)
			return fighters.at(i);
			cout << endl << (*(fighters.at(i))).getName() << endl;
	}
}

int Arena::getSize() const
{
	return fighters.size();
}

vector<std::string> Arena::splitString(std::string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str); // Turn the string into a stream.
	string tok;

	while (getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}

	return internal;
}