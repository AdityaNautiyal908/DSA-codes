/**
 * The code implements a menu-driven program for a linked list with options to insert elements at the
 * beginning, end, specific position, display the list, and reverse the list.
 * 
 * @return In the code provided, the functions `at_Beg`, `at_End`, and `ReverseLists` are returning a
 * pointer to a struct node. The `at_Beg` and `at_End` functions are returning a pointer to the updated
 * linked list after inserting a new node at the beginning or end, respectively. The `ReverseLists`
 * function is returning a pointer to the reversed linked list.
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void menu();
void insert();
void display();
struct node* at_Beg(struct node *head, int d);
struct node* at_End(struct node *head, int data);
void add_at_pos();
void ReverseLists(struct node *temp2);

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
            printf("Reversed List Element\n");
            ReverseLists(start);
            break;
            case '7':
            exit(0);
            break;
            default:
            printf("Invalid choice");
        }

    }while(choice!='7');
    return 0;
}

void menu(){
    printf("\n\tLinked list\n");
    printf("1. Insert\n");
    printf("2. Display\n");
    printf("3. Insert at Beginning\n");
    printf("4. Insert at End\n");
    printf("5. Insert at specific position\n");
    printf("6. Reverse list\n");
    printf("7. Exit\n");
    printf("Enter your choice : ");
}

void insert(){
    system("cls");
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
    system("cls");
    printf("List Element\n");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}
struct node* at_Beg(struct node *head, int d){
    system("cls");
    ptr = malloc(sizeof(struct node));
    ptr->data = d;
    ptr->link = head;
    return ptr;

}


struct node* at_End(struct node *head, int data){
    system("cls");
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
    system("cls");
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

void ReverseLists(struct node *temp2){
    while(start!=NULL){
        temp2=start->link;
        start->link=temp;
        temp=start;
        start=temp2;
    }
    start=temp;
}