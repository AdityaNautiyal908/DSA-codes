#include <iostream>
using namespace std;

long long int SquareRoot(int num){
    if(num==0 || num == 1)
    return num;

    int s = 0; 
    int e = num;
    long long int ans = -1;
    long long int mid = s + (e-s) / 2;

    while ( s<=e){

    long long int square = mid * mid;

    if( square == num ){
        return mid;
    }
    else if( square > num ) {
        e = mid - 1;
    }
    else {
        ans = mid;
        s = mid + 1;
    }
    mid = s + (e-s) / 2;
    }
    return ans;
}

double morePrecision(int n, int precision, int tempSol) {
    double factor = 1;
    double ans = tempSol;
    for ( int i = 0; i<precision; i++){
        factor = factor/10;
        for ( double j = ans; j*j<n; j= j + factor) {
            ans = j;
        }
    }
    return ans;
}

int main(){
    int n;
    cout << " Enter the number : ";
    cin >> n;

    int tempSol = SquareRoot(n);
    cout << " Answer is : " << morePrecision( n, 3, tempSol ) << endl;

return 0;
}