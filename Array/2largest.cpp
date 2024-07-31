#include <iostream>
#include <climits>
#include <vector>

using namespace std;

pair<int,int> findSecondLargest(vector<int> &nums){
    if(nums.size() < 2){
        cerr << " Array should have atleast 2 element " << endl;
        return {INT_MIN,INT_MIN};
    }

    int largest = INT_MIN;
    int second_largest = INT_MIN;

    for(auto num : nums){
        if(num > largest){
            second_largest = largest;
            largest = num;
        }
        else if ( num > second_largest && num != largest){
            second_largest = num;
        }
    }

    if(second_largest == INT_MIN){
        cerr<< " No second largest element found " << endl;
    }

    return {largest,second_largest};
}

int main(){
    vector<int> nums = {12, 35, 1, 10, 34, 1};
    pair<int,int> result = findSecondLargest(nums);

    if (result.second != INT_MIN) {
        cout << "The largest element is: " << result.first << endl;
        cout << "The second largest element is: " << result.second << endl;
    } else {
        cerr << "Could not find the second largest element." << endl;
    }

return 0;
}
