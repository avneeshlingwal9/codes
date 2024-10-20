#include <stdlib.h>
#include <stdio.h>
struct Node{
    int data ;
    struct Node *left , *right ;


};
struct Node* create(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data ;
    newnode->left= newnode->right=NULL ;
    return newnode ;
}
struct Node* insertion(struct Node *root ,int data ){
    if(root == NULL){
        return create(data);
    }
    else if(root->data > data){
        root->left = insertion(root->left,data);
    }
    else if(root->data < data){
        root->right = insertion(root->right,data);
    }
    return root ;
}
int elementfind(struct Node* root, int k, int *c)
{
    if(root== NULL){
        return -1 ;
}
    int r  = elementfind(root->left,k,c);
    if(r!=-1){
        return r ;
    }
    (*c)++;
    if(*c==k){
        return root->data;
    }
    
    return elementfind(root->right,k,c);


}
int countmultiple(struct Node* root , int k  ) 
{
    if(root == NULL )
    {
        return  0 ;
    }
    int c = root->data%k == 0 ; // Checking the condition if equal then c = 1 else c = 0 
        
    
    c+=countmultiple(root->left,k);
    c+=countmultiple(root->right,k);
    return c ;


}
int main(){
    struct Node* root =NULL;
    root = insertion(root,19);
    root = insertion(root ,14);
    root = insertion(root,27);
    root = insertion(root,4);
    root = insertion(root,25);
    root = insertion(root,21);
    root =insertion(root,7);
    root = insertion(root,22);
    int c = 0 ;
    int k = 2;

    printf("%d ",elementfind(root,4,&c));

    printf("\n The number of multiples of %d is %d ",k, countmultiple(root,2));

}
