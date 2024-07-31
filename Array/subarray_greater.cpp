#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums){
    int n = nums.size();
    int maxSum = 0;
    int windowSum = 0;
    int k = 4;

    if(n==1) return nums[0];

    // maximum of all element 
    maxSum = accumulate(nums.begin(),nums.end(),0);

    // Calculate the sum of first window
    windowSum = accumulate(nums.begin(), nums.begin()+k,0);


    for ( int i=k; i<n; i++){
        windowSum = windowSum + nums[i] - nums[i-k];
        maxSum = max(windowSum,maxSum);
    }
    return maxSum;
}

int main(){
    vector<int> nums = {5,4,-1,7,8};
    cout << maxSubArray(nums) << endl;
return 0;
}