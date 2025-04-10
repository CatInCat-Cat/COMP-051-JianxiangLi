#include "Character.h"

using namespace std;

void HUD();
void Combat();
void CombatHUD();
void Moving();
void CreatMonster();
void LevelUp();


int monsterHp = 0;
int monsterXp = 0;
int monsterLevel = 0;

string monsterName[] = { "Goblin", "Dwarf", "Orge", "Witch", "Demon", "Wizard" };
int currentMonsterNames = 5;
string currentMonster = " ";

int counter = 0;

Character character;

int main() {

	character.characterCreation();

	HUD();
	Moving();

	return 0;
}

void HUD() {
	Sleep(500);
	system("cls");
	cout << "Name: " << character.name << "		Health: " << character.totalHealth << "\nRace: " << character.race
		<< "\nSex: " << character.sex << "\nLevel: " << character.level << "\nxp: " << character.current_xp << "\nXp to Level: " << character.xp_to_level << endl;
	Moving();
}

void CombatHUD() {
	Sleep(500);
	system("cls");
	system("cls");
	cout << "Name: " << character.name << "		|		Monster Name: " << currentMonster << "\nHealth: " << character.totalHealth << "		|		MonsterHealth: "
		<< monsterHp << "\nLevel: " << character.level << "		|		Monster Level: " << monsterLevel << endl;
}

void Combat() {

	CombatHUD();
	int playerAttack; 
	int playerDamage = 8 * character.level / 2;
	//int playerDamage = 300000;
	int monsterAttack = 6 * monsterLevel / 2;

	if (character.totalHealth >= 1 && monsterHp >= 1) {
		cout << "\n";
		cout << "1. Attack\n";
		cout << "2. Block\n";
		cout << "3. Run!\n";
		cout << "\n";
		cin >> playerAttack;

		if (playerAttack == 1) {
			cout << "Attacking... you did " << playerDamage << " to the " << currentMonster << endl;
			monsterHp = monsterHp - playerDamage;
			Sleep(1000);
			CombatHUD();
			if (monsterHp >= 1) {
				cout << "\n";
				cout << "Monster is Attacking...\n";
				character.totalHealth = character.totalHealth - monsterAttack;
				cout << "You suffered " << monsterAttack << " hp " << character.totalHealth << endl;
				if (character.totalHealth <= 0) {
					character.totalHealth = 0;
					system("cls");
					cout << "You Died! \nYou were level: " << character.level << " you got killed by " << currentMonster << endl;
					Sleep(2000);
					exit(0);
				}
			}
			else if (monsterHp <= 0) {
				monsterHp = 0;
				cout << "\n";
				cout << "You Defeated " << currentMonster << " you are rewarded with " << monsterXp << " xp. \nWeel Done!";

				if (character.level != character.maxlevel) {
					character.current_xp += monsterXp;
					LevelUp();
				}

				Sleep(1000);
				HUD();
			}
			Sleep(1000);
			Combat();
		}
		else if (playerAttack == 2) {
			cout << "Blocking\n";
			int i = rand() % 100 + 1;
			if (i >= 50) {
				cout << "You Blocked the incoming attack\n";
				character.heal = character.level * 10 / 2;
				cout << "You have been healed for " << character.heal << endl;
				character.totalHealth += character.heal;
				Sleep(1000);
				Combat();
			}
			else {
				cout << "You failed to block the savage attack\n";
				character.totalHealth -= monsterAttack;
				cout << "You were stabbled in the back for " << monsterAttack << " current hp " << character.totalHealth << endl;
				Sleep(1000);
				Combat();
			}
		}	
		else if (playerAttack == 3) {
			cout << "You try to run\n";
			int x = rand() % 100 + 1;
			if (x >= 50) {
				cout << "You run away.\n";
					HUD();
			}
			else {
				cout << "You failed to run away.\n";
				cout << "Monster does a savage attack on you!\n";
				character.totalHealth -= monsterAttack + 10;
				cout << "You suffered " << monsterAttack + 10 << " Your current Health is " << character.totalHealth << endl;
				Sleep(1000);
				Combat();
			}
		}
		else {
			cout << "Invalid Number\n";
			Sleep(500);
			Moving();
		}
	}

	if (character.totalHealth <= 1) {
		system("cls");
		cout << "You Died! \nYou were level: " << character.level << " you got killed by " << currentMonster << endl;
		Sleep(2000);
		exit(0);
	}
	if (monsterHp <= 1) {
		HUD();
		LevelUp();
		cout << "\n";
		cout << "You Defeated " << currentMonster << " you are rewarded with " << monsterXp << " xp. \nWeel Done!";
		Sleep(1000);
	}

}

void Moving() {

	int choices;
	cout << "\n\n";
	cout << "1. Move Forward\n";
	cout << "2. Relax\n";
	cout << "3. Move Backwards\n";
	cout << "\n";

	cin >> choices;

	if (choices == 1) {
		int temp = rand() % 100 + 1;
		cout << "You begin moving forward...\n";
		if (temp >= 50) {
			CreatMonster();
			string tempName = monsterName[rand()% currentMonsterNames];
			cout << "A " << tempName << "! Prepare to fight!\n";
			currentMonster = tempName;
			Sleep(1000);
			Combat();
		}

		cout << "You find nothing of interest\n";
		Sleep(1000);
		HUD();

	}

	else if (choices == 2) {
		cout << "You want to set up camp for the evening\n";
		if (character.totalHealth <= 99) {
			character.totalHealth += 10 * character.level;
		}
		cout << "You healed by resting Healthing is now " << character.totalHealth << endl;
		Sleep(1000);
		HUD();
	}

	else if (choices == 3) {
		int temp = rand() % 100 + 1;
		cout << "You begin moving backwards...\n";
		if (temp >= 50) {
			CreatMonster();
			string tempName = monsterName[rand() % currentMonsterNames];
			cout << "A " << tempName << "! Prepare to fight!\n";
			currentMonster = tempName;
			Sleep(1000);
			Combat();
		}
		cout << "You find nothing of interest\n";
		Sleep(1000);
		HUD();
	}

	else {
		cout << "Invalid Number\n";
		Sleep(500);
		Moving();
	}

}

void LevelUp() {

	if (character.current_xp >= character.xp_to_level) {
		character.xp_to_level += floor(character.level + 25 * pow(2, character.level / 7));
		character.totalHealth = floor(character.totalHealth + 23 * pow(2, character.level / 8));

		if (character.level >= character.minlevel && character.level <= character.maxlevel) {
			character.level++;
		}
		else {
			character.level = 60;
		}

		character.maxHealth = character.totalHealth;
		cout << "Wait what's this a level up! You are now level " << character.level << endl;
		cout << "Your total health increased now your health is " << character.totalHealth << endl;
		cout << "\n";
		Sleep(1000);
		LevelUp();
	}

	Sleep(2000);
	HUD();
}

void CreatMonster() {
	monsterHp = 30;

	monsterLevel = (rand() % 3) + character.level;

	monsterHp = (rand() % 30) * monsterLevel;

	monsterXp = monsterHp;

	if (monsterHp == 0) {
		CreatMonster();
	}
	if (monsterLevel == 0) {
		CreatMonster();
	}
}