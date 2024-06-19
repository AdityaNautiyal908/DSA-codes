#include <iostream>
using namespace std;

void printA(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            if ((j == n - i) || (j == n + i))
                cout << "#";
            else if (i == n / 2 && j > n - i && j < n + i)
                cout << "#"; 
            else
                cout << " ";
        }
        cout << endl;
    }

}

int main() {
    int n;
    cout << "Enter the height of the letter A : ";
    cin >> n;

    printA(n);

    return 0;
}
