#include <iostream>
using namespace std;

void printArray(int arr[], int size){
    cout<<" "<<"Alternate swap ";
    for( int i=0; i<size; i++){
        cout<<" "<<arr[i];
    }cout<<endl;
}

void swap_alternate(int arr[], int size){
    for( int i=0; i<size; i+=2){
        if(i+1 < size){
            arr[i] = arr[i] + arr[i+1];
            arr[i+1] = arr[i] - arr[i+1];
            arr[i] = arr[i] - arr[i+1]; 
        }
    }
}

int main(){
    int even[8] = {1,2,3,4,5,6,7,8};
    int odd[5] = {4,5,6,2,3};


    swap_alternate(even,8);
    printArray(even,8);

return 0;
}