#include <iostream>
using namespace std;
#define INFINITY 99999
#define size 5 
void dijkstra(int a[size][size] , int start , int nodes){
    int cost[nodes][nodes];
    for (int i = 0; i < nodes; i++){
        for (int j = 0; j < nodes; j++){
            if(a[i][j] == 0 ){
                cost[i][j] = INFINITY;
            }
            else{
                cost[i][j] = a[i][j];
            }
        }
    }
    int distance[nodes],  visited[nodes] = {0} , previous[nodes] , min = 0 , prev = 0 ;
    for (int i = 0; i < nodes; i++){
        distance[i] = cost[start][i];
        previous[i] = start;
    }
    visited[start] = 1;
    int count = 1;
    while(count < nodes){
        min = INFINITY;
        prev = -1;
        for (int i = 0; i < nodes; i++){
            if( !visited[i] && distance[i] < min ){
                min = distance[i];
                prev = i;
            }
            if(prev==-1){
                break;
            }
            visited[prev] = 1;
        }
        for (int i = 0; i < nodes; i++){
            if(min + cost[prev][i] < distance[i]){
                distance[i] = min + cost[prev][i];
                previous[i] = prev;
            }
        }
        count++;
        }
        for (int i = 0; i < nodes; i++){
            if(i!=start){
                cout << "\nDistance of " << i << " from " << start << " is " << distance[i] << endl;

            }
            int j = i;
            cout << "Path is " << i; 
            do{
                j = previous[j];
                cout << "->" << j;

            } while (j != start);
        }
}

int main(){

int adjacencymatrix[size][size]= {{0,6,0,1,0},{6,0,5,2,2},{0,5,0,0,5},{1,2,0,0,1},{0,2,5,1,0}};
    dijkstra(adjacencymatrix,1,5);

}