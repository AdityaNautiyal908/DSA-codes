#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class MyLinkedList {
public:
    Node* head;

    MyLinkedList() {
        head = nullptr;
    }

    int length() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    int get(int k) {
        if (head == nullptr || k >= length()) return -1;
        Node *temp = head;
        for (int i = 0; i < k; i++) {
            temp = temp->next;
        }
        return (temp != nullptr) ? temp->data : -1;
    }

    void addAtHead(int val) {
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
    }

    void addAtTail(int val) {
        Node *temp = new Node(val);
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

    void addAtIndex(int pos, int val) {
        if (pos == 0) {
            addAtHead(val);
            return;
        }
        Node *ptr = head;
        for (int i = 0; i < pos - 1; i++) {
            if (ptr == nullptr) return; // Position out of bounds
            ptr = ptr->next;
        }
        Node *newNode = new Node(val);
        newNode->next = (ptr != nullptr) ? ptr->next : nullptr;
        if (ptr != nullptr) ptr->next = newNode;
    }

    void deleteAtIndex(int pos) {
        if (head == nullptr) return;
        if (pos == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *curr = head;
        for (int i = 0; i < pos - 1; i++) {
            if (curr == nullptr || curr->next == nullptr) return; // Position out of bounds
            curr = curr->next;
        }
        Node *toDelete = curr->next;
        if (toDelete != nullptr) {
            curr->next = toDelete->next;
            delete toDelete;
        }
    }

    void printLinked() {
        Node *ptr = head;
        while (ptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main() {
    MyLinkedList* list = new MyLinkedList();

    list->addAtHead(50);
    list->addAtHead(10);
    list->addAtHead(80);
    list->addAtTail(20);
    list->addAtTail(90);
    list->printLinked();

    cout << "Element at index 2: " << list->get(2) << endl;

    list->addAtIndex(2, 100);
    list->printLinked();

    list->deleteAtIndex(3);
    list->printLinked();

    delete list;
    return 0;
}
