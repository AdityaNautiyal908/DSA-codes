#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> &v, int size,int k){
    for ( int i=0; i<size; i++){
        if(v[i] == k){
            return i;
        }
    }
        return -1;
}

int main(){
    vector <int> v = {2,3,4,5,6};

    for ( auto i : v){
        cout << i << " ";
    }cout << endl;

    cout << " Linear search : " << linearSearch(v,v.size(),7) << endl;
return 0;
}