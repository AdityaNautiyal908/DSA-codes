#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int floor(vector<int> &a, int n, int x) {
    int s = 0;
    int e = n - 1;
    int mid;
    int ans = -1;

    while (s <= e) {
        mid = s + (e - s) / 2;

        if (a[mid] <= x) {
            ans = a[mid];
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

int ceil(vector<int> &a, int n, int x) {
    int s = 0;
    int e = n - 1;
    int mid;
    int ans = -1;

    while (s <= e) {
        mid = s + (e - s) / 2;

        if (a[mid] >= x) {
            ans = a[mid];
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    pair<int, int> p;
    p.first = floor(a, n, x);
    p.second = ceil(a, n, x);
    return p;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 8, 10, 10, 12, 19};
    int n = arr.size();
    int x = 5;

    pair<int, int> result = getFloorAndCeil(arr, n, x);
    cout << "Floor: " << result.first << ", Ceil: " << result.second << endl;

    return 0;
}
