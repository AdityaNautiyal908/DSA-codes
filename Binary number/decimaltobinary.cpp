#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    string ans = "";
    
    if(n == 0) {
        ans = "0";
    }
    
    while(n != 0) {
        int bit = n & 1;
        ans = to_string(bit) + ans;
        n = n >> 1;
    }

    cout << "Answer is: " << ans;
    return 0;
}
