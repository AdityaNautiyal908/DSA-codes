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

node* sortedArraytoBST(int arr[], int start, int end){
    if(start > end) return nullptr;

    int mid = start + (end - start) / 2;
    node *root = new node(arr[mid]);

    root->left = sortedArraytoBST(arr,start,mid-1);
    root->right = sortedArraytoBST(arr,mid+1,end);

    return root;
}

void preorder(node *root){
    if(root == nullptr) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int arr[] = {10,20,30,40,50};
    node* root = sortedArraytoBST(arr,0,4);
    preorder(root);
    cout << endl;
return 0;
}