/**
 * The given C program calculates and prints the Fibonacci series up to a specified number of terms.
 * 
 * @param n The code you provided is a C program that generates the Fibonacci series up to a specified
 * number of terms. The function `fibonacci` calculates the Fibonacci number at a given position using
 * recursion.
 * 
 * @return The `fibonacci` function returns the nth term of the Fibonacci series.
 */
#include <stdio.h>

int fibonacci(int n){
    if(n==0){
        return 0;
    }

    else if(n==1){
        return 1;
    }

    else {
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int main(){
    int n;
    printf("Enter the number of terms : ");
    scanf("%d",&n);

    printf("Fibonacci series up to %d terms : \n",n);

    for(int i=0; i<n; i++){
        printf("%d ",fibonacci(i));
    }
    printf("\n");
    return 0;
}