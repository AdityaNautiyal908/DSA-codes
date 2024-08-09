#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

double findMaxAverage(std::vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k) return -1.0;
    if (k == n) {
        double totalSum = accumulate(nums.begin(), nums.end(), 0);
        return totalSum / n;
    }

    int maxSum = 0;
    int windowSum = 0;

    windowSum = accumulate(nums.begin(), nums.begin() + k, 0);
    maxSum = windowSum;

    for (int i = k; i < n; i++) {
        windowSum = windowSum + nums[i] - nums[i - k];
        maxSum = std::max(windowSum, maxSum);
    }

    double average = static_cast<double>(maxSum) / k;
    return average;
}

int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    double result = findMaxAverage(nums, k);
    cout << "Max average: " << result << std::endl;
    return 0;
}
