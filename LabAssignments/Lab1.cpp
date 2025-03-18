#include <iostream>
using namespace std;

int main() {
int weatherCode;
int temperature;
double budget;
cout << "What's the weather like?" << endl;
cout << "1 for sunny, 2 for rainy, 3 for cloudy" << endl;
cin >> weatherCode;
if (weatherCode == 1){
cout << "Sunny" << endl;
} else if (weatherCode == 2){
cout << "Rainy" << endl;
} else if (weatherCode == 3){
cout << "Cloudy" << endl;
}
cout << "What's the temperature outside now?" << endl;
cin >> temperature;
cout << temperature << " degrees" << endl;
cout << "How much is the budget" << endl;
cin >> budget;
cout << budget << " dollars" << endl;
if (weatherCode == 1 && temperature > 75){
if (budget > 20){
cout << "Go to the beach!" << endl;
} else {
cout << "Have a picnic." << endl;
}
} else if (weatherCode == 2){
if (budget > 15){
cout << "Go to a museum." << endl;
} else {
cout << "Watch a movie at home." << endl;
}
} else if (weatherCode == 3 || temperature < 60){
cout << "Visit a coffee shop." << endl;
}
return 0;
}