#include <iostream>
using namespace std ;
class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        this->data = x ;
        this->next = NULL;
    }
};
class Stackk{
    public : 
    Node* top; 
    Stackk(){
        this->top = NULL ;
    }
    void push(int x){
        Node* newnode = new Node(x);
        newnode->next = top ;
        top = newnode ;

        
    }
    int pop(){
        Node* temp = top ; 
        top = temp->next ;
        temp->next = NULL ;
        return temp->data ;
    }
    bool isempty(){
        if(top == NULL){
            return true ;

        }
        else{
            return false ;
        }
    }
    void displa(){
        Node* temp = top ; 
        while(temp!=NULL){
            cout << temp->data << " " ;
            temp = temp->next ;
        }
        cout << endl ;
    }
    

};
int main(){
    Stackk s ;
    s.push(7);
    s.displa();
    s.push(8);
    s.displa();
    s.pop();
    s.displa();
    
}