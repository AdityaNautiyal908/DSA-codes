#include <iostream>
using namespace std;

bool checkPalindrome(string str, int i, int j){
    // base case
    if(i>j)
    return true;

    if(str[i] != str[j])
    return false;

    else {
        // Recursive call
        return checkPalindrome(str,i+1,j-1);
    }
}

int main(){
    string name = "book";

    bool isPalindrome = checkPalindrome(name,0,name.size()-1);

    if(isPalindrome){
        cout << " It's a Palindrome " << endl;
    }
    else {
        cout << " It's not a Palindrome " << endl;
    }

return 0;
}