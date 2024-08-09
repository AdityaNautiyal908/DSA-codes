#include <iostream>
#include <vector>
#include <map>

using namespace std;

void countFrequency(vector<int>& arr) {
    map<int, int> frequencyMap;

    // Iterate over the array and update the frequency map
    for (int num : arr) {
        frequencyMap[num]++;
    }
    // Display the frequency of each element
    for (auto pair : frequencyMap) {
        cout << "Element " << pair.first << " appears " << pair.second << " times." << endl;
    }

}

int main() {
    vector<int> arr = {1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4};
    countFrequency(arr);

    return 0;
}
