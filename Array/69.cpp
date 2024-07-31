#include <iostream>
using namespace std;

int maximum69Number(int num){
    // Convert the number to a string
    string numStr = to_string(num);

     // Traverse the string and find the first '6'
    for(char &c : numStr){
        if(c=='6'){
            c='9';
            break; // Change only the first '6' and exit the loop
        }
    }
    // Convert the modified string back to an integer
    return stoi(numStr);
}

int main(){
    int num = 9996;
    cout << " Maximum number is : " << maximum69Number(num) << endl;
return 0;
}