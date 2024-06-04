// STL of array
#include <iostream>
#include <array>
using namespace std;

int main(){
    int basic[3] = {1,2,3}; 
    array<int,4> a = {1,2,3,4}; // implementation fixed size ka array se hoti hai , static array

    int size = a.size();

    for(int i=0; i<size; i++){
        cout<<a[i]<<endl;
    }
    cout<<"Element at 2nd Index->"<<a.at(2)<<endl; // Element at second index
    
    cout<<"Empty or not->"<<a.empty()<<endl; // Empty or not return 0 or 1

    cout<<"First Element->"<<a.front()<<endl; // First element

    cout<<"Last Element->"<<a.back()<<endl; // last element
    
return 0;
}