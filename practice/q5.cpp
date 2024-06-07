#include <iostream>
#define MAX 5
using namespace std;

int sumofArray(int arr[], int size){
    int sum = 0;
    for ( int i=0; i<size; i++){
        sum = arr[i] + sum;
    }
    return sum;
}

int main(){
    int arr[MAX];
    cout << " Enter the element of array : ";
    for ( int i=0; i<MAX; i++){
        cin >> arr[i];
    }

    int sum = sumofArray(arr,MAX);
    cout << " Sum of all element in the array : " << sum << endl;

return 0;
}