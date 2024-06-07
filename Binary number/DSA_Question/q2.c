// Write a program to check the smallest number between two using (ternary operator)

#include <stdio.h>

int main(){
    int num1,num2;
    printf("Enter the two number : ");
    scanf("%d %d",&num1,&num2);

    num1<num2 ? printf("%d is the smallest",num1) : printf("%d is the smallest",num2);
    return 0;
}