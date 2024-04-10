#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *start, *end, *NewNode;
int size,data,pos;

void Traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}

void add_at_pos(){
    printf("\nEnter the position you want to insert the element : ");
    scanf("%d",&pos);
    printf("Enter the element to insert : ");
    scanf("%d",&data);
    struct node *ptr =start;
    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link=NULL;

    pos--;
    while(pos!=1){
        ptr=ptr->link;
        pos--;
    }
    ptr2->link=ptr->link;
    ptr->link=ptr2;

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
            start=end=NewNode;
        }
        else {
            end->link=NewNode;
            end=NewNode;
        }
    }
    Traversal(start);
    add_at_pos();
    printf("After Inserting the element\n");
    Traversal(start);
}