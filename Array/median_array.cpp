#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    vector<int> nums3;
    int i = 0, j = 0;

    // Merge the two sorted arrays
    while (i < n && j < m) {
        if (nums1[i] < nums2[j]) {
            nums3.push_back(nums1[i++]);
        } else {
            nums3.push_back(nums2[j++]);
        }
    }
    while (i < n) {
        nums3.push_back(nums1[i++]);
    }
    while (j < m) {
        nums3.push_back(nums2[j++]);
    }

    // Calculate the median
    int k = n + m;
    if (k % 2 == 1) {
        // If the total number of elements is odd, return the middle element
        return nums3[k / 2];
    } else {
        // If the total number of elements is even, return the average of the two middle elements
        return (nums3[k / 2] + nums3[k / 2 - 1]) / 2.0;
    }
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Median: " << findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.0

    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "Median: " << findMedianSortedArrays(nums3, nums4) << endl; // Output: 2.5

    return 0;
}
