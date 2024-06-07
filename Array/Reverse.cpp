#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reverse(vector<int> & v, int size){
    int start = 0;
    int end = v.size() - 1;
    while(start <= end){
        swap(v[start++],v[end--]);
    }

}

int main(){
    vector <int> v = {7,6,5,4,3,2,1};    

    cout << " Before reverse : ";
    for ( auto i : v){
        cout << i << " ";
    }cout << endl;

    reverse(v,7);

    cout << " After swapping : ";
    for ( auto i : v) {
        cout << i << " ";
    }cout << endl;

return 0;
}