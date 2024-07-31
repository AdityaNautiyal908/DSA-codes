#include <iostream>
using namespace std;

int partition(int arr[], int s , int e){
    int pivot = arr[s];

    int cnt = 0;
    for (int i = s+1; i<=e; i++){
        if(arr[i] <= pivot) cnt++;
    }

    // place pivot at right place
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex],arr[s]);


    //left and right
    int i = s , j = e;
    while(i<pivotIndex && j > pivotIndex){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot ){
            j--;
        }
        if(i<pivotIndex && j > pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }

    return pivotIndex;

}

void quicksort(int arr[], int s, int e){
    // base case
    if(s>=e)return;

    //partition
    int p = partition(arr,s,e);

    //left sort karo
    quicksort(arr,s,p-1);

    //Right sort karo
    quicksort(arr,p+1,e); 

}

int main(){
    int arr[] = {5,4,3,10,35,34};
    int n = 6;

    quicksort(arr,0,n-1);
    for(auto i:arr){
        cout << i << " ";
    }cout << endl;
return 0;
}