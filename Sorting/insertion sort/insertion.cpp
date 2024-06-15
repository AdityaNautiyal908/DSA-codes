#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int> & arr, int n){

}

int main(){
    vector <int> arr = {10,2,4,6,3,7,5};
    cout << " Before sorting the element with insertion sort : " << endl;
    for (auto i:arr){
        cout << i << " ";
    }cout << endl;

    insertion_sort(arr,7);
return 0;
}