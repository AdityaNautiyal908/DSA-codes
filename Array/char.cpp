#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char toLowerCase(char ch) {
    if (ch >= 'a' && ch <= 'z')
        return ch;
    else if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 'a';
    return ch;
}   

bool isAlphanumeric(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}


bool Palindrome(char a[],int n){
    int s = 0;
    int e = n - 1;

    while (s <= e) {
        while (s < e && !isAlphanumeric(a[s])) 
        s++;
        while (e > s && !isAlphanumeric(a[e])) 
        e--;

        if (toLowerCase(a[s]) != toLowerCase(a[e])) {
            return false;
        }
        s++;
        e--;
    }
    return true;

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
    char name[40];
    cout << " Enter your name : ";
    cin.getline(name,40);

    int len = getlength(name);

    cout << "Lenght of string : " <<len << endl;

    print(name,len);

    Reverse(name,len);
    
    cout << " After Reversing the String " << endl;
    print(name,len);

    cout << " Palindrome or Not : " << Palindrome(name,len) << endl;



    return 0;
}
