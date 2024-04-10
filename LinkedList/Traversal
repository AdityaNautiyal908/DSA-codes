#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *start, *end, *NewNode;

void Traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}

int main(){
    int size;
    printf("Enter the size of linked list : ");
    scanf("%d",&size);
    for(int i=0; i<size; i++){
        NewNode = malloc(sizeof(struct node));
        printf("Enter the element of node : ");
        scanf("%d",&NewNode->data);
        NewNode->link=NULL;

        if(start==NULL){
            start=end=NewNode;
        }
        else {
            end->link=NewNode;
            end=NewNode;
        }
    }
    Traversal(start);
}