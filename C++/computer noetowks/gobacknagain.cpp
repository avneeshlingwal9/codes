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
    int windowsize = 4, datasent = 0, datareceived = 0, total = 10, transmitted = 0;
    
    while(transmitted < total){
        for (int i = 0; i < windowsize && datasent < total; i++){
            cout << "Frame " << datasent << " Transmitted " << endl;
            sleep(1);
            datasent++; 
        }

        for (int i = 0; i < windowsize && transmitted < total; i++)
        {
            if(transmit()){
                cout << "Frame " << datareceived << " successfully " << endl;
                sleep(1);
                datareceived++;
                transmitted++;
            }
            else{

                datasent = transmitted;
                cout << "Frame " << datareceived << " not received" << endl;
                cout << "Retransmitting the whole window again  " << endl;
                break; 
            }
        }
    }
}
