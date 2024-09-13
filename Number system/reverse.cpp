#include <iostream>
using namespace std;

int reverse(int num){
    int reverse = 0;
    while( num != 0){
        int remainder = num % 10;
        num /= 10;
        reverse = (reverse * 10) + remainder;
    }
    return reverse;
}

int main(){
    int n;
    cout << " Enter the number : ";
    cin >> n;
    cout << reverse(n);
return 0;
}