#include <iostream>
using namespace std;


void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i]<<" ";
    }
    cout<<endl;
}



int main(){
    int arr[100];
    //Syntax to fill all the array with same value
    // fill(arr, arr+100, 42); 
    fill_n(arr,100,-5);
    printArray(arr,100);
return 0;
}