#include <iostream>
#include <vector>
using namespace std;

int peakElement(vector<int> & ans){
    int s = 0;
    int e = ans.size()-1;
    int mid = s + (e-s)/2;

    while ( s<e){

    if(ans[mid] < ans[mid+1]){
        s = mid + 1;
    }
    else {
        e = mid;
    }
    mid = s + (e-s)/2;
    }
    return e;
    
}

int main(){
    vector <int> arr = {3,4,5,3,1};
    cout << " Peak Element is : " << peakElement(arr) << endl;
return 0;
}