#include <iostream>
#include <vector>
using namespace std;

void swapArray( vector <int> &v , int size){
    int s = 0; 
    int e = size - 1;
    while (s < e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
}

int main(){
    vector <int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(6);
    v.push_back(7);

    for ( auto i:v){
        cout << i << " ";
    }cout << endl;

    
    swapArray(v, 5);
    for ( int i:v){
        cout << i << " ";
    }
return 0;
}