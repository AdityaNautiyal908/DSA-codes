#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s) {
        int length = 0;
        bool counting = false;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                counting = true;
                length++;
            }
            else if (counting) {
                break;
            }
        }
        
        return length;
    }

int main(){
    string s;
    s = " Hello Wwoorrlldd ";

    cout << "Last Word lenght : " << lengthOfLastWord(s) << endl;
    cout << " Length of string : " << s.length() << endl;
return 0;
}