
#include "Character.h"
using namespace std;
Character::Character() {

	name = " ";
	race = " ";
	sex = " ";

	playerRace = { "elf", "dwarf", "firelord", "goblin", "human" };

	level = 0;	
	health = 0;
	totalHealth = 0;
	maxHealth = 0;
	heal = 0;

	level = 1;
	current_xp = 0;
	base_xp = 83;
	xp_to_level = base_xp;
	minlevel = 1;
	maxlevel = 60;
}

void Character::characterCreation() {

	int counter = 0;

	cout << "Enter Caracters Name: ";
	cin >> name;

	cout << "Enter Characters race: \n";
	cout << "1.Elf\n";
	cout << "2.Dwarf\n";
	cout << "3.Firelord\n";
	cout << "4.Goblin\n";
	cout << "5.Human\n";
	cout << "Type Below your Race: \n\n";
	cin >> race;

	for_each(race.begin(), race.end(), [](char& c) {
		c = ::tolower(c);
		});

	for (int i = 0; i < sizeof(playerRace); i++) {
		if (race == "elf") {
			health = 80;
			break;
		}
		if (race == "dwarf") {
			health = 120;
			break;
		}
		if (race == "firelord") {
			health = 150;
			break;
		}
		if (race == "goblin") {
			health = 82;
			break;
		}
		if (race == "human") {
			health = 68;
			break;
		}
		else {
			health = 100;
			break;
		}
	}

	cout << "\n";
	cout << "Enter Characters sex: ";
	cin >> sex;
	system("cls");

	for (int i = 0; i <= counter; i++) {
		if (i == 0) {
			cout << "Creating Character.\n";
			break;
		}
		if (i == 1) {
			cout << "Creating Character..\n";
			break;
		}
		if (i == 2) { 
			cout << "Creating Character...\n"; 
			break;
		}


		Sleep(400);
		system("cls");
		counter++;
	}

	name[0] = toupper(name[0]);
	race[0] = toupper(race[0]);
	sex[0] = toupper(sex[0]);


	totalHealth = health;
	maxHealth = totalHealth;
}