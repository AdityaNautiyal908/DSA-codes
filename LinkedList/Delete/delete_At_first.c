/**
 * The above code defines a doubly linked list data structure and includes functions to print the list,
 * add a new node at the beginning, and delete the first node.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *pre;
    struct node *next;
}Node;

Node *head, *first, *second, *third,*ptr,*NewNode,*temp;

void print(){
    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

Node* del_first(Node *head){
    if(head==NULL){
        printf("List is empty\n");
    }

    else {
        temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
    return head;
}

void add_beg(int data){
    NewNode=malloc(sizeof(Node));
    NewNode->data=data;
    temp=NewNode;

    head->pre=temp;
    temp->pre=NULL;
    temp->next=head;
    head=temp;

}

int main(){
    first=malloc(sizeof(Node));
    second=malloc(sizeof(Node));
    third=malloc(sizeof(Node));

    head=first;

    first->data=1;
    first->pre=NULL;
    first->next=second;

    second->data=2;
    second->pre=first;
    second->next=third;

    third->data=3;
    third->pre=second;
    third->next=NULL;

    printf("Before adding the Element\n");
    print();

    printf("After adding the Element\n");
    add_beg(4);
    print();

    printf("After deleting the Element\n");
    head=del_first(head);
    print();

}