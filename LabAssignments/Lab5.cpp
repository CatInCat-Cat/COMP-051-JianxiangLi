#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
class Car {
private:
string make, model;
int year;
double originalPrice;
double currentPrice;
bool isOwned;
public:
Car(string make, string model, int year)
: make(make), model(model), year(year), originalPrice(10000),
currentPrice(10000), isOwned(false) {}
string getCarInfo() {
return to_string(year) + " " + make + " " + model;
}
bool buyCar(double &userMoney) {
if (isOwned) {
cout << "Could NOT buy " << getCarInfo() << " (already owned)." <<
endl;
return false;
}
if (userMoney < currentPrice) {
cout << "Could NOT buy " << getCarInfo() << " (insufficient funds)." <<
endl;
return false;
}
userMoney -= currentPrice;
isOwned = true;
cout << "Bought " << getCarInfo() << " for $" << currentPrice << "." <<
endl;
return true;
}
bool sellCar(double &userMoney) {
if (!isOwned) {
cout << "Could NOT sell " << getCarInfo() << " (not currently owned)."
<< endl;
return false;
}
userMoney += currentPrice;
isOwned = false;
cout << "Sold " << getCarInfo() << " for $" << currentPrice << "." << endl;
return true;
}
bool getOwnership() const {
return isOwned;
}
double getOriginalPrice() const {
    return originalPrice;
}
double getCurrentPrice() const {
return currentPrice;
}
};
int main() {
srand(time(0));
double userMoney = 100000;
vector<Car> cars = {
Car("Toyota", "Camry", 2010),
Car("Tesla", "Model 3", 2022),
Car("Ford", "Mustang", 1967)
};
for (int i = 1; i <= 10; i++) {
int carIndex = rand() % cars.size();
int action = rand() % 2;
cout << "--- Transaction " << i << " ---" << endl;
if (action == 0) {
cars[carIndex].buyCar(userMoney);
} else {
cars[carIndex].sellCar(userMoney);
}
cout << "User balance: $" << userMoney << "\n" << endl;
}
cout << "\n--- Final Report After 10 Transactions ---\n" << endl;
cout << "User final balance: $" << userMoney << "\n" << endl;
for (size_t i = 0; i < cars.size(); i++) {
cout << "Car " << i + 1 << ": " << cars[i].getCarInfo() << endl;
cout << " Original Price: $" << cars[i].getOriginalPrice() << endl;
cout << " Current Price: $" << cars[i].getCurrentPrice() << endl;
cout << " Currently Owned? " << (cars[i].getOwnership() ? "Yes" : "No") <<
"\n" << endl;
}
return 0;
}