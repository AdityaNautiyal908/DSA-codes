/**
 * The program allows the user to input an array, search for a specific element within it, and then
 * displays the location of that element if found.
 * 
 * @return The program returns an integer value of 0, which indicates successful execution of the
 * program.
 */
#include <stdio.h>
#define MAX 10

int arr[MAX],size;
int loc=-1;
int item;

int main(){
    printf("Enter the size of array : ");
    scanf("%d",&size);

    printf("Enter the element of array : ");
    for(int i=0; i<size; i++){
        scanf("%d",&arr[i]);
    }

    printf("Element of array\n");
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    printf("Enter the element you want to search for : ");
    scanf("%d",&item);
    int i=0;
    while(i<size && arr[i]!=item){
        i++;
    }

    if(arr[i]==item){
        loc = i;
        printf("Location of element %d : %d\n",loc,item);
    }

    else {
        printf("Element %d not found in the array.\n", item);
    }

    return 0;
}