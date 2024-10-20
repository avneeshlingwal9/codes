#include <iostream>
#include <unistd.h>
#include <ctime>
#include <cmath>
using namespace std ;
const double ERR = 0.3 ;
bool transmit(){
    
    double prob = (double)rand()/RAND_MAX;
    if(prob > ERR){
        return true;
    }
    return false ;
}
int main(){
    srand(time(nullptr));
    int ws , dt ;
    cout << "Enter the number of frames you want to send: " << endl ; 
    cin >> dt ;
    cout << "Enter the window size: " << endl;
    cin >> ws ;

    int tt = 0 , sent = 0 , rec = 0 , nr = 0 , suc = 1 , nt[ws] , k = 0 , fail = 0, re = 0 ,counter = 0; 
    while(tt < dt){
        for(int i = 0 ; i < k && !suc ; i++){
            sleep(1);
            cout << "Frame :: " << nt[i] << " Retransmitted " << endl ;
            
            

        }
        
        for(int i = 0 ; i < ws && sent < dt   ; i++){
            sleep(1);
            cout << "Frame ::" << sent << " Transmitted " << endl; 
            
            sent++;
        }
        for(int i = 0 ; i < k  && fail  ; i++  ){
            if(transmit()){
                sleep(1);
                cout << "Frame " << nt[i] << " Received Successfully " << endl ;
                re--;
                tt++;
                

            }
            else {
                sleep(1);
                cout << " Retransmit frame " << nt[i] << endl ;
                
                nt[re++] = nt[i]; 
            }
        }
        if(re == 0 ){
            suc = 1;
            k = 0 ;
        }
        
        for(int i = 0 ; i < ws && rec <dt  ; i++){
            if(transmit()){
                sleep(1);
                cout << "Frame " <<  rec << " received successfully " << endl ;
                tt++;
                
                rec++;
            }
            else{
                sleep(1);
                cout << "Retransmit Frame " << rec << " Again " << endl ;
                
                suc = 0 ; 
                fail =1 ;
                nt[k] = rec ;
                k ++;
                rec++ ; 


            }
}}
}