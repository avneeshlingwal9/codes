#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
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
/*         Process() : pid(0), arrivalTime(0), burstTime(0), waitingTime(0), turnaroundTime(0), lastTime(0), timeRequired(0) {}; */

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
struct compareByBurstTime{
    bool operator()(const Process &p1, const Process &p2) const{
        return p1.timeRequired > p2.timeRequired;
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
void checkShortProcess(vector<Process> &process , int &currIndex , Process &curr ,  int currentCycle,  priority_queue<Process, vector<Process>, compareByBurstTime> &processQueue ){
    
    if(currIndex == process.size()){
        return;
    }
    else{
        while(currIndex < process.size() && process[currIndex].arrivalTime <= currentCycle){
            processQueue.push(process[currIndex]);
            currIndex++;
        }
    }
}
void calculateSJF(vector<Process> &process ){
    sort(process.begin(), process.end(), [](const Process &a, const Process &b)
         { return a.arrivalTime < b.arrivalTime; });
    double avgWaitingTime = 0;
    int currentCycle = process[0].arrivalTime;
    double avgTurnaroundTime = 0;
    priority_queue<Process, vector<Process>, compareByBurstTime> processQueue;
    processQueue.push(process[0]);
    int currIndex = 1; 
    while(!processQueue.empty()){
        Process curr = processQueue.top();
        processQueue.pop();
        while(curr.timeRequired > 0){
            curr.timeRequired--;
            currentCycle++;
            checkShortProcess(process, currIndex, curr,currentCycle ,processQueue);
            if(!processQueue.empty() && processQueue.top().timeRequired < curr.timeRequired){
                break;
            }
            

        }

        if(curr.timeRequired == 0){
            
            curr.turnaroundTime = currentCycle - curr.arrivalTime;
            curr.waitingTime += curr.turnaroundTime - curr.burstTime;
            

            avgTurnaroundTime += curr.turnaroundTime;
            avgWaitingTime += (double)curr.waitingTime;
        }
        else{
            
            curr.waitingTime += currentCycle - curr.lastTime;
            curr.lastTime = currentCycle;
            processQueue.push(curr);
        }
        for (int i = 0; i < process.size(); i++){
            if(process[i].pid == curr.pid){
                process[i] = curr;
                break;
            }
        }
    }

    avgTurnaroundTime = avgTurnaroundTime / process.size();
    avgWaitingTime = avgWaitingTime / process.size();
    display(process, avgTurnaroundTime, avgWaitingTime);
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

    calculateSJF(process);
}