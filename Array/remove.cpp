#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[count++] = nums[i];
        }
    }
    return count;
}

int main() {
    vector<int> nums(4);

    cout << "Enter the elements: ";
    for (int i = 0; i < nums.size(); i++) {
        cin >> nums[i];
    }

    cout << "Before removing element: ";
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;

    int val;
    cout << "Enter the element to remove: ";
    cin >> val;

    int remaining = removeElement(nums, val);

    cout << "Remaining Elements: ";
    for (int i = 0; i < remaining; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
