/**
 * The program provides a menu-driven interface to create, display, insert, delete, and reverse
 * elements in an array.
 * 
 * @return The main function is returning 0, which indicates successful completion of the program.
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 100

int A[MAX],size,pos,elem,item;

void menu();
void create();
void display();
void insert();
void delete();
void reverse();

int main(){
    char ch;
    do{
        menu();
        ch=getch();
        printf("%c\n", ch);  
        switch(ch){
            case '1':
            create();
            break;
            case '2':
            display();
            break;
            case '3':
            insert();
            break;
            case '4':
            delete();
            break;
            case '5':
            reverse();
            break;
            case '6':
            exit(0);
            break;
            default:
            printf("Invalid choice");
        }
    }while(ch!='6');
    return 0;
}

void menu(){
    printf("\n\tMain Menu\n");
    printf("1. Create an array of N elements\n");
    printf("2. Display array element\n");
    printf("3. Insert element at given position\n");
    printf("4. Delete element at given position\n");
    printf("5. Reverse array element\n");
    printf("6. Exit\n");
    printf("Enter your choice : ");
}

void create(){
    system("cls");
    printf("Enter the size of array : ");
    scanf("%d",&size);
    printf("Enter the array element : \n");
    for(int i=1; i<=size; i++){
        scanf("%d",&A[i]);
    }
}

void display(){
    system("cls");
    printf("Array element : ");
    for(int i=1; i<=size; i++){
        printf("%d ",A[i]);
    }
}

void insert(){
    printf("\nEnter the position where you want to insert the element : ");
    scanf("%d",&pos);
    printf("Enter the element to insert : ");
    scanf("%d",&item);
    elem=size;
    while(elem>=pos){
        A[elem+1]=A[elem];
        elem=elem-1;
    }
    A[pos]=item;
    size++;

}

void delete(){
    printf("\nEnter the position where you want to delete the element : ");
    scanf("%d",&pos);
    item=A[pos];

    for(int i=pos; i<size; i++){
        A[i]=A[i+1];
    }
    size--;
}

void reverse(){
    printf("Reverse order\n");
    for(int i=size; i>=1; i--){
        printf("%d ",A[i]);
    }
}