#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool Palindrome(char a[],int n){
    int s = 0;
    int e = n-1;

    while(s<=e){
        if(a[s] != a[e]){
            return 0;
        }
        else {
            s++;
            e--;
        }
    }
    return 1;
}

int getlength(char name[]){
    int count = 0;
    for ( int i=0; name[i] != '\0'; i++){
        count++;
    }
    return count;
}

void Reverse(char name[],int size) {
    int i = 0;
    int start = 0;
    int end = size - 1;
    while(start < end) {
        swap(name[start++],name[end--]);
    }
}

void print(char name[], int size){
    for ( int i=0; i<size; i++){
        cout << name[i] << " ";
    }cout << endl;
}

int main() {
    char name[20];
    cout << " Enter your name : ";
    cin >> name;

    int len = getlength(name);

    cout << "Lenght of string : " <<len << endl;

    print(name,len);

    Reverse(name,len);
    
    cout << " After Reversing the String " << endl;
    print(name,len);

    cout << " Palindrome or Not : " << Palindrome(name,len) << endl;
    return 0;
}
