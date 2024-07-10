#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
private:
    int findMax(vector<int> &v) {
        int maxi = INT_MIN;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    int CalculateTotalHours(vector<int> &v, int hourly) {
        int totalH = 0;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            totalH += ceil((double)v[i] / (double)hourly);
        }
        return totalH;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1, e = findMax(piles);
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int totalH = CalculateTotalHours(piles, mid);
            if (totalH <= h) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    vector<int> piles = {3, 6, 7, 11};  // Example input
    int h = 8;
    cout << "Minimum eating speed: " << sol.minEatingSpeed(piles, h) << endl;
    return 0;
}
