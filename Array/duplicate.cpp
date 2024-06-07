#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) return 0;

    int j = 1; // Initialize j with 1 for the first element
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[i - 1]) { // Compare current element with previous element
            nums[j] = nums[i]; // Store unique elements and update j
            j++;
        }
    }
    return j;
}

int main() {
    vector<int> nums(6);

    cout << "Enter the elements: ";
    for(int i = 0; i < 6; i++) {
        cin >> nums[i];
    }

    cout << "Original elements: ";
    for(auto i : nums) {
        cout << i << " ";
    }
    cout << endl;

    int uniqueCount = removeDuplicates(nums);

    cout << "Unique elements: ";
    for(int i = 0; i < uniqueCount; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
