#include <iostream>
using namespace std;

int main() {
    int n;
    int sum = 0;
    cout << "Enter a number: ";
    cin >> n;

    int i = 2;
    while( i <= n ){
        if( i % 2 == 0){
            sum += i;
        }
            i++;
    }
    cout << " Sum all even number from 1 to n : " << sum << endl;

    return 0;
}
