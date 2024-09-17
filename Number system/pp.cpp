/**
 * The above C++ program defines functions to calculate the sum and product of an array, swap the
 * maximum and minimum elements, and attempts to find unique values in the array.
 * 
 * @param arr The `arr` parameter in the code represents an array of integers. In the `main` function,
 * an array `arr` is defined with values {1, 2, 1, 3, 4, 1, 3}.
 * @param size The `size` parameter in the functions and arrays represents the number of elements in
 * the array. It is used to determine the length of the array and iterate over its elements in loops.
 * In the `main` function, the `size` variable is set to 7, indicating that the array `
 * 
 * @return The program returns the sum of the array elements, the product of the array elements, and
 * the array after swapping the maximum and minimum elements.
 */
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int sumofArray(int arr[],int size){
    int sum = 0;
    for ( int i=0; i<size; i++){
        sum += arr[i];
    }
    return sum;
}

int ProductofArray(int arr[], int size){
    int product = 1;
    for ( int i = 0; i<size; i++){
        product *= arr[i];
    }
    return product;
}

void swapMaxandMin ( int arr[], int size){
    int maxi = INT_MIN;
    int mini = INT_MAX;
    int maxIndex = -1;
    int minIndex = -1;

    for (int i = 0; i < size; i++){
        if (arr[i] > maxi){
            maxi = arr[i];
            maxIndex = i;
        }
        if (arr[i] < mini){
            mini = arr[i];
            minIndex = i;
        }
    }

    // Swap the elements at maxIndex and minIndex
    swap(arr[maxIndex], arr[minIndex]);
}

void UniqueValues(int arr[], int size){
    for ( int i=0; i<size; i++){
        for ( int j = i+1; i<size; j++){
            if(arr[i] != arr[j]){
                
            }
        }
    }
}

int main(){
    int arr[] = {1,2,1,3,4,1,3};
    int size = 7;

    cout << "Sum of array : " << sumofArray(arr,size) << endl;
    
    cout << " Product of array : " << ProductofArray(arr,size) << endl;

    swapMaxandMin(arr,size);

    for ( int i=0; i<size; i++){
        cout << arr[i] << " ";
    }cout << endl;
    
return 0;
}