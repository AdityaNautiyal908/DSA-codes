#include <iostream>
using namespace std;

void hollowDiamond(int n){
    for ( int i=0; i<n; i++){
        for ( int j=0; j<(2*n); j++){

            if(i+j <= n-1)
            cout << "*";

            else
            cout << " ";

            if((i+n) <=j)
            cout << "*";

            else 
            cout << " ";
        }
        cout << endl;
    }

    for ( int i=0; i<n; i++){
        for ( int j=0; j<(2*n); j++){
            if(i>=j)
            cout << "*";

            else 
            cout << " ";
            if(i>=(2*n-1)-j)

            cout << "*";
            else
            cout << " ";
            
        }
    cout << endl;
    }
}

int main(){
    int n;
    cout << " Enter the level : ";
    cin >> n;

    hollowDiamond(n);
return 0;
}