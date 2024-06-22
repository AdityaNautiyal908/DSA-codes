#include <iostream>
using namespace std;

void reverse(string &str, int i, int j){

    cout << " call recieved for : " << str << endl;
    // base case
    if(i>j)
    return;

    swap(str[i],str[j]);
    i++,j--;

    // Recursion call
    reverse(str,i,j);

}

int main(){
    string name = "Aditya";
    cout << endl;
    reverse(name,0,name.length()-1);
    cout << " Reverse string : " << name << endl;
    cout << endl;

return 0;
}