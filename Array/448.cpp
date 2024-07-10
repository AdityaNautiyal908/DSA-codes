#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    // Mark elements as visited by setting the value at corresponding index negative
    for (int i = 0; i < n; i++) {
        int index = abs(nums[i]) - 1; // Find the corresponding index
        if (nums[index] > 0) {
            nums[index] = -nums[index]; // Mark as visited
        }
    }

    // Collect the indices that are still positive
    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            result.push_back(i + 1);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = findDisappearedNumbers(nums);

    cout << "Missing numbers: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}