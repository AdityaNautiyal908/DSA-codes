#include <iostream>
#include <vector>
using namespace std;

// Modified insertion_sort to return the sorted array
vector<int> insertion_sort(vector<int>& arr, int n) {
    vector<int> ans = arr; // Copy original array to ans

    // Start from the second element (index 1)
    for (int i = 1; i < n; i++) {
        int key = ans[i];  // The element to be positioned
        int j = i - 1;
        
        // Move elements of ans[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && ans[j] > key) {
            ans[j + 1] = ans[j];
            j--;
        }
        
        // Place the key in its correct position
        ans[j + 1] = key;
    }

    return ans; // Return sorted array
}

int main() {
    vector<int> arr = {10, 2, 4, 6, 3, 7, 5};
    cout << "Before sorting with insertion sort: " << endl;
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    // Get the sorted array in ans
    vector<int> ans = insertion_sort(arr, arr.size());

    cout << "After sorting with insertion sort: " << endl;
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
