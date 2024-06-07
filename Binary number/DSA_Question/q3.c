// Program to check if a number is natural or not

#include <stdio.h>

int main(){
    int num;
    printf("Enter the number : ");
    scanf("%d",&num);
    num>=1 ? printf("%d is a natural number",num) : printf("%d is not a natural number",num);
    return 0;
}