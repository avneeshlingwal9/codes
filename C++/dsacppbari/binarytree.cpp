#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(){
        data = -1;
        left = right = NULL;
    }
    Node(int x){
        data = x;
        left = right = NULL;
    }
    
    

};
Node *root = NULL;

Node* insert(Node* root, int x){
    if(root == NULL){
        root = new Node(x);
        return root;
    }
    if(root->data < x){
        root->right = insert(root->right,x);
    }
    else{
        root->left = insert(root->left, x);
    }
    return root;
}
void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    postOrder(root->left);
    postOrder(root->right);
}

int main(){
    root = insert(root,4);
    root = insert(root,5);
    root = insert(root,8);
    root = insert(root,3);
    root = insert(root,1);
    cout << "Inorder traversal ";
    inOrder(root);
    cout << endl;

    preOrder(root);
}