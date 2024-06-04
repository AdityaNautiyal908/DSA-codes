#include <iostream>
using namespace std;

bool duplicate(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {  // start j from i+1 to avoid self-comparison
            if (arr[i] == arr[j]) {
                return true;  // found a duplicate
            }
        }
    }
    return false;  // no duplicates found
}

int main() {
    int arr[4] = {1, 2, 3, 1};
    bool repeat = duplicate(arr, 4);
    cout << "Repeat element found: " << (repeat ? "Yes" : "No") << endl;

    return 0;
}
