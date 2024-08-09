#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int MissingNumber(vector<int> nums){
    int n = nums.size();
    int sum = n*(n+1)/2;
    int arrySum = accumulate(nums.begin(),nums.end(),0);
    return sum - arrySum;

}

int main(){
    vector<int> nums = {3,0,1,5,4};
    cout << MissingNumber(nums);
return 0;
}