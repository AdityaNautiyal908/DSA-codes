#include <iostream>
using namespace std;

string replaceSpaces(string &arr){
    string temp = "";
    for ( int i=0; i<arr.length(); i++){
        if(arr[i] == ' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else {
            temp.push_back(arr[i]);
        }
    }
    return temp;
}

int main(){
    string arr = "My name is khan";

    string print = replaceSpaces(arr);
    cout << print << endl;
return 0;
}