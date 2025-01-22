#include <iostream>
using namespace std ;
class Grap{
    public :
    int data ;
    Grap* left ;
    Grap* right;
    Grap(int data){
        this->data = data ;
        this->left = NULL;
        this->right = NULL;
        }
    Grap(){
        this->data = 0 ;
        this->left = NULL ;
        this->right = NULL;
    }
    Grap* inserrt(Grap* root , int d){
        if(root == NULL){
            return new Grap(d);
        }
        else if(d > root->data){
            root->right = inserrt(root->right,d);

        }
        else if(d< root->data){
            root->left = inserrt(root->left,d);
        }
        return root ;
    }
    void inordertraversal(Grap* root){
        if(root==NULL){
            return ;
        }
        inordertraversal(root->left);
        cout << root->data << " ";
        inordertraversal(root->right);

    }
    void preordertraversal(Grap* root){
        cout << root->data << " ";
        preordertraversal(root->left);
        preordertraversal(root->right);
    }
    void postordertraversal(Grap* root){
        postordertraversal(root->left);
        postordertraversal(root->right);
        cout << root->data << " " ;

    }
    
    
    

};
int main(){
    Grap g ,*root = NULL ;
    root = g.inserrt(root,8);

    g.inserrt(root,12);
    g.inserrt(root,9);
    g.inserrt(root,3);
    g.inserrt(root,1);
    g.inserrt(root,2);
    g.inserrt(root,7);
    g.inordertraversal(root);

}
