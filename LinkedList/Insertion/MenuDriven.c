#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void menu();
void insert();
void display();
struct node* at_Beg(struct node *head, int d);
struct node* at_End(struct node *head, int data);
void add_at_pos();

struct node *start, *end, *NewNode,*ptr,*temp;
int data,pos;

struct node {
    int data;
    struct node *link;
};

int main(){
    char choice;
    do{
        menu();
        choice=getch();
        printf("%c\n", choice);  
        switch(choice){
            case '1':
            insert();
            break;
            case '2':
            display(start);
            break;
            case '3':
            printf("Enter the element to insert at the beginning: ");
            scanf("%d", &data);
            start = at_Beg(start, data);
            break;
            case '4':
            printf("Enter the element to insert at the End : ");
            scanf("%d",&data);
            at_End(start,data);
            break;
            case '5':
            add_at_pos();
            break;
            case '6':
            exit(0);
            break;
            default:
            printf("Invalid choice");
        }

    }while(choice!='6');
    return 0;
}

void menu(){
    printf("\n\tLinked list\n");
    printf("1. Insert\n");
    printf("2. Display\n");
    printf("3. Insert at Beginning\n");
    printf("4. Insert at End\n");
    printf("5. Insert at specific position\n");
    printf("6. Exit\n");
    printf("Enter your choice : ");
}

void insert(){
    int size;
    printf("\nEnter the size of linked list : ");
    scanf("%d", &size);

    printf("Enter the element of list\n");

    for(int i = 0; i < size; i++) {
        NewNode = malloc(sizeof(struct node));
        if (NewNode == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        printf("Index Number %d : ", i + 1); 
        scanf("%d", &NewNode->data);
        NewNode->link = NULL;

        if (start == NULL) {
            start = end = NewNode;
        } else {
            end->link = NewNode;
            end = NewNode;
        }
    }
}

void display(struct node *ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}
struct node* at_Beg(struct node *head, int d){
    ptr = malloc(sizeof(struct node));
    ptr->data = d;
    ptr->link = head;
    return ptr;

}


struct node* at_End(struct node *head, int data){
    ptr=head;
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
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