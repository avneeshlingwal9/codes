#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class Process{
    public:
        string pid;
        int arrivalTime;
        int burstTime;
        int waitingTime;
        int turnaroundTime;
    Process(string apid, int aarrivalTime, int aburstTime){
        pid = apid;
        arrivalTime = aarrivalTime;
        burstTime = aburstTime;
        waitingTime = 0;
        turnaroundTime = 0;
    }
};
void display(vector<Process> &process , double avgTAT , double avgWT){
    cout << "ProcessID " << "ArrivalTime " << "BurstTime " << "WaitingTime " << "TurnaroundTime " << endl;
    for(auto i : process){
        cout << "\t" <<i.pid << "\t" << i.arrivalTime << "\t" << i.burstTime << "\t\t" << i.waitingTime << "\t" << i.turnaroundTime << endl;

    }
    cout << "Average Turnaround time: " << avgTAT << endl;
    cout << "Average Waiting Time: " << avgWT << endl; 
}

void calculateFCFS(vector<Process> &process ){
    sort(process.begin(), process.end(), [](const Process &a, const Process &b)
         { return a.arrivalTime < b.arrivalTime; });

    double avgWaitingTime = 0;
    int currentCycle = process[0].arrivalTime;
    double avgTurnaroundTime = 0;
    for (auto &i : process){
        i.waitingTime = currentCycle- i.arrivalTime;
        avgWaitingTime += (double)i.waitingTime;
        currentCycle += i.burstTime;
        i.turnaroundTime = currentCycle - i.arrivalTime;
        avgTurnaroundTime += (double)i.turnaroundTime;

    }
    avgTurnaroundTime = avgTurnaroundTime / process.size();
    avgWaitingTime = avgWaitingTime / process.size();
    display(process, avgTurnaroundTime, avgWaitingTime);
}


int main(){
    Process p1("P1", 0, 8);
    Process p2("P2", 1, 4);
    Process p3("P3", 2, 9);
    Process p4("P4", 3, 5);
    vector<Process> process = {p1, p2, p3, p4};
    
    calculateFCFS(process);
    
}