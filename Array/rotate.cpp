// 1752 rotate and check if array is sorted or not

#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &nums){
    int count = 0;
    int n = nums.size();
    for ( int i = 0; i<n; i++){
        if( nums[i] <= nums[i+1]){
            continue;
        }
        else {
            count ++;
        }
    }
        if(nums[n-1] > nums[0]){
            count++;
        }
    return count<=1;
}

int main(){
    vector<int> nums = {3,4,5,1,2};
    vector<int> nums2 = {2,1,3,4};
    vector<int> nums3 = {1,2,3};
    vector<int> nums4 = {1,1,1};

    cout << " Check if value is true or not : " << check(nums) << endl;
    cout << " Check if value is true or not : " << check(nums2) << endl;
    cout << " Check if value is true or not : " << check(nums3) << endl;
    cout << " Check if value is true or not : " << check(nums4) << endl;
return 0;
}