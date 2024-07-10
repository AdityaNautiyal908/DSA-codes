#include <iostream>
using namespace std;

int search_element(int arr[],int n, int target){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<=e){
        if(arr[mid] == target){
            return mid;
        }
        // left sorted
        if(arr[mid] >= arr[s]){
            if(arr[s] <= target && target <= arr[mid])
            e = mid -1;
            else 
            s = mid + 1;
        }
        // right sorted
        else {
            if(arr[mid] <= target && target <= arr[e])
            s = mid + 1;
            else 
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

int main(){
    int arr[10] = {7,8,9,1,2,3,4,5,6,10};
    int n = 10;
    int target = 4; 

    cout << " Element is found : " << search_element(arr,n,target);
return 0;
}