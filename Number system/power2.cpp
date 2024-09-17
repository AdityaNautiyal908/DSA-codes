#include <iostream>
using namespace std;

bool isPowerOfTwo(int num) {
    if (num <= 0) return false;  // Negative numbers and zero cannot be powers of 2
    
    int count = 0;
    
    // Count how many bits are set to 1
    while (num > 0) {
        count += (num & 1);  // Check if the last bit is 1
        num >>= 1;  // Right shift the number by 1 (equivalent to dividing by 2)
    }
    
    // If exactly one bit is set to 1, it's a power of 2
    return count == 1;
}

int main() {
    int num;
    cout << "Enter the number: ";
    cin >> num;

    if (isPowerOfTwo(num)) {
        cout << "True, the number is a power of 2." << endl;
    } else {
        cout << "False, the number is not a power of 2." << endl;
    }

    return 0;
}
