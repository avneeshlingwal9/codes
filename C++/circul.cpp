#include <iostream>
int arr[5] ;
using namespace std ;
class Queuee{
    public:

    int front ;
    int rear ;
    int size ; 
    char* arr ; 
    Queuee(int n){
        front = -1 ;
        rear = -1 ;
        size = n ;
        arr = new char[size];


    }
    void enquee(char x){
        if(front == -1){
            arr[0] = x ;
            front= rear = 0 ; 
        }
        else if(front != (rear+1)%size ){
            arr[(rear+1)%size] = x ; 
            rear = (rear+1)%size ;
        }
            
        else{
             cout << "Overflow s \n" ; 
        }

        
    }
    int dedquee(){
        if(front == -1){
            cout << "Underflow \n" ; 
            return -1  ; 
        }
        else if( front == (rear)%size){
            int k = front ;
            front = rear = -1 ; 
            return arr[k];



        }
        else{
            front = (front+1)%size ;
            return arr[front];
            
        }
    }
    void sho(){
        cout << "front " << front << " rear "  << rear << endl ; 
    
        for(int i = front%size ; i < size; i++){
            cout << arr[i] << " " ; 
        }
        cout << endl ;
    }
};


int main(){
    Queuee q1(6);
    q1.enquee('B');
    q1.sho();
    q1.enquee('A');
    q1.sho();
    q1.enquee('C');
    q1.sho();
    q1.enquee('D');
    q1.sho();
    q1.dedquee();
    q1.sho();
    q1.enquee('F');
    q1.sho();
    q1.dedquee();
    q1.sho();
    q1.dedquee();
    q1.sho();
    q1.enquee('K');
    q1.sho();
    q1.enquee('L');
    q1.sho();
    q1.enquee('M');
    q1.sho();
    q1.dedquee();
    q1.sho();
    q1.dedquee();
    q1.sho();
    q1.dedquee();
    q1.sho();
    q1.enquee('S');
    q1.sho();

    



    
    
    
}