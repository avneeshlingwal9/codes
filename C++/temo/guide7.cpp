#include <iostream>
using namespace std ;
class circularQueue{
    public :
    int front ;
    int rear ;
    int* arr ;
    int size ;
    circularQueue(int size){
        this->size = size ;
        arr = new int[size];
        front = rear = -1 ;
    }
    void enqueue(int x){
        if(this->isFull()){
            cout << "Queue overflow. " << endl ;
            return ;
        }
        else if(this->isEmpty()){
        arr[++rear] = x ;
        front = rear ;
        return ;
        }
        else {
            rear = (rear+1)%size ;
            arr[rear] = x ; 


        }
    



    }
    int dequeue(){
        if(this->isEmpty()){
            cout << "Queue is empty." << endl ;
            return -1 ;
        }
        else if((front)%size== rear){
            int r = arr[front] ;
            front = rear = -1 ;
            return r ;

        }
        else{
            int r = arr[front];
            front = (front+1)%size ;
            return r ;

        }
    }
    bool isEmpty(){
        return front==-1 ;
    }
    bool isFull(){
        return (rear+1)%size==front ;
    }
    void display(){
        if(this->isEmpty()){
            cout << "Queue is empty." << endl ;
            return ;
        }
        else {
            cout << "Elements of the array is: " << endl ;
            int i = front ;
            do{
                cout << arr[i] << " ";
                i = (i+1)%size;
            }
            while(i !=(rear+1)%size);

            
            cout << endl; 

        }
    }
    int peek(){
        return arr[front];
    }

};
int main(){
    int n , con = 0  ;
    cout << "Enter the size of the queue you want: " << endl ;
    cin >> n ;
    circularQueue q1(n);
    cout << "Enter 1 for enqueue." << "\nEnter 2 for dequeue. " <<"\nEnter 3 for peek." <<"\nEnter 4 for display." <<"\nEnter 5 for isFull" << endl ;
    cout << "Enter 6 for isEmpty." << "\nEnter -1 to exit." << endl ;
    while(con!=-1){
        cout << "Enter a choice:" << endl ;
        cin >> con ; 
        switch (con)
        {
        case 1:
        int l ;
        cout << "Enter the element: " << endl ;
        cin >> l ; 
        q1.enqueue(l);
            break;
        case 2 :
        
        cout << "Popped element is " << q1.dequeue() << endl ; 
            break ;
        case 3 :
        cout <<"Element at the top is "<<  q1.peek() << endl ;
        break ;
        case 4:
        
        q1.display();
        break;
        case 5:
        if(q1.isFull()){
            cout << "Queue is full " << endl ;
            break ;
        }
        cout << "Queue is not full " << endl; 
        break;
        case 6:
        if(q1.isEmpty()){
            cout << "Queue is empty." << endl ;
            break;
        }
        cout << "Queue is not empty." << endl; 
        break;

        
        default :
        con = -1 ;
        break ;}
            

    }
        

 }       
