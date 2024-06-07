#include <iostream>
#include <vector>
#include <limits.h> // For INT_MAX and INT_MIN

using namespace std;

void findLargestAndSmallest(const vector<int>& v, int& largest, int& smallest) {
    largest = INT_MIN; // Initialize largest to the smallest possible integer
    smallest = INT_MAX; // Initialize smallest to the largest possible integer

    for (int num : v) {
        if (num > largest) {
            largest = num;
        }
        if (num < smallest) {
            smallest = num;
        }
    }
}

int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(6);
    v.push_back(7);

    // Print the original array
    cout << "Array elements: ";
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;

    int largest, smallest;
    findLargestAndSmallest(v, largest, smallest);

    // Print the largest and smallest elements
    cout << "Largest element: " << largest << endl;
    cout << "Smallest element: " << smallest << endl;

    return 0;
}
