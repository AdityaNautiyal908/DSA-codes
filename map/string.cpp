#include <iostream>
#include <string>
#include <map>

using namespace std;

void countFrequency(string& str) {
    map<char, int> frequencyMap;

    // Iterate over the string and update the frequency map
    for (char ch : str) {
        frequencyMap[ch]++;
    }

    // Display the frequency of each character
    for (auto pair : frequencyMap) {
        cout << "Character '" << pair.first << "' appears " << pair.second << " times." << endl;
    }
}

int main() {
    string str = "hello world";
    countFrequency(str);

    return 0;
}
