#include <iostream>
using namespace std;
template <class T>
class Node{
    public :
    T data ;
    Node *next; 
    Node(T d , Node* nxt){
        data = d ;
        nxt = NULL;
    }
   
};

class SList{
    public :
    Node* head ; 
    SList(){
        head = NULL;
    }
    void InsB(){
        
    }
}


int main(){
    cout << "Hello World" << endl; 
    Node<int> n(34,NULL);
    cout << n.add(4.23,5.69) << endl ; 
}