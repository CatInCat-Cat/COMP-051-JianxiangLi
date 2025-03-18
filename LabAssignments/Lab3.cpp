#include <iostream>
#include <ctime>
using namespace std;

int main() {
srand(static_cast<unsigned int>(time(0)));
int guessNumber;
int number = rand()%100 + 1;
char yes = 'y';
while (yes == 'y' || yes == 'Y'){
cout << "You only have 5 time to guess an interger number." << endl;
cout << "Enter an interger between 0 and 100: " << endl;
cin >> guessNumber;
for (int i = 1; i <= 5; i++) {
if (guessNumber > number ){
cout << "Too hight!" << endl;
cout << "Pleas try again: " << endl;
cin >> guessNumber;
} else if (guessNumber < number) {
cout << "Too low~" << endl;
cout << "Pleas try again: " << endl;
cin >> guessNumber;
} else {
cout << "Congratulations! You guessed the number! " << endl;
break;
}
}
cout << "Guess failure!" << endl;
cout << "The correct number is: " << number << endl;
cout << "Do you want to play again? (y/n)" << endl;
cin >> yes;
}
return 0;
}#include <iostream>
#include <ctime>
using namespace std;
int main() {
srand(static_cast<unsigned int>(time(0)));
int guessNumber;
int number = rand()%100 + 1;
char yes = 'y';
while (yes == 'y' || yes == 'Y'){
cout << "You only have 5 time to guess an interger number." << endl;
cout << "Enter an interger between 0 and 100: " << endl;
cin >> guessNumber;
for (int i = 1; i <= 5; i++) {
if (guessNumber > number ){
cout << "Too hight!" << endl;
cout << "Pleas try again: " << endl;
cin >> guessNumber;
} else if (guessNumber < number) {
cout << "Too low~" << endl;
cout << "Pleas try again: " << endl;
cin >> guessNumber;
} else {
cout << "Congratulations! You guessed the number! " << endl;
break;
}
}
cout << "Guess failure!" << endl;
cout << "The correct number is: " << number << endl;
cout << "Do you want to play again? (y/n)" << endl;
cin >> yes;
}
return 0;
