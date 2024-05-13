#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *pre;
    struct node *next;
}Node;

Node *head, *first, *second, *third,*ptr;

void printlinked(){
    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

void insert_At_Beg(int data){
    Node *temp;
    temp=malloc(sizeof(Node));
    temp->data=data;

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

    printlinked();
    insert_At_Beg(7);
    printlinked();
}