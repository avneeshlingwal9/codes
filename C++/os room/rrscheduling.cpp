#include <queue>
#include <iostream>
using namespace std;
class Process{
    public:
        string pid;
        int arrivalTime;
        int burstTime;
        int waitingTime;
        int turnaroundTime;
    Process(){
        cout << "Enter process details " << endl;
        cin >> pid >> arrivalTime >> burstTime;
        waitingTime = -1;
        turnaroundTime = 0;
    }

};
class RoundRobin{
    public:
        int timeslice;
        int numOfProcess;
        queue<Process> q;
        queue<Process> completed;
        RoundRobin(int t)
        {
            timeslice = t;
            cout << "Enter the number of processes: " << endl;
            cin >> numOfProcess;
            for (int i = 0; i < numOfProcess; i++)
            {
                Process p;
                q.push(p);
            }

        
        }

    void execution(){
        int cputime = 0;
        while(!q.empty()){
            Process p = q.front();
            q.pop();
            if(p.waitingTime == -1){
                p.waitingTime = cputime - p.arrivalTime;
            }
            int c = 0;
            while(p.burstTime > 0 && c < timeslice){
                c++;
                p.burstTime--;
            }
        
            cputime += c;
            if(p.burstTime ==0){
                p.turnaroundTime = cputime-p.arrivalTime;
                completed.push(p);
            }
            else{
                q.push(p);
            }
        }
    }
    void display(){
        int totalWaitingTime = 0;
        int totalTurnaroundTime = 0;
        cout << " Process id " << " Arrival Time " << " Waiting Time " << " Turnaround Time  " << endl;
        while(!completed.empty()){
            Process p = completed.front();
            totalTurnaroundTime += p.turnaroundTime;
            totalWaitingTime += p.waitingTime;
            completed.pop();
            cout << p.pid << "            " << p.arrivalTime << "               " << p.waitingTime << "                 " << p.turnaroundTime << endl;
        }

        cout << "Average waiting time is: " << (double)totalWaitingTime / (double)n;
        cout << "Average turnaround time is: " << (double)totalTurnaroundTime / (double)n;
    }
};

int main(){
    RoundRobin r(2);
    r.execution();
    r.display();
}