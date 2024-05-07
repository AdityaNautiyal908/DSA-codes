#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head, *first, *second, *third,*NewNode;

struct node* print(struct node *ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
        return ptr;
        printf("\n");
}

struct node* add_beg(int data,struct node *temp){
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=head;
    head=temp;
}

struct node* add_end(int data, struct node *ptr){
    struct node *NewNode;
    NewNode=malloc(sizeof(struct node));
    
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        NewNode->data=data;
        NewNode->next=NULL;
        ptr->next=NewNode;
    
}

struct node* at_specific(struct node *ptr, int data, int pos){
    int count=1;
    NewNode=malloc(sizeof(struct node));
    NewNode->data=data;
    while(ptr!=NULL && count<pos){
        ptr=ptr->next;
        count++;
    }
    if(ptr!=NULL){
        NewNode->next=ptr->next;
        ptr->next=NewNode;
    }
    return head;
}

int main(){
    first = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    head=first;

    first->data=1;
    first->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;

    printf("Before adding the element\n");
    print(head);

    printf("\nAfter adding the element\n");
    add_beg(4,head);
    print(head);

    printf("\nAfter inserting element in end\n");
    add_end(5,head);
    print(head);

    printf("\nInsert at specific position\n");
    at_specific(head,8,3);
    print(head);

    return 0;

}