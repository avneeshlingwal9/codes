#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;



class Process{
    public:
    string pid;
    int burstTime;
    int arrivalTime;
    Process(){
        cout << "Enter details of the process " << endl;
        cin >> pid >> arrivalTime >> burstTime ;
    }
    Process(string id , int btime , int atime){
        pid = id;
        burstTime = btime;
        arrivalTime = atime;
    }
    // Overloaded the output stream

    friend ostream &operator<<(ostream &os, Process &p)
    {
        os << "Process Id " << p.pid << " Burst Time " << p.burstTime << " Arrival Time " << p.arrivalTime;
        return os;
   }
   // Overloaded the operator
   bool operator<(const Process& p1 ) const{
       return burstTime > p1.burstTime;
   }


};
class Scheduling{
    public:
    queue<Process> q;
    int n;
    Scheduling(){
        cout << "Enter the number of processes you want to insert : " << endl;
        cin >> n;
        for (int i = 0; i < n; i++){
            Process p;
            q.push(p);
        }

    }
    void execution();
};

class FCFS : public Scheduling{
        public:

       void execution(){
        int waitingTime = 0, tat = 0;
        int totalWaitingTime = 0;
        int totalTAT = 0;
        int totalBurst = 0;
        cout << "Process ID " << " Arrival Time " << " Burst Time " <<  " Waiting Time " << " Turnaround Time " << endl;
        while(!q.empty()){
           
            Process p = q.front();
            q.pop();
            waitingTime = totalBurst - p.arrivalTime >= 0 ? totalBurst - p.arrivalTime : 0;
            tat = waitingTime+ p.burstTime ;
            
            totalTAT += tat;
            cout << p.pid << "            " << p.arrivalTime << "           " << p.burstTime;
            cout << "                  " << waitingTime << "           " << tat << endl;
            totalBurst+=  p.burstTime;
            totalWaitingTime += waitingTime;
        }
        cout << "Average waiting time " << (double)totalWaitingTime / (double)n << endl;
        cout << "Average turnaround time " << (double)totalTAT / (double)n << endl;
    }
};
class SJF : public Scheduling {
public:
    map<Process,int> mp;
    // As the operator < is overloaded, so map can sort them.
    vector<vector<int>> ans;
    int waitingTime = 0, tat = 0;
    int totalWaitingTime = 0;
    int totalTAT = 0;
    int totalBurst = 0;
    void calc(){
        auto it = mp.begin();
        Process p = it->first;
        mp.erase(it);
        waitingTime = totalBurst - p.arrivalTime >= 0 ? totalBurst - p.arrivalTime : 0;
        tat = waitingTime + p.burstTime;
        totalTAT += tat;
        ans.push_back({waitingTime, tat});
        totalBurst += p.burstTime;
        totalWaitingTime += waitingTime;
    }

    void execution()  {
        

        while(!q.empty()){
            /* if(mp.empty()){
                Process p = q.front();
                q.pop();
                mp[p] = p.arrivalTime;
                calc();
            } */
           
            while( q.front().arrivalTime <= totalBurst){
            Process p = q.front();
            q.pop();
            mp[p] = p.arrivalTime;
            
        }

        }
        
        

        while (!mp.empty()) {
            calc();
        }

        cout << "Average waiting time: " << (double)totalWaitingTime / (double)n << endl;
        cout << "Average turnaround time: " << (double)totalTAT / (double)n << endl;
    }

    void display() {
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
};

/* class SJF{
    public:
        map<int, Process> q;
        map<int, int> arrivals;
        vector<vector<int>> ans;
        int n; 
        SJF()
        {
            cout << "Enter the number of totat processes : " << endl;
            cin >> n;
           
            int i = 0;
            while(i < n){
            cout << "Enter the  arrival time and number of processes at that time : " << endl;
            int atime = 0, pcount = 0;
            cin >> atime >> pcount;
            arrivals[atime] = pcount;
            i += pcount;}
    }
    int waitingTime = 0, tat = 0;
    int totalWaitingTime = 0;
    int totalTAT = 0;
    int totalBurst = 0;
    void calculate( ){
        auto it = q.begin();
        
        Process p = it->second;
        q.erase(it);
        waitingTime = totalBurst - p.arrivalTime >= 0 ? totalBurst - p.arrivalTime : 0;
        tat = waitingTime+ p.burstTime ;
        totalTAT += tat;
        ans.push_back({waitingTime, tat});
        

        totalBurst+=  p.burstTime;
        totalWaitingTime += waitingTime;


    }
    void execution(){

        int count = 0;
        for(auto it : arrivals){
            for (int i = 0; i < it.second; i++){
                Process p;
                q[p.burstTime] = p;
            }
            calculate();
            
        }
        while(!q.empty()){
            calculate();

            q.erase(q.begin());
        }    
}
void display(){
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

}; */

int main(){
    SJF s;
    s.execution();
    s.display();
}