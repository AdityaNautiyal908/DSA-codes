#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int maxSumSubarray(vector<int> arr, int k){
    if(arr.size() < k) {
        return -1;
    }

    int maxSum = 0;
    int windowSum = 0;

    // Calculate the sum of first window
    windowSum = accumulate(arr.begin(), arr.begin()+k,0);    
    maxSum = windowSum;

    // Slide the window from the k-th element to the end of the array
    for ( int i=k; i<arr.size(); i++){
        windowSum = windowSum + arr[i] - arr[i-k];
        maxSum = max(windowSum,maxSum);

    return maxSum;
}
}

int main(){
    vector<int> arr = {5};
    int k = 1;
    cout << "The maximum sum of a subarray of size " << k << " is: " 
    << maxSumSubarray(arr, k) << endl;
return 0;
}