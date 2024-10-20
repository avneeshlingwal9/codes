#include <iostream>
#include <unistd.h>
#include <ctime>
using namespace std;
const double err = 0.3;
bool transmit(){
    double p = (double)rand() / RAND_MAX;
    return p > err;
}


int main(){
    srand(time(nullptr));
    int windowsize = 4, tdata = 9,  sdata = 0 , rdata = 0 , success = 0 , retrans = 0 , failindex = 0 , refailindex = 0 , s = 1;
    string fail = "", refail = "";
    while( success < tdata){

        for (int i = 0; i < windowsize && sdata < tdata ; i++){
            
            if( i < failindex){
                sleep(1);

                cout << "Frame " << fail[i] << " ReTransmitted " << endl; 
                }
            else{

                sleep(1);
                cout << "Frame " << sdata << " Transmitted successfully " << endl;
                sdata++;}
            }
            
            for (int j = 0 ; j < windowsize && success < tdata; j++ ){
            if(j < failindex){
                if(transmit()){
                    sleep(1);
                    cout << "Frame " << fail[j] << " Received successfully " << endl;
                    success++;
                }
                else {
                    sleep(1);
                    cout << "Retransmit " << fail[j] << endl;
                    refail += fail[j];
                    refailindex++;
                                }
            
            }

            else
            {
                if (transmit())
                {
                    sleep(1);
                    cout << "Frame " << rdata << " Received successfully " << endl;
                    rdata++;
                    success++;
                }
                else

                {
                    sleep(1);
                    cout << " Frame " << rdata << " Not received successfully " << endl;
                    fail.append(to_string(rdata));
                    rdata++;
                }
                } 


            }
            fail = fail.substr(failindex);
            fail = refail + fail;
            failindex = fail.length() ;
            refail = "";
            refailindex = 0;
        }    }

