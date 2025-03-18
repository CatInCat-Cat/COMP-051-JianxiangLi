#include <iostream>
#include <ctime>
using namespace std;
int rollDie() {
return (rand() % 6) + 1;
}
int rollMultipleDice(int numberOfDice) {
int total = 0;
for (int i = 0; i < numberOfDice; ++i) {
int roll = rollDie();
total += roll;
cout << "Rolled: " << roll << endl;
}
return total;
}
int playRound() {
cout << "Player's turn:" << endl;
int playerTotal = rollMultipleDice(2);
cout << "Player's total: " << playerTotal << endl;
cout << "Computer's turn:" << endl;
int computerTotal = rollMultipleDice(2);
cout << "Computer's total: " << computerTotal << endl;
if (playerTotal > computerTotal) {
cout << "You win this round! (+20 points)" << endl;
return 1;
} else if (playerTotal < computerTotal) {
cout << "You lose this round." << endl;
return -1;
} else {
cout << "This round is a draw. (+10 points)" << endl;
return 0;
}
}
int shop(int currentScore) {
int choice;
cout << "Shop" << endl;
cout << "1. Add +5 points (Cost: 5 points)" << endl;
cout << "2. Add +15 points (Cost: 10 points)" << endl;
cout << "3. Exit Shop" << endl;
cout << "Enter your choice: ";
cin >> choice;
if (choice == 1 && currentScore >= 5) {
currentScore += 5;
currentScore -= 5;
cout << "Purchased +5 points!" << endl;
} else if (choice == 2 && currentScore >= 10) {
currentScore += 15;
currentScore -= 10;
cout << "Purchased +15 points!" << endl;
} else if (choice == 3) {
cout << "Exiting shop." << endl;
} else {

    finalScore) {
        cout << "Game Over!" << endl;
        cout << "Rounds Played: " << totalRounds << endl;
        cout << "Wins: " << wins << " | Draws: " << draws << " | Losses: " << losses <<
        endl;
        cout << "Final Score: " << finalScore << endl;
        cout << "Thanks for playing!" << endl;
        }
        int main() {
        srand(static_cast<unsigned int>(time(0)));
        int score = 0;
        int rounds = 0;
        int wins = 0, draws = 0, losses = 0;
        char playAgain = 'y';
        cout << "Welcome to the Dice Battle Game!" << endl;
        while (playAgain == 'y' || playAgain == 'Y') {
        ++rounds;
        cout << "Round " << rounds << ":" << endl;
        char shopChoice;
        cout << "Do you want to visit the shop before playing? (y/n): ";
        cin >> shopChoice;
        if (shopChoice == 'y' || shopChoice == 'Y') {
        score = shop(score);
        }
        int result = playRound();
        if (result == 1) {
        score += 20;
        ++wins;
        } else if (result == -1) {
        ++losses;
        } else {
        score += 10;
        ++draws;
        }
        cout << "Current Score: " << score << endl;
        cout << "Do you want to play another round? (y/n): ";
        cin >> playAgain;
        }
        displayStatistics(rounds, wins, draws, losses, score);
        return 0;
        }cout << "Not enough points or invalid choice." << endl;
        }
        return currentScore;
        }
        void displayStatistics(int totalRounds, int wins, int draws, int losses, int
        finalScore) {
        cout << "Game Over!" << endl;
        cout << "Rounds Played: " << totalRounds << endl;
        cout << "Wins: " << wins << " | Draws: " << draws << " | Losses: " << losses <<
        endl;
        cout << "Final Score: " << finalScore << endl;
        cout << "Thanks for playing!" << endl;
        }
        int main() {
        srand(static_cast<unsigned int>(time(0)));
        int score = 0;
        int rounds = 0;
        int wins = 0, draws = 0, losses = 0;
        char playAgain = 'y';
        cout << "Welcome to the Dice Battle Game!" << endl;
        while (playAgain == 'y' || playAgain == 'Y') {
        ++rounds;
        cout << "Round " << rounds << ":" << endl;
        char shopChoice;
        cout << "Do you want to visit the shop before playing? (y/n): ";
        cin >> shopChoice;
        if (shopChoice == 'y' || shopChoice == 'Y') {
        score = shop(score);
        }
        int result = playRound();
        if (result == 1) {
        score += 20;
        ++wins;
        } else if (result == -1) {
        ++losses;
        } else {
        score += 10;
        ++draws;
        }
        cout << "Current Score: " << score << endl;
        cout << "Do you want to play another round? (y/n): ";
        cin >> playAgain;
        }
        displayStatistics(rounds, wins, draws, losses, score);
        return 0;
        }