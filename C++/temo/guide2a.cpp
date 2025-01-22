#include <iostream>
using namespace std ;
class Node{
    public :
    int data ;
    Node* next ;
    Node(int x){
        data = x ;
        next = NULL ;

    }

};
class Linkedlist{
    public :
    Node* head ; 
    Linkedlist(){
        head = NULL ;
    }
    void insertatend(int x){
        Node* newnode = new Node(x);
        
        if(head == NULL){
            head = newnode ;
        }
        else{
            Node* temp = head ;
            while(temp->next != NULL){
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;

        }
        
    }
    void sh(){
        Node* temp = head ;
        while(temp != NULL){
            cout << temp->data << " " ;
            temp = temp->next;
        }
        cout << endl ; 
    }
    bool linearsearch(int n ){
        bool found = false ;
        Node* temp = head ;
        while(temp!= NULL){
            if(temp->data == n){
                found = true ;
                return found ;
            }
            temp = temp->next;
        }
        return found ;


    }
};
int main(){
    Linkedlist l ;
    int n , e , f ; 
    cout << "Enter the number of elements you want to insert in the linked list: " << endl ;
    cin >> n ;
    cout << "Enter the elements of the linked list: " << endl ;
    for(int i = 0 ; i < n ; i++){
        cin >> e ;
        l.insertatend(e);

    }
    l.sh();
    cout << "Enter the element you want to search in the linked list: " << endl ;
    cin >> f ;
    if(l.linearsearch(f)){
        cout << "The element exists in the linked list. " << endl ;

    }
    else{
        cout << "Element does not exist in the linked list. " << endl ;
    }


}