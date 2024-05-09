/**
 * The code defines a circular doubly linked list with three nodes and prints the data in each node.
 * 
 * @param ptr The `ptr` parameter in the `print` function is a pointer to a struct node. It is used to
 * traverse the circular linked list starting from the node it points to and printing the data of each
 * node until it reaches the starting node again.
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *pre;
    struct node *next;
};
    struct node *head,*first,*second,*third;

void print(struct node *ptr){
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    printf("\n");
    
}

void printBackward(struct node *ptr){
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    do{
        printf("%d ",ptr->data);
        ptr=ptr->pre;
    }while(ptr!=head->pre);
}

int main(){

    first=malloc(sizeof(struct node));
    second=malloc(sizeof(struct node));
    third=malloc(sizeof(struct node));

    head=first;
    
    first->pre=NULL;
    first->data=1;
    first->next=second;

    second->pre=first;
    second->data=2;
    second->next=third;

    third->pre=second;
    third->data=3;
    third->next=first;

    print(head);
    printBackward(head);
    return 0;
}