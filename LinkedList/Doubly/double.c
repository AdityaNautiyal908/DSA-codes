/**
 * The above C program creates a doubly linked list with three nodes and prints the data in each node.
 * 
 * @return The program is returning 0, which indicates successful execution without any errors.
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

int main(){
    struct node *head, *first, *second, *third,*ptr;
    first = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    first->data=1;
    second->data=2;
    third->data=3;

    first->next=second;
    first->prev=NULL;

    second->next=third;
    second->prev=first;

    third->next=NULL;
    third->prev=second;

    head=first;
    ptr=head;

    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}