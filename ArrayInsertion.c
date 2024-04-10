#include <stdio.h>
#define MAX 100
int main(){
    int size,Pos,item;
    int Arr[MAX];

    printf("Enter the size of Array : ");
    scanf("%d",&size);

    printf("Enter array element : ");
    for(int i=0; i<size; i++){
        scanf("%d",&Arr[i]);
    }

    printf("Array element : ");
    for(int i=0; i<size; i++){
        printf("%d ",Arr[i]);
    }

    // Insertion at specific postion 
    printf("\nEnter the position you want to enter the element : ");
    scanf("%d",&Pos);
    printf("Enter the element to insert : ");
    scanf("%d",&item);

    for(int i=size; i>=Pos; i--){
        Arr[i]=Arr[i-1];
    }
    Arr[Pos] =item;
    size++;

    printf("After insertion element : ");
    for(int i=0; i<size; i++){
        printf("%d ",Arr[i]);
    }

}