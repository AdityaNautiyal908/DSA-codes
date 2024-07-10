#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    set<int> tempSet;
    int i = 0;
    int j = 0;
    while(i < nums1.size() && j < nums2.size()) {
        if(nums1[i] < nums2[j]) {
            i++;
        }
        else if(nums1[i] > nums2[j]) {
            j++;
        }
        else {
            tempSet.insert(nums1[i]);
            i++;
            j++;
        }
    }
    return vector<int>(tempSet.begin(), tempSet.end());
}

int main(){
    vector<int> nums1 = {1, 2, 2, 1, 3};
    vector<int> nums2 = {2, 2, 3};

    vector<int> result = intersection(nums1, nums2);

    cout << "Answer is : ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
