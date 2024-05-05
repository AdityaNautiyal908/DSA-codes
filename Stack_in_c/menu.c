/**
 * The code implements a stack data structure using an array in C with push, pop, print, and exit
 * functionalities.
 * 
 * @return The program is a simple implementation of a stack using an array in C. It allows the user to
 * push elements onto the stack, pop elements from the stack, print all elements in the stack, and exit
 * the program.
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 4

int arr_stack[MAX];
int top = -1;

int isFull(){
    if(top==MAX-1)
    return 1;
    else
    return 0;
}

int isEmpty(){
    if(top==-1)
    return 1;
    else 
    return 0;
}

void menu();

void Push(int data){
    system("cls");
    if(isFull()){
        printf("Stack overflow");
        return;
    }
    top = top + 1;
    arr_stack[top]= data;
}
int Pop(){
    system("cls");
    int value;
    if(isEmpty()){
        printf("Stack underflow");
        exit(1);
    }

    value = arr_stack[top];
    top = top - 1;
    return value;
}
// void Print_Top();

void Print_All(){
    system("cls");
    if(isEmpty()){
        printf("Stack underflow\n");
    }
    printf("Stack Element-\n");
    for(int i=top; i>=0; i--){
        printf("%d ",arr_stack[i]);
    }
    printf("\n");
}

int main(){
    char choice;
    int data;
    do{
        menu();
        scanf(" %c",&choice);
        switch(choice){
            case '1':
            printf("Enter the element to be pushed : ");
            scanf("%d", &data);
            Push(data);
            break;

            case '2':
            data = Pop();
            printf("Deleted element is %d\n",data);
            break;

            case '3':
            Print_All();
            break;

            case '4':
            exit(0);
            break;

            default:
            printf("Invalid choice");
        }
    getchar();
    }while(choice!='4');
}

void menu(){
    printf("\nMain Menu\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Print the top element\n");
    printf("4. Exit\n");
    printf("Enter your choice : ");
}