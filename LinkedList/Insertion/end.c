#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *start, *temp, *NewNode,*ptr;
int size,data;

void Traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}

void add_at_end(){
    printf("\nEnter the element you want to insert : ");
    scanf("%d",&data);
    ptr=start;
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;

}


int main(){
    printf("Enter the size of linked list : ");
    scanf("%d",&size);
    for(int i=0; i<size; i++){
        NewNode = malloc(sizeof(struct node));
        printf("Enter the element of node : ");
        scanf("%d",&NewNode->data);
        NewNode->link=NULL;

        if(start==NULL){
            start=temp=NewNode;
        }
        else {
            temp->link=NewNode;
            temp=NewNode;
        }
    }
    Traversal(start);
    add_at_end();
    printf("After inserting the element at last\n");
    Traversal(start);
}