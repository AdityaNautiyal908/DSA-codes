#include <iostream>
using namespace std;

bool PowerofTwo(int num){
    if ( num <= 0) return false;

    while(num > 1){
        if ( num % 2 == 0){
            num = num / 2;
        }
        else {
            return false;
        }
    }
    return true;
}

int main(){
    int num;
    cout << " Enter the number : ";
    cin >> num;
    int ans = PowerofTwo(num);

    if(ans){
        cout << "True";
    }
    else {
        cout << "false";
    }
return 0;
}