#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm> 
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Item {
public:
    string name;
    string type;
    int value;

    Item(string n, string t, int v) : name(n), type(t), value(v) {}
};

class Character {
public:
    string name;
    string job;
    int level;
    int exp;
    int maxHP, currentHP;
    int maxMP, currentMP;
    int strength;
    int floor;
    int x, y;
    vector<Item> inventory;
    bool hasSword;
    bool hasAcceptedSmithQuest;
    bool hasCompletedSmithQuest;
    bool hasCompletedMayorQuest;

    Character() : level(1), exp(0), floor(1), x(2), y(2),
        hasSword(false), hasAcceptedSmithQuest(false),
        hasCompletedSmithQuest(false), hasCompletedMayorQuest(false) {
        inventory = {
            Item("Health Potion", "potion", 30),
            Item("Health Potion", "potion", 30),
            Item("Health Potion", "potion", 30),
            Item("Health Potion", "potion", 30),
            Item("Health Potion", "potion", 30),
            Item("Mana Potion", "potion", 20),
            Item("Mana Potion", "potion", 20),
            Item("Mana Potion", "potion", 20),
            Item("Mana Potion", "potion", 20),
            Item("Mana Potion", "potion", 20)
        };
    }

    void createCharacter() {
        cout << "Enter character name: ";
        cin >> name;

        cout << "Choose job:\n1. Warrior\n2. Mage\nChoice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            job = "Warrior";
            maxHP = currentHP = 150;
            maxMP = currentMP = 30;
            strength = 20;
        }
        else {
            job = "Mage";
            maxHP = currentHP = 80;
            maxMP = currentMP = 100;
            strength = 10;
        }
    }

    void showStatus() {
        cout << "\n=== Character Status ==="
            << "\nName: " << name
            << "\nJob: " << job
            << "\nLevel: " << level
            << "\nHP: " << currentHP << "/" << maxHP
            << "\nMP: " << currentMP << "/" << maxMP
            << "\nStrength: " << strength
            << "\nEXP: " << exp << "/" << getNextLevelExp()
            << "\nLocation: Floor " << floor << " (" << x << "," << y << ")"
            << endl;
    }

    void showInventory() {
        cout << "\n=== Inventory ===";
        for (size_t i = 0; i < inventory.size(); i++) {
            cout << "\n" << i + 1 << ". " << inventory[i].name;
        }
        cout << endl;
    }

    int getNextLevelExp() {
        return 30 * (1 + 0.5 * (level - 1));
    }

    void levelUp() {
        level++;
        maxHP += 20;
        strength += 5;
        exp = 0;
        cout << "Leveled up to " << level << "!\n";
    }

    void completeSmithQuest() {
        if (!hasCompletedSmithQuest) {
            level++;
            maxHP += 100;
            currentHP = maxHP;
            maxMP += 50;
            currentMP = maxMP;
            strength += 20;
            hasCompletedSmithQuest = true;
            cout << "\nYou completed the blacksmith's quest and received rewards!\n";
            showStatus();
        }
    }

    void completeMayorQuest() {
        hasCompletedMayorQuest = true;
    }

    void saveGame() {
        ofstream file("save.dat");
        file << name << endl
            << job << endl
            << level << endl
            << exp << endl
            << currentHP << endl
            << maxHP << endl
            << currentMP << endl
            << maxMP << endl
            << strength << endl
            << floor << endl
            << x << endl
            << y << endl
            << hasSword << endl
            << hasAcceptedSmithQuest << endl
            << hasCompletedSmithQuest << endl
            << hasCompletedMayorQuest << endl;
    }

    void loadGame() {
        ifstream file("save.dat");
        getline(file, name);
        getline(file, job);
        file >> level >> exp >> currentHP >> maxHP >> currentMP >> maxMP >> strength >> floor >> x >> y
            >> hasSword >> hasAcceptedSmithQuest >> hasCompletedSmithQuest >> hasCompletedMayorQuest;
    }
};

class Enemy {
public:
    string name;
    int hp;
    int strength;
    int exp;

    Enemy(string n, int h, int s, int e) : name(n), hp(h), strength(s), exp(e) {}

