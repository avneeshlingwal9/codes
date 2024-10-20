#include <iostream>
using namespace std ;
#define INFINITY 9999
#define size 5 
void dijkstra(int adjacency[size][size], int nodes , int start){
    int cost[size][size];
    for(int i = 0 ; i < nodes ; i++){
        for(int j = 0 ; j < nodes; j++){
            if(adjacency[i][j] == 0 ){
                cost[i][j] = INFINITY;
            }
            else{
                cost[i][j] = adjacency[i][j];
            }
        }
    }
    int distance[nodes], previous[nodes],visited[nodes]={0} , prevnode ,min;
    for(int i=0; i < nodes; i++){
        distance[i] = cost[start][i];
        previous[i]=start;
    }
    int count = 1 ;
    while(count < nodes){
        min = INFINITY;
        prevnode = -1 ;
        for(int i= 0; i < nodes ; i++){
            if(!visited[i] && distance[i] < min){
                min = distance[i];
                prevnode = i ;


            }
            
        }
        visited[prevnode]=1 ;
        for(int i =0 ; i < nodes ; i++){
            if(!visited[i]){
                if(min+cost[prevnode][i] < distance[i]){
                    distance[i]= min + cost[prevnode][i] ;
                    previous[i] = prevnode;
                }
            }
        }
    count++;

        
    }
    for(int i = 0 ; i < nodes ; i++){
        if(i!= start){
            cout << "\n Distance between node "<< start << " and " << i << " is " << distance[i] << endl ;
         
         int j = i ;
         cout << "\n Path is " << i  ;
         do{
            j = previous[j];
            cout << " <- " << j ; 
        


         }
         while(j!=start);}
    }
}
int main(){
    int nodes = size , start ;
    cout << "Enter the start node : " << endl ;
    cin >> start ; 
    /*int adjacencymatrix[size][size];
    cout <<"Enter the cost between the nodes: " << endl;
    for(int i =0 ;i < nodes ; i++){
        for(int j= 0 ; j < nodes; j++){
            cin >> adjacencymatrix[i][j];
        }
    }*/
    int adjacencymatrix[size][size]= {{0,6,0,1,0},{6,0,5,2,2},{0,5,0,0,5},{1,2,0,0,1},{0,2,5,1,0}};
    dijkstra(adjacencymatrix,nodes,start);

}