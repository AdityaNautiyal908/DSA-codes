#include <iostream>
using namespace std;

int main(){
    int n;
    char ch = 'a';
    cout << " Enter the level : ";
    cin >> n;
    for ( int i=1; i<=n; i++){
        for ( int j=1; j<=i; j++){
            cout << ch << " ";
        }
        ch++;
        cout << endl;
    }
return 0;
}