    static Enemy createEnemy(int floor) {
        if (floor <= 2) {
            if (rand() % 100 < 70) return Enemy("Slime", 30, 5, 20);
            return Enemy("Goblin", 50, 8, 30);
        }
        if (floor <= 4) {
            if (rand() % 100 < 70) return Enemy("Goblin", 50, 8, 30);
            return Enemy("Headless Knight", 100, 15, 50);
        }
        return Enemy("Demon King", 500, 30, 200);
    }
};

class GameSystem {
private:
    vector<vector<vector<char>>> gameMap;
    Character player;
    bool bossDefeated;

    void showMap() {
        cout << "\n=== Floor " << player.floor << " Map ===\n";
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == player.y && j == player.x) {
                    cout << "P "; 
                }
                else {
                    cout << gameMap[player.floor - 1][i][j] << " ";
                }
            }
            cout << endl;
        }
        cout << "Legend: P=Player, S=Stairs\n";
    }

    void showQuests() {
        cout << "\n=== Current Quests ===";
        cout << "\n1. Mayor's Quest: Defeat the Demon King on the 5th floor";
        if (player.hasCompletedMayorQuest) {
            cout << " (Completed)";
        }
        else {
            cout << " (In Progress)";
        }

        cout << "\n2. Blacksmith's Quest: Find the Holy Sword";
        if (player.hasCompletedSmithQuest) {
            cout << " (Completed)";
        }
        else if (player.hasAcceptedSmithQuest) {
            cout << " (In Progress)";
        }
        else {
            cout << " (Not Accepted)";
        }
        cout << endl;
    }

    void generateStairs() {
        srand(time(0));
        for (int f = 0; f < 5; f++) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    gameMap[f][i][j] = '.';
                }
            }
            int stairX, stairY;
            do {
                stairX = rand() % 5;
                stairY = rand() % 5;
            } while (stairX == 2 && stairY == 2);

            gameMap[f][stairY][stairX] = 'S';
        }
    }

