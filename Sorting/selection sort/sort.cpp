#include <iostream>
#include <vector>
#include <algorithm> // Include <algorithm> for swap

using namespace std;

void SelectionSort(vector<int> &v) {
    for (int i = 0; i < v.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        swap(v[minIndex], v[i]); // Move the swap statement inside the outer loop
    }
}

int main() {
    vector<int> v;

    cout << "Enter the elements of vector (enter -1 to stop): ";
    int num;
    while (cin >> num && num != -1) {
        v.push_back(num);
    }

    cout << "Elements of vector before sorting: ";
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;

    SelectionSort(v); // Call SelectionSort to sort the vector in place

    cout << "Elements of vector after sorting: ";
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
