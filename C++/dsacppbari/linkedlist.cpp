#include <iostream>
using namespace std; 

struct Node{
    int data;
    Node *next;
};
class LinkedList{
    private:
        Node *head; 
    public :
    LinkedList(){
        head = NULL;
    }
    LinkedList(int A[], int n){
        Node *last ,*t;
        head = new Node;
        head->data = A[0];
        head->next = NULL;
        last = head; 
        for (int i = 1; i < n; i++){
            t = new Node; 
            t->data = A[i];
            t->next = NULL;
            last->next = t;
            last = t; 
        }
    }
    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl; 
    }
    int count(){
        int c = 0 ; 
        Node *temp = head;
        while(temp){
            temp = temp->next;
            c++;
        }
        return c; 
    }
    void insert(int pos , int el){
    
        if(pos < 0 && pos > count()){
        cout <<"Uh HH cannot be inserted " << endl;
        return; 
        }
        Node *temp = new Node;

        temp->data = el;
        if(head == NULL){
            head = temp;
        }
        Node *o = head;
        for (int i = 0; i < pos-1; i++){
            o = o->next;
        }
        if(o == head){
            temp->next = o;
            head = temp; 
        }
        else{
        temp->next = o->next;
        o->next = temp;
        }
    }
    void Delete(int pos){
        if(pos <1 && pos > count()){
            cout << "Uh uH wRONG INDEX " << endl;
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos -1; i++){

            temp = temp->next;
        }
        if(temp == head){
            head = head->next;
            delete temp;
        }
        else{
            Node *t = temp->next;
            temp->next = temp->next->next;
        
            
            delete (t);
        }
        
    }
    ~LinkedList(){
        Node* p = head ; 
        while(head){
            head = head->next;
            delete (p);
            p = head;
        }

    }
    
};
int main(){
    int A[] = {4, 5, 6, 7, 8};
    LinkedList l(A,5);
    l.display();
    l.Delete(4);
    l.display();
}