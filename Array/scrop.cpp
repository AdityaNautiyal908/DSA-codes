#include <iostream>
using namespace std;

void update(int arr[], int n){
    arr[0]=123;
    cout<<"Before update the value"<<endl;
    for(int i=0; i<n; i++){
        cout<<" "<<arr[i];
    }cout<<endl;
    cout<<"After update print the value"<<endl;
}

int main(){
    int arr[3] = {1,2,3};
    int n = 3;

    update(arr,n);

    for( int i=0; i<n; i++){
        cout<<" "<< arr[i];
    }


return 0;
}