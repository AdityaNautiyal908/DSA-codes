#include <iostream>
#include <vector>

using namespace std;


bool isPossible(vector<int> &boards, int k, int mid) {
    int Painter = 1;
    int BoardSum = 0;

    for( int i=0; i<=boards.size()-1; i++){
        if(BoardSum + boards[i] <= mid){
            BoardSum += boards[i];
        }
        else {
            Painter++;
            if(Painter > k || boards[i] > mid){
                return false;
            }
            BoardSum = 0;
            BoardSum += boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = 0;
    int sum = 0;
    int ans = -1;
    for ( int i = 0; i<=boards.size()-1; i++){
        sum += boards[i];
    }
    int e = sum;
    int mid = s + (e-s) / 2;

    while ( s<=e){
        if(isPossible(boards,k,mid)){
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e-s) / 2;
    }
    return ans;
}


int main(){
    vector <int> arr = {2,1,5,6,2,3};
    int k = 2;

    cout << " Answer is : " << findLargestMinDistance(arr,k) << endl;
}