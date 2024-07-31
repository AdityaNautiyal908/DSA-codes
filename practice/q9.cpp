#include <iostream>
using namespace std;

bool isSorted(int *arr, int size){
    // base case
    if(size <= 1) return true;

    if(arr[0] > arr[1]) return false;

    bool remainingPart = isSorted(arr+1 , size-1);
    return remainingPart;

}

int main(){
    int arr[] = {1,2,3,4,8,6};
    bool ans =  isSorted(arr,6);

    if(ans){
        cerr << " Array is Sorted " << endl;
    }

    else {
        cerr << " Not sorted " << endl;
    }
return 0;
}