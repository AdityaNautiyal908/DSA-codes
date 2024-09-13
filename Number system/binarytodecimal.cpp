#include <iostream>
using namespace std;

int BinaryToDecimal(int num){
    int ans = 0;
    int pow = 1;
    while( num > 0 ){
        int reverse = num % 10;
        num /=10;
        ans += (reverse * pow);
        pow *= 2;
    }
    return ans;
}

int main(){
    int num;
    cout << " Enter the binary number : ";
    cin >> num;

    cout << BinaryToDecimal(num) << endl;


return 0;
}