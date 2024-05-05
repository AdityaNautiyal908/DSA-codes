/**
 * This C program inserts an element into an array at a specified position.
 * 
 * @return The `main` function is returning an integer value of 0.
 */
#include <stdio.h>
int main(){
    int arr[100],i,pos,size,item;
    printf("Enter size of array : ");
    scanf("%d",&size);
    printf("Enter array element : ");
    for(int i=0; i<=size-1; i++){
        scanf("%d",&arr[i]);
    }
   
    printf("Before insertion an element : ");
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }

    printf("\nEnter position that you want to Insert : ");
    scanf("%d",&pos);
    printf("Enter item you want to insert : ");
    scanf("%d",&item);
    int J;
    J=size;
    while(J>=pos){
        arr[J+1]=arr[J];
        J=J-1;
    }
    arr[pos]=item;
    size++;

    printf("After insertion an element : ");
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}