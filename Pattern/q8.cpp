#include <iostream>
using namespace std;

int main(){
    int n;
    cout << " Enter the level : ";
    cin >> n;
    for ( int i = n; i>=1; i--){
        for ( int j = i; j>0; j--){
            cout << (n-i)+1;
        }
        cout << endl;
    }
return 0;
}