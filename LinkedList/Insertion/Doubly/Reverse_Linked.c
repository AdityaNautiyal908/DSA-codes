/**
 * The code defines a linked list structure, creates a linked list with three nodes, prints the
 * original list, reverses the list, and then prints the reversed list.
 * 
 * @param ptr `ptr` is a pointer to the struct `node` type, which is used to traverse through the
 * linked list and print the data stored in each node.
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void printLinkedList(struct node *ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
    struct node *head, *first, *second, *third,*temp=NULL;

void ReverseLists(struct node *temp2){
    while(head!=NULL){
        temp2=head->next;
        head->next=temp;
        temp=head;
        head=temp2;
    }
    head=temp;
}

int main(){
    first=malloc(sizeof(struct node));
    second=malloc(sizeof(struct node));
    third=malloc(sizeof(struct node));

    head=first;

    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next=NULL;


    printf("Original Linked List\n");
    printLinkedList(head);

    ReverseLists(head);
    printf("Reverse Linked List\n");

    printLinkedList(head);

}