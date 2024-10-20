#include <iostream>
using namespace std ;
class Node{
    public :

    Node* next ; 
    int data ;
    Node(int x){
        data = x ;
        next = NULL ;
    }
};
class stackLinkedList{
    public :
    Node* head ; 
    stackLinkedList(){
        head = NULL ;
    }
    void push(int x){

        Node* newnode = new Node(x);
        if(!newnode ){
            cout << "Stack overflow " << endl ;
            return ; 
        }
        newnode->next = head ;
        head = newnode ;


    }
    void show(){
        if(this->isEmpty()){
            cout << "Stack is empty" << endl ;
            return ;
        }
        Node* temp = head ;
        
        while(temp!= NULL){
            cout << temp->data << " ";
            temp = temp->next ;
        }
        cout << endl ;
    }
    int pop(){
        if(head == NULL){
            cout << "Stack underflow " << endl ;
            return -1 ;
        }
        Node* temp = head ;
        head = temp->next ;
        temp->next = NULL ;
        return temp->data ;
    }
    int peek(){
        return head->data ;
    }
    bool isEmpty(){
        return head == NULL ;
    }


};
int main(){
    stackLinkedList s1 ;
    int con = 0 ;
cout << "Enter 1 for push." << "\nEnter 2 for pop. " <<"\nEnter 3 for peek." <<"\nEnter 4 for display." <<"\nEnter 5 for isEmpty" << endl ;
    cout << "Enter -1 to exit." << endl ;
    while(con!=-1){
        cout << "Enter a choice:" << endl ;
        cin >> con ; 
        switch (con)
        {
        case 1:
        int l ;
        cout << "Enter the element: " << endl ;
        cin >> l ; 
        s1.push(l);
            break;
        case 2 :
        
        cout << "Popped element is " << s1.pop() << endl ; 
            break ;
        case 3 :
        cout <<"Element at the top is "<<  s1.peek() << endl ;
        break ;
        case 4:
        cout << "Elements in the stack are " << endl ;
        s1.show();
        break;
        case 5:
        if(s1.isEmpty()){
            cout << "Stack is empty." << endl ;
            break;}
        
        cout << "Stack is not empty." << endl; 
        break;

        
        
        default :
        con = -1 ;
        break ;}
            

    }}