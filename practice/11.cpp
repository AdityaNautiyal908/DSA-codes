#include <iostream>
using namespace std;

void reverseString(string &str, int start, int end) {
    // Base case
    if (start >= end) return;
    // Swap characters
    swap(str[start], str[end]);
    // Recursive case
    reverseString(str, start + 1, end - 1);
}

int main(){
    string name;
    cin >> name;
    reverseString(name, 0, name.size() - 1);
    cout << name << endl;
    return 0;
}
