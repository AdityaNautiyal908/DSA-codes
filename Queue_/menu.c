#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int Front=-1,Rear=-1,Queue[MAX],value;

void menu(){
    printf("\nMain Menu\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Print Queue element\n");
    printf("4. Exit\n");
    printf("Enter your choice : ");
}

int isFull(){
    if(Rear==MAX-1){
        return 1;
    }
    else {
        return 0;
    }
}

int isEmpty(){
    if(Front==-1){
        return 1;
    }
    else {
        return 0;
    }
}

void Enqueue(int data){
    if(isFull()){
        printf("Queue overflow\n");
    }
    else if(Rear==-1)
    {
        Front=Rear=0;
        Queue[Rear]= data;
    }
    else {
        Rear++;
        Queue[Rear]= data;
    }
}

int Dequeue(){
    if(isEmpty()){
        printf("Queue underflow\n");
        exit(1);
    }
    value = Queue[Front];
    if (Front == Rear) {
        Front = Rear = -1;
    } else {
    Front++;
    }
    return value;
}

void PrintQueue(){
    if(isEmpty()){
        printf("Queue is empty");
    }
    else {
        printf("Queue elements : ");
        for(int i=Front; i<=Rear; i++){
            printf("%d ",Queue[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice,data;
    do{
        menu();
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the element you want to insert : ");
            scanf("%d",&data);
            Enqueue(data);
            break;
            case 2:
            value = Dequeue();
            printf("Deleted element is %d\n",value);
            break;
            case 3:
            PrintQueue();
            break;
            case 4:
            exit(0);

        }
    }while(choice!=4);
    return 0;
}