#include <iostream>

using namespace std;

int main() {
    char ch;
    cout << "Enter the character: ";
    cin >> ch;

    if(ch >= 'a' && ch <= 'z') {
        cout << "Lower case" << endl;
    }
    else if(ch >= 'A' && ch <= 'Z') {
        cout << "Upper case" << endl;
    }
    else {
        cout << "Numeric value" << endl;
    }

    return 0;
}
    
