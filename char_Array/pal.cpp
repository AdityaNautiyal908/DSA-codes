#include <iostream>
using namespace std;

void toLowerCase(char str[], int size) {
    for (int i = 0; i < size; i++) {
        str[i] = tolower(str[i]);
    }
}

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

int main(){
    char name [] = {'E','E', 'V','E','E'};
    cout << " Palindrome or Not : "<< Palindrome(name,5);



return 0;
}