// 191 Question in leet code
#include <iostream>
using namespace std;

int main(){
    int n;
    int count = 0;
    cout<<"Enter the value of n : ";
    cin>>n;

    while(n != 0){
        if(n & 1){
            count ++;
        }
        n = n>>1;
    }
    cout<<"Value of count "<<count;


return 0;
}