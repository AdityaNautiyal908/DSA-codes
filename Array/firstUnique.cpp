#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        // Create a frequency array of size 26 initialized to 0
        vector<int> freq(26, 0);

        // Populate the frequency array using a normal for loop
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        // Find the first unique character using a normal for loop
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        // If no unique character is found, return -1
        return -1;
    }
};

int main() {
    Solution solution;
    string s = "loveleetcode";
    int index = solution.firstUniqChar(s);
    cout << "The index of the first non-repeating character is: " << index << endl;
    return 0;
}
