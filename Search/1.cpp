#include <iostream>
using namespace std;

int Minimum(int arr[], int n) {
    if (n == 1) return arr[0];
    if (arr[0] < arr[n-1]) return arr[0];
    int s = 0, e = n - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;

        // Check if mid element is the minimum
        if(arr[mid] < arr[mid-1] && arr[mid] < arr[mid+1]) return mid;
        // Decide whether to go to the left half or the right half
        if (arr[mid] >= arr[s]) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[8] = {11, 12, 15, 18, 2, 5, 6, 8};
    cout << " Minimum element is  : " << Minimum(arr, 8) << endl;
    return 0;
}
