#include <iostream>
using namespace std;

int main() {
int number;
double moneya;
double amount;
double moneyb;
moneya = 1000.00;
cout << "Menu:" << endl;
cout << "1. Check Balance" << endl;
cout << "2. Deposit Money" << endl;
cout << "3. Withdraw Money" << endl;
cout << "4. Exit" << endl;
cout << endl;
number = 0;
while (number < 4) {
cout << "Enter your choice: " << endl;
cin >> number;
if (number == 1 ) {
cout << "Your current balance is: $" << moneya << endl;
} else if (number == 2) {
cout << "Enter the amount to deposit: " << endl;
cin >> amount;
moneyb = moneya + amount;
cout << "Deposit successful! Your new balance is: $" << moneyb << endl;
} else if ( number == 3) {
cout << "Enter the amount to withDraw: " << endl;
cin >> amount;
moneyb = moneyb - amount;
cout << "Withdrawal successful! Your new balance is: $" << moneyb <<
endl;
} else if (moneya < amount) {
cout << "Insufficient funds." << endl;
} else if (number == 4) {
cout << "Thank you for using the ATM, Goodbye!" << endl;
}
}
return 0;
}