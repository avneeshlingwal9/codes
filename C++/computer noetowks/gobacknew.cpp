#include <iostream>
#include <unistd.h>
#include <ctime>
const double ERR = 0.5;
using namespace std ;
bool transmit(){
    sleep(1);
    double p = (double)rand()/RAND_MAX;
    if(p> ERR){
        return true;
    }
    return false; 
}
int main(){
    srand(time(nullptr));
    int windowsize,datan ;
    cout << "Enter the amount of bits you want to send : " << endl;
    cin >> datan ;
    cout << "Enter the window size: " << endl ;
    cin >> windowsize ;
    int transmitted = 0 , sent = 0 ,rec = 0 ;
    while(transmitted < datan ){
        for(int i =0 ; i < windowsize && sent < datan ; i++){
            cout << " Frame " << sent << " Sent  " << endl ;
            sleep(1);
            
            sent++;

        }
        for(int i = 0 ; i < windowsize && transmitted < datan ; i++){
            if(transmit()){ 
                cout << "Frame " << rec << " Received Successfully " << endl;
                rec++ ;
                transmitted++;
                
            }
            else {
                cout << "Frame " <<  rec << " Not Transmitted "  <<  endl ;
                sent = transmitted;
                cout <<" Retransmitting the whole window " << endl ; 
                break; 
            }

        }
        
    }



}


