#include <iostream>
using namespace std;

int firstOcc(int arr[], int s, int e, int k) {
    if (s > e) {
        return -1; // Base case: element not found
    }

    int mid = s + (e - s) / 2;

    // if element is found
    if (arr[mid] == k) {
        // Check if this is the first occurrence
        if (mid == 0 || arr[mid - 1] < k) {
            return mid; // Return the index of first occurrence
        } else {
            // Continue searching in the left half
            return firstOcc(arr, s, mid - 1, k);
        }
    } else if (arr[mid] > k) {
        return firstOcc(arr, s, mid - 1, k); // Search in the left half
    } else {
        return firstOcc(arr, mid + 1, e, k); // Search in the right half
    }
}

int main() {
    int arr[7] = {1, 3, 2, 2, 2, 4, 5};
    int size = 7;
    int key = 2;

    int result = firstOcc(arr, 0, size - 1, key);
    if (result != -1) { // Check if element was found (result is not -1)
        cout << "First occurrence of " << key << " is at index " << result << endl;
    } else {
        cout << "Element " << key << " not found in the array." << endl;
    }

    return 0;
}
