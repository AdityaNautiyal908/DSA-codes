#include <iostream>
#include <vector>

using namespace std;

void Selection_Sort (vector <int> &v , int n) {
    for ( int i = 0; i<n-1; i++){
        int minIndex = i;
        for ( int j = i+1; j<n; j++){
            if(v[j] < v[minIndex])
                minIndex = j;
        }
        swap(v[i], v[minIndex]);
    }
}

int main(){
    int n = 5;
    vector<int> v = {50,40,30,10,10};    
    Selection_Sort(v,n);

    cout << " Selection Sort : " << endl;
    for ( auto i : v){
        cout << i << "   ";
    }cout << endl;
return 0;
}