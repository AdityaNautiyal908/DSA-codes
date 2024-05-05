/**
 * The code implements a stack data structure in C with push, pop, and print functions.
 * 
 * @return The program is pushing the values 1, 2, 3, and 4 onto the stack and then printing the stack
 * contents. The output of the program will be:
 * 4 3 2 1
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int arr_stack[MAX];
int top = -1; // -1 indicates that the stack is empty.

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

void push(int data){
    if(isFull()){
        printf("Stack overflow");
        return;
    }
    top = top + 1;
    arr_stack[top]= data;
}

int pop(){
    int value;
    if(isEmpty()){
        printf("Stack underflow");
        exit(1);
    }

    value = arr_stack[top];
    top = top - 1;
    return value;
}

void print(){
    if(isEmpty()){
        printf("Stack underflow\n");
    }
    for(int i=top; i>=0; i--){
        printf("%d ",arr_stack[i]);
    }
    printf("\n");
}

int main(){
    int data;
    push(1);
    push(2);
    push(3);
    push(4);
    print();
    return 0;
}