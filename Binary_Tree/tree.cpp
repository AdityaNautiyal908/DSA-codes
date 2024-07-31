#include <iostream>
using namespace std;

class node {
    public:
    int data;
    node *left;
    node *right;

    node(int d){
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node* createTree(node *root){
    cout << " Enter the data : ";
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1) return nullptr;

    cout << " Enter the data to insert in left of " << data << endl;
    root->left = createTree(root->left);
    cout << " Enter the data to insert in right of " << data << endl;
    root->right = createTree(root->right);
    return root;
}

void inorder(node *root){
    if(root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    node *root = nullptr;
    root = createTree(root);

    cout << " Inorder Traversal " << endl;
    inorder(root);
return 0;
}