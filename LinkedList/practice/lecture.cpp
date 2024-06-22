#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next=NULL;
    }
};

void InsertAtHead(Node* &head, int d){
    // new node create
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAttail(Node* &tail,int d){
     // new node create
    Node* temp = new Node(d);
    tail->next = temp;
}

void print(Node* &head) {
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }cout << endl;
}

bool CircularList(Node* head){
    if(head==NULL)
    return true;

    Node *temp = head->next;
    while(temp!=NULL && temp != head){
        temp = temp->next;
    }
    if(temp==head)
    return true;

    return false;
}

int main(){
    // created a new node
    Node *node1 = new Node(10);

    // head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    cout << endl;
    InsertAtHead(head,15);
    InsertAtHead(head,16);
    InsertAtHead(head,17);
    print(head);
    cout << endl;
    if(CircularList(head)){
        cout << " Linked list is circular " << endl;
    }
    else {
        cout << " Not circular " << endl;
    }

return 0;
}