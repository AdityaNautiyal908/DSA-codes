#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        int ans = INT16_MAX;
        while(s<=e){
            if(nums[s] <= nums[e]){
                ans = min(ans,nums[s]);
                break;
            }

            if(nums[s] <= nums[mid]){
                ans = min(ans,nums[s]);
                s = mid + 1;
            }
            else {
                ans = min(ans,nums[mid]);
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }

int main(){
    vector<int> v = {11,13,15,17};

    cout << " Minimum element is : " << findMin(v);
return 0;
}