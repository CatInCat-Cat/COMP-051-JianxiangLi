#pragma once

#include "Header.h"
using namespace std;
class Character
{
public:
	Character();

	string name, race, sex;
	vector<string> playerRace = { "elf", "dwarf", "firelord", "goblin", "human" };
	int health, totalHealth, maxHealth, heal;

	int level, current_xp, base_xp, xp_to_level, minlevel, maxlevel;

	void characterCreation();
};
