#include <iostream>
#include <time.h>
#include <unistd.h>
double er = 0.1;
using namespace std ;
int cfr = 0 ; 
const int windowsize = 3 ;
int windex = 0 ; 

bool receiver(int sf){
    for(int i = 0 ; i < windowsize; i++){
        if(cfr+i != i){
            break;
        }

    }
    return false ;
}
bool transmit(int sf , int l ){
    srand(l);

    
    double p = (double)rand()/RAND_MAX;
    if(p > er && receiver(sf)){
        return true ; 
    }


    return false ;
}










int main(){
    srand(time(nullptr));
    int i ;
    cout << "Enter the number of frames you want to send: " << endl ;
    cin >> i ;
    
    while(cfr < i ){
        int l = rand();
        for(windex = 0; windex < windowsize; windex++ ){
            cout << "Sender:: Frame sent:  " << windex << endl ;  
        }
        windex = 0 ;
        if(transmit(l,cfr+windowsize)){
            
            cout << "Sender:: Transmission Successful. Acknowledgement Received. " << endl ;
            windex = 0 ; 
            cfr = cfr+windowsize;

        }
        else{
            cout << "Sender:: Transmission Failed. Retransmitting window. "  << endl; 
            windex=0;
        }



        



    }


}