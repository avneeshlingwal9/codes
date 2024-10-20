#include <iostream>
#include <unistd.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

const double ERR = 0.3;

bool transmit() {
    sleep(2);
    double p = (double)rand() / RAND_MAX;
    return p > ERR;
}

int main() {
    srand(time(nullptr));
    int ws, dt;
    cout << "Enter the data to be transmitted : " << endl;
    cin >> dt;
    cout << "Enter the window size: " << endl;
    cin >> ws;
    int tt = 0, sent = 0, rec = 0, numlen = 0;
    string num = "", ref = "";
    while (tt < dt) {
        ref = "";
        for (int i = 0; i < ws && sent < dt; i++) {
            if (i < numlen) {
                cout << "Frame :: " << num[i] << " Retransmitted " << endl;
                sleep(1);
            } else {
                cout << " Frame :: " << sent << " Transmitted " << endl;
                sleep(1);
                sent++;
            }
        }
        for (int i = 0; i < ws && tt < dt; i++) {
            if (i < numlen) {
                if (transmit()) {
                    cout << "Frame :: " << num[i] << " Received Successfully " << endl;
                    sleep(1);
                    tt++;
                } else {
                    cout << "Retransmit Frame :: " << num[i] << endl;
                    sleep(1);
                    ref += num[i];
                }
            }
            if (transmit()) {
                cout << "Frame :: " << rec << " Received Successfully " << endl;
                sleep(1);
                rec++;
                tt++;
            } else {
                cout << "Retransmit Frame :: " << rec << endl;
                sleep(1);
                num += to_string(rec);
                rec++;
            }
        }
        num = ref;
        numlen = num.length();
    }
    cout << num << endl;
    return 0;
}
