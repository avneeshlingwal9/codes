#include <iostream>
#include <unistd.h>

using namespace std ;
#define INFINITY 9999 
#define siz 7

void dijkstra(int node[siz][siz], int num , int start){
    int cost[siz][siz];
    for(int i = 0 ; i < num ;i++){
        for(int j =0 ; j < num ; j++){
            if(node[i][j] == 0 ){
                cost[i][j] = INFINITY;
            }
            else{
                cost[i][j] = node[i][j];
            }
        }
    }
    int distance[num], visited[num]={0} , prev[num] ;
    int nextnode ;
    
    for(int i = 0 ; i < num ; i++){
        distance[i] = cost[start][i];
        prev[i] = start ; 
        

    }
    distance[start] = 0 ;
    visited[start]= 1;

    
    int c = 1;
    while(c < num){
        nextnode = -1 ;
        int min = INFINITY;
        for(int i= 0 ; i < num; i++){
            if(distance[i] < min && !visited[i]){
                min = distance[i];
                nextnode = i ;

                }}     
            visited[nextnode] = 1 ;

        
        for(int i =0 ;i < num ; i++){
            if(!visited[i]){
                if(min+cost[nextnode][i] < distance[i]){
                    distance[i] = min+cost[nextnode][i] ;
                    prev[i] = nextnode;
            
                }
            }
        }
        c++;

    }
    for(int i =0 ; i < num ; i++){
        int j = 0 ;
        if(i!=start){
            cout << "Distance of node " << i << " is " << distance[i] << endl; 
            cout << "Path = " << i ;
            j = i ; 
            do{
                j = prev[j];
                cout <<"<-"<<j;


            }while(j!=start);
        }
    }



    
}
int main(){
    int snode , nodes = siz ;
    
    int adjacencymatrix[siz][siz];
    cout << "Enter the cost between the nodes: " << endl;
    for(int i =0 ; i < nodes;i++){
        for(int j=0;j<nodes ; j++){
            cin >> adjacencymatrix[i][j];
        }
    }
    cout << "Enter the startnode: " << endl;
    cin >> snode;
    dijkstra(adjacencymatrix,nodes,snode);
}

