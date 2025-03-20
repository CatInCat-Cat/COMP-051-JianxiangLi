#include <iostream>
using namespace std; 

main(){
    int a = 3;
    int b = 5; 
    int c = 0;
    int d;
    char choice;

    while (true){
        cout << "1. add operation" << endl;
        cout << "2. minus operation" << endl;
        cout << "3. display all variable value" << endl;
        cout << "4. quit" << endl;

        cin >> d;
        if (d == 1){
            c = a + b;
            cout << "Add operation: " << c << endl;
        } else if (d == 2) {
            a = c - 2;
            cout << "Minus operation: " << a << endl;
        } else if (d == 3) {
            cout << "Variabl value: " << a << " " << b << " " << c << endl;
        } else {
            break;
        }
    }
    
}