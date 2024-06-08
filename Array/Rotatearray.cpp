// 189 leet code problem rotate array element;

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector <int> &nums, int k){
    vector<int> temp(nums.size());
    for ( int i=0; i<nums.size(); i++){
        temp[(i+k) % nums.size()] = nums[i];
    }
    nums = temp;
}

void print(vector<int> nums){
    for ( int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }cout << endl;
}
int main(){
    vector<int> nums = {1,2,3,4};
    int k = 3;
    rotate(nums,k);
    cout << "Rotating the array by 3" << endl;
    print(nums);
return 0;
}