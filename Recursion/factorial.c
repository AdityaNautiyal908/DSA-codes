/**
 * The program calculates the factorial of a given number using a recursive function.
 * 
 * @param n The parameter `n` in the `factorial` function represents the number for which the factorial
 * is being calculated. It is an integer value that is passed to the function to compute the factorial
 * recursively.
 * 
 * @return The factorial of the number entered by the user is being returned by the `factorial`
 * function in the code.
 */
#include <stdio.h>

int factorial(int n){
    if(n==0){
        return 1;
    }
    else {
        return n*factorial(n-1);
    }
}

int main(){
    int num;
    printf("Enter the number : ");
    scanf("%d",&num);
    printf("Factoial of a number : %d",factorial(num));
    return 0;
}