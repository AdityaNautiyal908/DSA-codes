// Write a program to check if a given number is digit or not

#include <stdio.h>

int main(){
    char ch;
    printf("Enter the number : ");
    scanf("%c",&ch);
    
    //ternary operator is to run code when the condition is true and another code when the condition is false 
    ch>='0' && ch<='9' ? printf("It's a digit!") : printf("It's not a digit");
    return 0;

}