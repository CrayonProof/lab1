#pragma once
#include "ArenaInterface.h"
#include  <vector>
#include "Fighter.h"
using namespace std;
class Arena :
	public ArenaInterface
{
public:
	Arena();
	~Arena();
	bool addFighter(std::string info);
	bool removeFighter(std::string name);
	FighterInterface* getFighter(std::string name);
	int getSize() const;
	vector<std::string> splitString(std::string str, char delimiter);
private:
	vector<Fighter*> fighters;
};

