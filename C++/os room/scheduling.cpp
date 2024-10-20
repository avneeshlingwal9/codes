#include <iostream>
#include <queue>
using namespace std ;
struct Process{
    int timeslice;
    string pid ;
    int arrivaltime ; 
};
void processInsertion(queue<Process>&q1 ){
    int n ;
    cout <<"Enter the processes you want to run : " << endl; 
    cin >> n ;
    cout <<"Enter the process id and respective time slices for your process " << endl; 
    for(int i =0 ; i < n ; i++){
        Process p ;
        cin >> p.pid;
        cin >> p.timeslice;
        p.arrivaltime = i ;      
        q1.push(p); 

    }
}
void display(queue<Process> q){
    queue<Process> q1 = q ;
    while(!q1.empty()){
        cout << q1.front().pid <<  " " << q1.front().timeslice << " " << q1.front().arrivaltime <<  endl;
        q1.pop();
    }
}
void fcfs(queue<Process>&q){
    double avgtime = 0 ;
    int start = 0 ;
    while(!q.empty()){
        Process curr = q.front();
        avgtime+=curr.timeslice;
        cout << curr.pid << " is running from " << start << " -> " << curr.timeslice+start   << endl;
        start+=curr.timeslice;



    }
}
int main(){
queue<Process> q1 ;
processInsertion(q1);
display(q1);



}