#include <iostream>
#include <map>
using namespace std;


class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    // destructor
    ~Node(){
        int value = this ->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};
Node *head = nullptr;

void printLinked(Node *ptr) {
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void insertAtBeg(Node* &head, int d) {
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtEnd(Node* &head, int d) {
    Node *temp = new Node(d);
    if (head == nullptr) {
        head = temp;
    } else {
        Node *ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void insertAtSpecific(Node* &head, int pos, int d) {
    if (pos == 1) {
        insertAtBeg(head, d);
        return;
    }

    Node *ptr = head;
    Node *newNode = new Node(d);
    pos--;

    while (pos > 1 && ptr != nullptr) {
        ptr = ptr->next;
        pos--;
    }

    if (ptr == nullptr) {
        cout << "Position out of bounds" << endl;
    } else {
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

void deleteNode(int pos, Node* &head){
    // deleting start node
    if(pos == 1) {
        Node* temp = head;
        head = head -> next;
        // memory free
        temp ->next = NULL;
        delete temp;
    }

    // deleting any middle node or last node
    else {
        Node *curr = head;
        Node *pre = NULL;

        int cnt = 1;
        while(cnt <= pos) {
            pre = curr;
            curr = curr->next;
            cnt++;
        }
        pre ->next = curr->next;
        curr ->next = NULL;
        delete curr;
    }
}

bool detectloop(Node *temp){
    if(head == nullptr) return false;
    map<Node*,bool> visited;

    while(temp != NULL){
        // cycle is present
        if(visited[temp] == true) return true;

        visited[temp] = true;
        temp = temp ->next;
    }
    return false;
}

Node* floydCycle(Node* &head){
    if(head == nullptr || head ->next == nullptr) return nullptr;

    Node *slow = head;
    Node *fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast ->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow ->next;

        if(slow == fast){
        cout << " present at : " << slow ->data << endl;
        return slow;
        }            
    }
    return nullptr;
}

Node *first, *second , *third, *fourth, *five;

int main() {
    first = new Node(1);
    second = new Node(2);
    third = new Node(3);
    fourth = new Node(4);
    five = new Node(5);

    head = first;

    first ->next = second;
    second ->next = third;
    third->next = fourth;
    fourth->next = five;
    five ->next = second;

    if(floydCycle(head)){
        cout << " Cycle is present " << endl;
    }
    else {
        cout << " NO Cycle is present " << endl;
    }
    // deleteNode(1, head);
    // printLinked(head);


    return 0;
}
