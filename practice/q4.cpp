#include <iostream>
using namespace std;

int main(){
    int num;
    cout << " Enter the number : ";
    cin >> num;

    int i = 2;
    while( i < num ) {
        if ( num % i == 0) {
            cout << " Not prime " << i << endl;
        }
        else {
            cout << " Prime Number "<< i << endl;
        }
        i++;
    }

    
return 0;
}