#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;
const int j = 5 ;
int rec = 0 ; 
const double er = 0.1 ;
bool receiver(int seqn){
    if(seqn == rec){
        cout << "Receiver:: Received " << endl ;
        rec = (rec+1)%2 ;
        return true ;
    }
    return false ;

}
bool transmit(int l, int seqno){
    sleep(1);
    srand(l);
    double p = (double)rand()/RAND_MAX;
    if(p > er && receiver(seqno)){
        return true;
    }
    return false;
}


int main(){
    srand(time(nullptr));
    for(int i = 0 ; i < j ; i++){
        cout << "Sending frame number :: " << rec << endl ;
        int l = rand();
        if(transmit(l,rec)){
            cout << "Transmission successful " << endl ;

        }
    else{
        cout << "Transmission unsuccessful. Retransmitting " << endl ;
        i--; 

    }




    }
    


}