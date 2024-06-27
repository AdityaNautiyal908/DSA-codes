#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCol){
    vector<int> ans;
    cout << " Printing in wava form " << endl;
    for ( int col = 0; col<mCol; col++){
        if(col & 1){
            // bottom to top
            for ( int row = nRows-1; row>=0; row--){
                cout << arr[row][col] << " "; 
                ans.push_back(arr[row][col]);
            }
        }
        else {
            // top to bottom
            for ( int row = 0; row<=nRows-1; row++){
                cout << arr[row][col] << " "; 
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> arr(3, vector<int>(3)); 
    cout << " Enter the element " << endl;
    for ( int i=0; i<3; i++){
        for ( int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }

    cout << " Print element in normal form" << endl;
    for ( int i=0; i<3; i++){
        for ( int j=0; j<3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;   
    }
    cout << endl;
    wavePrint(arr,3,3);


return 0;
}