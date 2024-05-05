#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *head, *first, *second, *third;

int main(){
    //If your are running this code in Dev C add (struct node*) at the start of malloc;
    first = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    first->data = 1;
    first->link= second;

    second->data = 2;
    second->link = third;

    third->data = 3;
    third->link = NULL;

    // Put first linked address inside head;
    head = first;

    //Transversal
    while(head!=NULL){
        printf("%d ",head->data);
        head = head->link;
    }
    return 0;
}