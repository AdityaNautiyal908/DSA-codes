#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int total = 0;
    int k = flowerbed.size();
    for (int i = 0; i < k && total < n; i++) {
        if (flowerbed[i] == 0) {
            int next = (i == k - 1) ? 0 : flowerbed[i + 1];
            int prev = (i == 0) ? 0 : flowerbed[i - 1];
            
            if (next == 0 && prev == 0) {
                flowerbed[i] = 1;
                total++;
            }
        }
    }
    return total >= n;
}

int main(){
    vector<int> flowerbed = { 1,0,0,0,1};
    cout << " Can plant or not : " << canPlaceFlowers(flowerbed,2);
}