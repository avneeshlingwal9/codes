#include <iostream>
using namespace std;
#define size 5 
#define INFINITY 9999 
void dijkstra(int adj[size][size] , int start , int nodes){
    int cost[size][size];
    for (int i = 0; i < nodes; i++){
        for (int j = 0; j < nodes; j++){
            if(adj[i][j] == 0 ){
                cost[i][j] = INFINITY;
            }
            else{
                cost[i][j] = adj[i][j] ;
            }
        }
    }
    int count = 1, dist[nodes] , previous[nodes], visited[nodes] = {0}, min, prev ;
    for (int i = 0; i < nodes; i++){
        
            dist[i] = cost[start][i];
            previous[i] = start;
        

    }
    visited[start] = 1;
    while(count < nodes){
        min = INFINITY;
        prev = -1;
        for (int i = 0; i < nodes; i++){
            if(!visited[i] && dist[i] < min){
                min = dist[i];
                prev = i; 
            }
        }
        visited[prev] = 1;
        
        for (int i = 0; i < nodes; i++){
            if(!visited[i]){
            if(cost[prev][i] + min < dist[i]){
                dist[i] = cost[prev][i] + min;
                previous[i] = prev; 
            }}
        }
        count++;
    }
    for (int i = 0; i < nodes; i++){
        if(i != start){
            cout << "Distance from " << start << " to node " << i << " is " << dist[i ] << endl; 
        }
    }
}
int main(){
        int adjacencymatrix[size][size]= {{0,6,0,1,0},{6,0,5,2,2},{0,5,0,0,5},{1,2,0,0,1},{0,2,5,1,0}};
        dijkstra(adjacencymatrix , 0,size );
}