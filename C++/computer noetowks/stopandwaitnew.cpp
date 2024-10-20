#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;
const int j = 5 ;
int framenum = 0 ; 
const double er = 0.1 ;
bool receiver(int seqn){
    if(seqn == framenum){
        cout << "Receiver:: Received " << endl ;
        framenum = (framenum+1)%2 ;
        return true ;
    }
    return false ;

}
bool transmit( int seqno){
    sleep(2);
    double p = (double)rand()/RAND_MAX;
    if(p > er && receiver(seqno)){
        return true;
    }
    return false;
}


int main(){
    srand(time(nullptr));
    for(int i = 0 ; i < j ; i++){
        cout << "Sending frame number :: " << framenum << endl ;
        if(transmit(framenum)){
            cout << "Sender :: Transmission successful. Acknowlegment received. " << endl ;

        }
    else{
        cout << "Transmission unsuccessful. Retransmitting " << endl ;
        i--; 

    }




    }
    


}