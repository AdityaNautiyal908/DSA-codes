#include <iostream>
using namespace std;

void printArray (char arr[], char size){
    cout<< " Printing array element " << endl;
    for(int i=0; i<size; i++){
        cout << arr[i] << "\t";
    }
}


int main(){
    // int arr[10] = {1,2,4};
    // printArray(arr,10);
    // int size = sizeof(arr)/sizeof(int);
    // cout << endl << "size of array : " << size; 

    char ch[5] = {'a','e','i','o','u'};
    printArray(ch,5);
    return 0;
}