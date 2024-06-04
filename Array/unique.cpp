#include <iostream>
using namespace std;

int findUnique(int arr[], int size){
    int ans = 0;
    for(int i = 0; i<size; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

void printArray(int arr[], int size){
    cout<<" Array element " <<endl;
    for( int i = 0; i<size; i++){
        cout<<" "<<arr[i];
    }cout<<endl;
}

int main(){
    int M = 3;
    int N = (2*M) + 1;
    int arr[N] = {2,7,3,2,7,3,4};

    int unique = findUnique(arr, N);
    printArray(arr,N);
    cout<<" Unique element is "<<unique;
    

return 0;
}