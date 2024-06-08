// 283

#include <iostream>
#include <vector>
using namespace std;

void movesZeroes(vector<int> &nums){
    int noneZero = 0;
    for ( int j = 0; j<nums.size(); j++){
        if(nums[j] != 0){
            swap(nums[j],nums[noneZero]);
            noneZero++;
        }
    }
}

void print(vector<int> ans){
    for ( int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }cout << endl;
}

int main(){
    vector <int> nums = {0,1,0,3,12};

    movesZeroes(nums);
    print(nums);

return 0;
}