#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> reverse(vector<int> & v, int size,int k){
    int start = k+1;
    int end = size-1;

    while(start <= end) {
        swap(v[start++],v[end--]);
    }
    return v;
}

int main(){
    vector <int> v = {7,6,5,4,3,2,1};    

    cout << " Before reverse : ";
    for ( auto i : v){
        cout << i << " ";
    }cout << endl;

    reverse(v,7,3);

    cout << " After swapping : ";
    for ( auto i : v) {
        cout << i << " ";
    }cout << endl;

return 0;
}