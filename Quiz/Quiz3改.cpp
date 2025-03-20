#include <iostream>
using namespace std; 

class MenuProgram {
    public: 
        int a = 3;
        int b = 5; 
        int c = 0;
        int d = 0;

    void display_menu (){
        cout << "1. add operation" << endl;
        cout << "2. minus operation" << endl;
        cout << "3. display all variable value" << endl;
        cout << "4. quit" << endl;
        cin >> d;
    } 

    void display_outcome() {
        cout << "All variable value: " << a << " " << b << " " << c << endl;

    }

    void run (){
        display_menu();

        while (d != 4){
            if (d == 1){
                c = a + b;
                cout << "Add operation: " << c << endl;
            } else if (d == 2) {
                a = c - 2;
                cout << "Minus operation: " << a << endl;
            } else if (d == 3) {
                display_outcome();
            }
            
            display_menu();
        } 
    }
};

main(){
    MenuProgram menuProgram;
    menuProgram.run();
}