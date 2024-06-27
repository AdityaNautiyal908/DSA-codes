#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);

    for ( auto i:v){
        cout << i << " ";
    }cout << endl;

    cout << " Present or Not : " << binary_search(v.begin(),v.end(),6) << endl;

    cout << " Lower bound : " << lower_bound(v.begin(),v.end(),5) -v.begin() << endl;

    cout << " Upper bound : " << upper_bound(v.begin(),v.end(),5) -v.begin() << endl;

    sort(v.begin(),v.end());

    cout << " After sorting " << endl;
    for ( auto i:v){
        cout << i << " ";
    }cout << endl;

return 0;
}