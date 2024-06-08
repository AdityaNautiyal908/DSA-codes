#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = 0, j = 0, k = m; 

    while (i < m && j < n) {
        if (nums2[j] < nums1[i]) {
            swap(nums1[i], nums2[j]);
            sort(nums2.begin(), nums2.end()); 
        }
        i++;
    }

    while (j < n) {
        nums1[k++] = nums2[j++];
    }
}

void print(vector<int> &ans, int size) {
    for (int i = 0; i < size; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {1, 2, 3};

    merge(nums1, 3, nums2, 3);
    print(nums1, 6);

    return 0;
}