public:
    GameSystem() : bossDefeated(false) {
        gameMap = vector<vector<vector<char>>>(5,
            vector<vector<char>>(5, vector<char>(5, '.')));
        generateStairs(); 
    }

    void mainMenu() {
        while (true) {
            system("cls");
            cout << "=== RPG Game ==="
                << "\n1. New Game"
                << "\n2. Load Game"
                << "\n3. Exit"
                << "\nChoice: ";
            int choice;
            cin >> choice;

            switch (choice) {
            case 1: newGame(); break;
            case 2: loadGame(); break;
            case 3: exit(0);
            }
        }
    }

    void newGame() {
        player.createCharacter();
        showIntro();
        gameLoop();
    }

    void loadGame() {
        player.loadGame();
        gameLoop();
    }

    void showIntro() {
        system("cls");
        cout << "One day, you arrived at a ruined village.\n";
        Sleep(1500);
        cout << "There were few people in the village, so you asked the mayor about the reason.\n";
        Sleep(1500);
        cout << "Mayor: 'Young adventurer, the Demon King has occupied the dungeon and driven away our villagers...'\n";
        Sleep(1500);
        cout << "Mayor: 'Please defeat the Demon King on the 5th floor and save our village!'\n";
        Sleep(1500);

        cout << "\nAs you were about to leave, the blacksmith stopped you...\n";
        Sleep(1500);
        cout << "Blacksmith: 'Wait! I heard the legendary Holy Sword is hidden in the dungeon!'\n";
        Sleep(1500);
        cout << "Blacksmith: 'If you can find it, I can enhance your equipment as a reward! (3% drop rate)'\n";
        Sleep(1500);

        char choice;
        cout << "Accept the blacksmith's quest? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            player.hasAcceptedSmithQuest = true;
            cout << "Blacksmith: 'Great! I'll be waiting here for your good news!'\n";
        }
        else {
            cout << "Blacksmith: 'What a pity... You can come find me if you change your mind.'\n";
        }
        Sleep(3000);
    }

    void gameLoop() {
        while (true) {
            system("cls");
            player.showStatus();

            cout << "\n=== Actions ==="
                << "\n1. Move (WASD)"
                << "\n2. Items"
                << "\n3. View Map"
                << "\n4. View Quests"
                << "\n5. Save Game"
                << "\n6. Exit Game"
                << "\nChoice: ";
            int choice;
            cin >> choice;

            switch (choice) {
            case 1: movePlayer(); break;
            case 2: useItem(); break;
            case 3: showMap();
                cout << "\nPress any key to continue...";
                cin.ignore();
                cin.get();
                break;
            case 4: showQuests();
                cout << "\nPress any key to continue...";
                cin.ignore();
                cin.get();
                break;
            case 5: player.saveGame();
                cout << "Game saved!";
                Sleep(1000);
                break;
            case 6: return;
            default: cout << "Invalid choice!"; Sleep(500);
            }
        }
    }

    void movePlayer() {
        cout << "Enter direction (W/A/S/D): ";
        char dir;
        cin >> dir;

        switch (toupper(dir)) {
        case 'W': player.y = max(0, player.y - 1); break;
        case 'S': player.y = min(4, player.y + 1); break;
        case 'A': player.x = max(0, player.x - 1); break;
        case 'D': player.x = min(4, player.x + 1); break;
        }

        if (gameMap[player.floor - 1][player.y][player.x] == 'S' && player.floor < 5) {
            player.floor++;
            player.x = player.y = 2;
            cout << "Entered floor " << player.floor << "!";
            Sleep(1000);
        }

        if ((rand() % 100 < 25 && player.floor != 5) || player.floor == 5) {
            battle();
        }
    }

    void useItem() {
        player.showInventory();
        cout << "Select item (0 to cancel): ";
        int choice;
        cin >> choice;

        if (choice > 0 && choice <= player.inventory.size()) {
            Item item = player.inventory[choice - 1];
            if (item.type == "potion") {
                if (item.name == "Health Potion") {
                    player.currentHP = min(player.maxHP, player.currentHP + item.value);
                    cout << "Recovered " << item.value << " HP!\n";
                }
                else {
                    player.currentMP = min(player.maxMP, player.currentMP + item.value);
                    cout << "Recovered " << item.value << " MP!\n";
                }
                player.inventory.erase(player.inventory.begin() + choice - 1);
            }
        }
        Sleep(1000);
    }

    void battle() {
        Enemy enemy = Enemy::createEnemy(player.floor);
        cout << "\nEncountered " << enemy.name << "!\n";

        while (player.currentHP > 0 && enemy.hp > 0) {
            player.showStatus();
            cout << enemy.name << " HP: " << enemy.hp << "\n";

            cout << "\n1. Attack\n2. Use Skill\n3. Use Item\n4. Flee\nChoice: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                int damage = player.strength + rand() % 5;
                if (player.hasSword) damage += 10;
                enemy.hp -= damage;
                cout << "Dealt " << damage << " damage!\n";
            }
            else if (choice == 2) {
                if (player.currentMP >= 10) {
                    int damage = player.strength * 2 + rand() % 10;
                    enemy.hp -= damage;
                    player.currentMP -= 10;
                    cout << "Used skill and dealt " << damage << " damage!\n";
                }
                else {
                    cout << "Not enough MP!\n";
                }
            }
            else if (choice == 3) {
                useItem();
                continue;
            }
            else if (choice == 4) {
                if (rand() % 100 < 30) {
                    cout << "Successfully fled!\n";
                    Sleep(1000);
                    return;
                }
                cout << "Failed to flee!\n";
            }

            if (enemy.hp > 0) {
                int damage = enemy.strength + rand() % 5;
                player.currentHP -= damage;
                cout << enemy.name << " dealt " << damage << " damage!\n";
            }

            Sleep(1000);
        }

        if (player.currentHP > 0) {
            player.exp += enemy.exp;
            cout << "Gained " << enemy.exp << " EXP!\n";

            if (rand() % 100 < 3 && player.hasAcceptedSmithQuest && !player.hasCompletedSmithQuest) {
                player.hasSword = true;
                cout << "Obtained the Holy Sword!\n";
                player.completeSmithQuest();
            }

            while (player.exp >= player.getNextLevelExp()) {
                player.levelUp();
            }

            if (enemy.name == "Demon King") {
                player.completeMayorQuest();
                cout << "\n================================\n";
                cout << "Mayor: 'Thank you for defeating the Demon King, the village will soon recover!'\n";
                cout << "Villagers gradually returned to the village and started new lives.\n";
                cout << "You became the hero of the village!\n";
                cout << "Game Victory!\n";
                cout << "================================\n";
                Sleep(5000);
                exit(0);
            }
        }
        else {
            cout << "Game Over!\n";
            Sleep(2000);
            exit(0);
        }
        Sleep(2000);
    }
};

int main() {
    srand(time(0));
    GameSystem game;
    game.mainMenu();
    return 0;
}