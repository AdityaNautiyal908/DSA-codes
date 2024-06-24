#include <iostream>
#include <stack>
using namespace std;

int main(){
    // string str = "Love";

    // stack<int> s; 

    // for ( int i=0; i<str.length(); i++){
    //     char ch = str[i];
    //     s.push(ch);
    // }

    // string ans = " ";
    // while(!s.empty()){
    //     char ch = s.top();
    //     ans.push_back(ch);
    //     s.pop();
    // }

    // cout << " answer is : " << ans << endl;

    stack <char> s;
    s.push('a');
    s.push('d');
    s.push('i');
    s.push('t');
    s.push('y');
    s.push('a');

    cout << " Reversed string is : ";
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }

return 0;
}