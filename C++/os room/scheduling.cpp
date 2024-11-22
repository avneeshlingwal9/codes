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
        int lastTime;
        int completionTime;
        int timeRequired;
        Process(string apid, int aarrivalTime, int aburstTime)
        {
            pid = apid;
            arrivalTime = aarrivalTime;
            burstTime = aburstTime;
            waitingTime = 0;
            turnaroundTime = 0;
            lastTime = aarrivalTime;
            timeRequired = aburstTime;
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
void checkAnyNewProcesses(vector<Process> &process, int &currIndex ,  int currentCycle, queue<int> &processQueue )
{
    if(currIndex == process.size()){
        return;
    }
    else{
        while(currIndex < process.size() && process[currIndex].arrivalTime <= currentCycle  ){
            processQueue.push(currIndex);
            currIndex++;
        }

    }
    
}
void calculateRR(vector<Process> &process , int timeSlice ){
    sort(process.begin(), process.end(), [](const Process &a, const Process &b)
         { return a.arrivalTime < b.arrivalTime; });

    double avgWaitingTime = 0;
    int currentCycle = process[0].arrivalTime;
    double avgTurnaroundTime = 0;
    int quantum = timeSlice;
    queue<int> processQueue;
    processQueue.push(0);
    int currIndex = 1;
    while(!processQueue.empty()){
        int index = processQueue.front();
        Process &curr = process[index];
        processQueue.pop();
        curr.waitingTime += currentCycle - curr.lastTime;

        while(quantum > 0 && curr.timeRequired > 0){
            curr.timeRequired--;
            quantum--;
            currentCycle++;
            checkAnyNewProcesses(process, currIndex, currentCycle, processQueue);
        }
        if(curr.timeRequired == 0){
            curr.turnaroundTime = currentCycle - curr.arrivalTime;
            avgTurnaroundTime += curr.turnaroundTime;
            avgWaitingTime += (double)curr.waitingTime;

        }
        else{
            curr.lastTime = currentCycle;
            processQueue.push(index);
        }
        quantum = timeSlice;
    }

    avgTurnaroundTime = avgTurnaroundTime / process.size();
    avgWaitingTime = avgWaitingTime / process.size();
    display(process, avgTurnaroundTime, avgWaitingTime);
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
    
    calculateRR(process,2);
    
}