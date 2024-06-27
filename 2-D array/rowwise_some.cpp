#include <iostream>
using namespace std;

// to print col wise sum
void printsum_col(int arr[][3],int n, int m){
    cout << " Printing row wise sum ";
    for ( int i=0; i<3; i++){
        int sum = 0;
        for ( int j=0; j<3; j++){
            sum +=  arr[j][i];
        }
        cout << sum << " " ;
    }
}


// to print row wise sum
void printsum_row(int arr[][3],int n, int m){
    cout << " Printing row wise sum ";
    for ( int i=0; i<3; i++){
        int sum = 0;
        for ( int j=0; j<3; j++){
            sum +=  arr[i][j];
        }
        cout << sum << " " ;
    }
}

int main(){
    int arr[3][3];
    cout << " Enter the element : " << endl;
    for ( int i=0; i<3; i++){
        for ( int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }

    cout << " Printing the array " << endl;
    for ( int i=0; i<3; i++){
        for ( int j=0; j<3; j++){
            cout << arr[i][j] << " ";
        } cout << endl;
    }
    // printsum_row(arr,3,3);
    printsum_col(arr,3,3);


return 0;
}