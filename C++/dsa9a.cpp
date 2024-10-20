#include <iostream>
using namespace std ;
class Node{
    public :
    int data ;
    Node* right ;
    Node* left ;
    Node(int x){
        this->data = x ;
        this->left = NULL;
        this->right = NULL ;
    }
    
};
Node* insertbinary(Node* root,int x){
    if(root == NULL ){
        return new Node(x);
    }
    if(x < root->data){
        root->left = insertbinary(root->left, x);
    }
    else if( x > root->data){
        root->right = insertbinary(root->right,x);
    }

    return root ;
    
}
void inordertraversal(Node* temp){
    if(temp == NULL){
        return ;
    }
    inordertraversal(temp->left);
    cout << temp->data << " " ;
    inordertraversal(temp->right);

}
void postorder(Node* temp){
    if(temp == NULL){
        return ;
    }
    postorder(temp->left);
    postorder(temp->right);
    cout << temp->data << " " ;
}
void preorder(Node* temp){
    if(temp == NULL){
        return ;
    }
    
    cout << temp->data << " " ;
    preorder(temp->left);
    preorder(temp->right);

}
Node* dletenode(Node* root ,int val){
    if(root == NULL){
        return root ; 
    }
    if(root->data > val){
        root->right = dletenode(root->right,val);
        return root ;
    }
    else if(root->data < val){
        root->left = dletenode(root->left,val);
        return root ;
    }


    


}
int main(){
    Node* root = insertbinary(NULL , 75);
    insertbinary(root ,70);
    insertbinary(root ,44);
    insertbinary(root ,48);
    insertbinary(root , 98);
    insertbinary(root ,108);
    insertbinary(root ,91);
    insertbinary(root ,145);
    inordertraversal(root);
    cout << endl ;
    postorder(root);
    cout << endl ;
    preorder(root);
    cout << endl ;

}

