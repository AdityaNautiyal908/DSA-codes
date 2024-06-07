#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int firstOccur(vector<int> &arr, int n, int key){
    int ans = -1;
    int s = 0, e = n-1;
    int mid = s + (e - s) / 2;

    while (s <= e) {

    if ( arr[mid] == key){
        ans = mid;
        e = mid - 1;
    }

    else if (arr[mid] > key){
        e = mid - 1;
    }
    else {
        s = mid + 1;
    }
    mid = s + (e - s) / 2;
    }
    return ans;
}

int lastOccur(vector<int> &arr, int n, int key){
    int ans = -1;
    int s = 0, e = n-1;
    int mid = s + (e - s) / 2;

    while(s <= e) {

    if ( arr[mid] == key){
        ans = mid;
        s = mid + 1;
    }

    else if (arr[mid] > key){
        e = mid - 1;
    }
    else {
        s = mid + 1;
    }
    mid = s + (e - s) / 2;
    }
    return ans;
}

int main () {
    vector <int> arr = {1,2,3,3,3,3,3,3,3,3,3,3,5,5};

    for ( auto i:arr){
        cout << i << " ";
    }cout << endl;


    pair<int,int> p;
    p.first = firstOccur(arr,arr.size(),3);
    p.second = lastOccur(arr,arr.size(),3);
    

    cout << " First Occurrence of element at Index : " << p.first << endl;
    cout << " Last Occurrence of element at Index : " << p.second << endl;
    
    if (p.first == -1 || p.second == -1) {
        cout << "Element not found in the array." << endl;
    } else {
        cout << "Total number of Occurrences of element: " << (p.second - p.first) + 1 << endl;
    }

    return 0;
}