#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

struct Packet{
    int pno;
    string data;

};
struct Frame
{
    int Fno = 0  ;
    Packet p ;
    int ack ; 

};
class SAW{
    public : 
    double er = 0.1 ;
    Frame f ; 
    int bits; 
    int j = 2;
    
    bool transmit(int i){
        srand(j);
        j= j*2;
        
    
        if(rand()/RAND_MAX > er && receiver(i)){
            

        return true ;
    }
    
    return false ;
    

}

void sender(){
    cout << "Enter the bits you want to send: " << endl; 
    cin >> bits ;
    for (int i = 0 ; i < bits; i++){
        f.p.pno = i ; 
        j = 2*j;
        cout << "Sending data :: " << endl ;
        if(transmit(f.Fno)){
            f.Fno = (f.Fno+1)%2 ;
            cout << "Acknowledgement received " << endl; 

        }
        
        else{
            cout << "Retransmitting the frame:: " << endl ; 
            i--;
        }


        

    }
    

}
bool receiver(int i ){
    if((i%2)==f.Fno){
        cout << " Receiver:: Packet received " << endl ;
        cout << "Acknowledgement sent " << endl ;
        f.Fno = (f.Fno+1) %2 ;
        return true; 

    } 
    return false;
}

};





int main(){
    srand(time(NULL));
    SAW s ;
    s.sender();





}


