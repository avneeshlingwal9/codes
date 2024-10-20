#include <iostream>
using namespace std ; 
template <class T> 
/*

Creating a node class which represents a Node of the singly linked list with data members as data and pointer to next node.
*/
class Node{
    public:
    T data;
    Node* next;
    Node(){
        next = NULL;
    }
    Node(T x){
        data = x ;
    }
};
/*
Creating a class Linked List with head and using Node class.
Time Complexity of Various Functions:
insertAtFront(): O(1)
insertAtBack(): O(N) where N is the total number of nodes in the linked list
insertAtAnyPosition() : O(N) in worst case
deleteAtFront() : O(1)
deleteAtBack() : O(N)
deleteAtAnyPosition() : O(N) in worst case
check(): O(1) For checking if we can create a new node or not.



 */
template <class T>
class LinkedList{
    public:
    Node <T>* head ; 
    LinkedList(){
        head = NULL;
    }
    void insertAtFront(T data){
        Node <T> *ne = new Node(data);
        ne->next= head;
        head = ne ;}

    void insertAtBack(T data){
        Node<T>* ne = new Node(data);
        Node<T>* temp = head;
        while(temp){
            temp = temp->next;
        }
        temp->next = ne;
        if(head == NULL){
            head = ne;
        }
    }
    void insertAtAnyPosition(T data , int pos){
        Node<T> * ne = new Node(data);
        Node<T> * temp = head;
        if(head){
        for(int i = 1 ; i < pos-1  && temp ;i++ ){
            temp = temp->next;
        }
        if(temp->next){
            Node<T>* temp1 = temp->next;
            ne->next = temp1;
            
        }
        temp->next = ne;
    }
    else{
        head = ne ; 

    }}

    T deleteAtFront(){
        Node<T>* temp = head;
        head = head->next;
        int d = temp->data;
        delete temp ; 
        return d;
    }
    void deleteAtBack(){
        Node<T>* curr = head;
        Node <T>* prev =NULL;
        while(curr->next){
            prev = curr;
            curr = curr->next;
        }
        if(curr == head){
            head = NULL;
            
        }
        else{
            prev->next = NULL;
            

        }
        delete curr;

    }
    void deleteAtAnyPosition(int pos){
        Node<T>* curr = head;
        Node<T>* prev = NULL;
        for(int i = 0 ; i < pos-1 && curr;i++){
            prev = curr;
            curr = curr->next;
        }
        if(curr == head){
            head = NULL;
        }
        else{
            prev->next = curr->next;
            curr->next= NULL;    
        }
        delete curr ;

    }
    int check(){
        Node<T> *ne = new Node<T>;
        if(ne == NULL){
            return 1 ; 
        }
        else{
            return 0 ; 
        }
    }

};








