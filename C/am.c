#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
bool isPalindrome(char* str){ // Checks if a string is pallindrome or not .
    int len = strlen(str);
    for(int i =0 ; i < len/2; i++){
        if (str[i] != str[len-i-1]){
            return false ;
        }
    }
    return true ;
}



int countpallindrome(struct Node* root){
    if(root == NULL){
        return 0 ;
    }
    char* str  = (char*)malloc(12);
    sprintf(str,"%d",root->data); 
    

    int count = isPalindrome(str); // sprintf converts an integer back to string . and if it is pallindrome this 
    // function returns 1 else 0 .
    free(str);

    count+=countpallindrome(root->left);
    count+=countpallindrome(root->right);
    return count;
}

int main(){
    struct Node* root =NULL;
    root = insertion(root,191); //pallindrome
    root = insertion(root ,141);//pallindrome
    root = insertion(root,27);
    root = insertion(root,434);//pallindrome
    root = insertion(root,12521);//pallindrome
    root = insertion(root,21);
    root =insertion(root,7);//pallindrome
    root = insertion(root,22);//pallindrome

    printf("The number of the pallindrome is: %d " ,countpallindrome(root) );
    return 0 ;
    

}
