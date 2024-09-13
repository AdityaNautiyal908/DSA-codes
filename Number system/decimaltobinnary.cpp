#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DeciamlToBinary(int num){
    int ans = 0;
    int pow = 1;
    while(num > 0){
        int remainder = num % 2;
        num = num / 2; 
        ans += (remainder * pow);
        pow *= 10;
    }
    return ans;
}

int main(){
    // int num;
    // cout << " Enter your number : ";
    // cin >> num;
    

    for ( int i=1; i<=10; i++){
        cout << DeciamlToBinary(i) << endl;
    }

return 0;
}