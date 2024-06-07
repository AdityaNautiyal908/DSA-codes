/**
 * The program calculates and prints the Fibonacci series up to a specified number of terms entered by
 * the user.
 * 
 * @param n The parameter `n` in the code represents the number of terms in the Fibonacci series that
 * the user wants to generate. The program calculates and prints the Fibonacci series up to `n` terms.
 * 
 * @return The `fibonacci` function is returning the nth term of the Fibonacci series.
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
        return fibonacci (n-1) + fibonacci(n-2);
    }
}

int main(){
    int n;
    printf("Enter the number of term : ");
    scanf("%d",&n);
    printf("Fibonacci series up to %d terms : ",n);
    for(int i=0; i<n; i++){
        printf("%d ",fibonacci(i));
    }
    printf("\n");
    return 0;
}