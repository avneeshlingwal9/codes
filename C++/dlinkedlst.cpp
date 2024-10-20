#include <iostream>
using namespace std ;
class Node{
    
    
    public :
    int data ; 
    Node* lft ; 
    Node* rit ;
    Node(int x){
        this->data = x ; 
        this->lft = NULL ;
        this->rit = NULL ;
    }
};
class dbly_list{
    private : 
    Node* head  ; 
    public : 
    dbly_list(){
        head = NULL ;
    }
    void beginsrt(int x){
        
        Node* newnode = new Node(x); 
        if(head == NULL){
            head = newnode;
        }
        else{   
            head->lft = newnode ; 
            newnode->rit = head ; 
            head = newnode ; }

        
    }
    void insertanywhere(int x , int pos){
        Node* newnode = new Node(x);
        Node* temp = head ; 
        Node* temp1 ; 
        if(pos == 1){
            head->lft = newnode ;
            newnode->rit = head;
            head = newnode ; 
             
            

        }
        else{
       
        for(int i = 0 ; i < pos-2 ; i++){
            temp = temp->rit ;
        }
        temp1 = temp->rit ; 
        temp->rit = newnode ;
        newnode->lft = temp ; 
        newnode->rit = temp1 ;
        temp1->lft = newnode ; 
        }
        



    }
    void pri(){
        Node* temp = head ; 
        while(temp!= NULL){
            cout << temp->data << " " ; 
            temp = temp->rit;
        } 
        cout << "\n" ; 
    }
};
int main(){
    dbly_list n ;

    n.beginsrt(4);
    n.pri();
    n.beginsrt(5);
    n.pri();
    n.beginsrt(6);
    n.pri(); 
    n.insertanywhere(1,3);
    n.pri();
    n.insertanywhere(4,1);
    n.pri();
    
    
}