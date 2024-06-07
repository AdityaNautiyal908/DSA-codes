#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v;
    v.push_back(1);    
    v.push_back(2);    
    v.push_back(3);    
    v.push_back(4);    
    v.push_back(7);    

    int key;
    // cout << " Enter the key : ";
    // cin >> key;

    // cout<<binary_search(v.begin(),v.end(),key) << endl;

    int a = 3;
    int b = 5;
    int c = 6;
    int d = 8;
    int e = 9;

    cout << " Max ->" << max(a , b ) << endl;
    cout << " Min -> " << min(a , b ) << endl;

    string name = "Aditya";
    reverse(name.begin(), name.end());
    cout << " String reverse -> "<< name << endl;

    return 0;
}