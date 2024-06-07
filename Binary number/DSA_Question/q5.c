// Write a program to print the follow numbers in reverse order:
// 34 56 54 32 67 89 90 32 21
// Assume that all these numbers are stored in an array.

#include <stdio.h>

int main(){
    int arr[9]={34, 56, 54 , 32 , 67 , 89 , 90 ,32, 21 };

    printf("Original order\n");
    for(int i=0; i<9; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    printf("Element in Reverse order\n");
    for(int i=8; i>=0; i--){
        printf("%d ",arr[i]);
    }

    return 0;
}


