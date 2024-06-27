#include <iostream>
using namespace std;

int largestSum(int arr[][3], int n, int m){
    int maxi = INT8_MIN;
    int rowIdx = -1;
    for(int i=0; i<3; i++){
        int sum = 0;
        for ( int j=0; j<3; j++){
            sum += arr[i][j];
        }
        if(sum>maxi){
            maxi = sum;
            rowIdx = n;
        }
    }
    cout <<" The maximum sum is : " << maxi << endl;
    return n;
}

int main(){
    int arr[3][3];
    cout << " Enter the element : " << endl;
    for(int i=0; i<3; i++){
        for ( int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }

    cout << " Printing the element " << endl;
    for(int i=0; i<3; i++){
        for ( int j=0; j<3; j++){
            cout << arr[i][j] << " ";
        }
    }cout << endl;

    cout <<" Max row at index " << largestSum(arr,3,3);
return 0;
}