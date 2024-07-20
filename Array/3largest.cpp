#include <iostream>
#include <vector>
#include <set>
#include <limits.h> // For INT_MIN

using namespace std;

int thirdMax(vector<int>& nums) {
    set<int> st;
    for (int num : nums) {
        st.insert(num);
    }

    // If there are less than 3 unique elements, return the maximum
    if (st.size() < 3) {
        return *st.rbegin(); // rbegin() gives reverse iterator, so *rbegin() gives the maximum element
    }

    // Otherwise, find the third maximum
    auto it = st.rbegin();
    advance(it, 2); // Move iterator to the third maximum element
    return *it;
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    cout << "Third maximum element is: " << thirdMax(nums) << endl;
    return 0;
}
