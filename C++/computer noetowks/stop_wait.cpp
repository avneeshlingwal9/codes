#include <iostream>
#include <ctime>
#include <stdio.h>
#include <unistd.h>
using namespace std;
int num= 0;
const int j = 5;
const double err = 0.2;
bool receiver(int seq)

{	if(num == seq ){
		cout << "Frame received  successfully " << endl;
		num = (num + 1) % 2;
		return true;
	}

	cout << "Transmission Failed  Resend Frame " << endl;
	return false;

}
bool transmit(int seq){
	sleep(1);
	double prob = (double)rand() / RAND_MAX;
	if(prob > err && receiver(seq)){
		return true;
	}
	return false;
}
void sender(){
	int fnum; 
	cout << "Enter the frames you want to send : " << endl;
	cin >> fnum;
	for (int i = 0; i < fnum;){
		sleep(2);
		cout << "Frame number :: " << num << endl;
		if (transmit(num))
		{
			cout << "Acknowledgement received " << endl;
			i++;
		}
		else {
			cout << "Retransmitting frames " << endl; 
		}
	}
}

int main(){
	srand(time(nullptr));
	sender();
}