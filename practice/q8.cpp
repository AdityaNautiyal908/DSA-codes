#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> &v, int key){
    int start = 0;
    int end = v.size() - 1;
    int mid = (start + end) / 2;

    while ( start <= end){
        if(v[mid] == key){
            return mid;
        }
        else if ( v[mid] > key){
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
        mid = (start + end)/2;
    }
    return -1;
}

int main(){
    vector <int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(9);
    v.push_back(10);
    v.push_back(1);

    sort(v.begin(),v.end());

    for ( auto i : v){
        cout << i << " ";
    }cout << endl;

    int key;
    cout << " Enter the element you want to know the index : ";
    cin >> key;

    int search = BinarySearch(v,key);
    cout << " 4 is at index : " << search << endl;
}