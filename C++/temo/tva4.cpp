#include <iostream>
using namespace std ;
class Queuee{
    public:
    char* arr ;
    int size ; 
    int rear ;
    int front ;
    Queuee(int s){
        this->size = s ;

        this->arr = new char[size];
        rear = front = -1; 
    }
    void enqueee(char x)
    {
        if(front==-1 ){
            front=rear = 0;
            arr[rear] = x ;
        }
        else if(front != (rear+1)%size){
            rear = (rear+1)%size ;
            arr[rear] = x ;
        }
        else{
            cout << "Queue overflow" << endl ;
        }

    }
    char dequeee(){
        if(front ==-1){
            cout << "Queue underflow " << endl ; 
            return 'null' ;
        }
        else if(front == rear){
            char a = arr[front];
            front = rear = -1 ;
            return a ; 

        }
        else{
            char a = arr[front];
            front = (front+1)%size ;
            return a ;
        }
    }
    void sh(){
        cout << "Front " << front << " Rear " << rear << endl ;
        for(int i = 0 ; i < size ; i++){
            cout << arr[i] << " " ;
        }
        cout << endl ;
    }


};
int main(){
    Queuee q(6);
    q.enqueee('B');
    q.enqueee('A');
    
    q.enqueee('C');

    q.enqueee('D');
    q.dequeee();
    q.sh();
    q.enqueee('F');
    q.sh();
    q.dequeee();
    q.dequeee();
    q.sh();
    q.enqueee('K');
    q.enqueee('L');
    q.enqueee('M');
    q.sh();
    q.dequeee();

    q.dequeee();

    q.dequeee();
    q.sh();
    q.enqueee('S');
    q.sh();



}