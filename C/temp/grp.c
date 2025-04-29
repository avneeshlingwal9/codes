#include <stdlib.h>
#include <stdio.h>
struct Node{
    int dest ;
    Node* next ;

};
struct Node* createnewnode(int dest){
    Node* newn = struct Node*malloc(sizeof(struct Node));
    newn->dest = dest ;
    newn->next = NULL ;
    return newn ;

}
struct graph{
    int numvertices ;
    struct Node** adjacencylist ;
};
struct graph* creategraph(int num){
    graph* g = struct graph*malloc(num* sizeof(struct Node));
    g->numvertices = num ;
    for(int i =0 ; i < num; i++){
        adjacencylist[i] = NULL;
    }

}
void addedge(struct graph* g , int start , int destination){
    Node* n = createnewnode(destination);
    n->next = g->adjacencylist[start] ;
    g->adjacencylist[start]->next = n;
    Node* m = createnewnode(start);
    m->next = g->adjacencylist[destination];
    g->adjacencylist[destination]->next = m ;


}
void printgraph(struct graph* g){
    for(int i  =0 ; i < g->numvertices; i++){
        Node* n = g->adjacencylist[i];
        while(n!= NULL){
            printf(n->dest);
            n = n->next ;
        }
        cout << "NULL\n" ;
    }

}
int main(){
    struct Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);



    return 0;
}

