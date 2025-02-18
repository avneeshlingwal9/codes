#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

void bfs(vector<vector<int>>& adj , int node){
    vector<bool> visited(adj.size(), false);
    queue<int> qu;
    qu.push(node);
    visited[node] = true;
    cout << node << " ";
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        for(auto& v : adj[u]){
            if(!visited[v]){
                cout << v << " ";
                visited[v] = true;
                qu.push(v);
            }
        }
    }

}
void dfs(vector<vector<int>>& adj , vector<bool>& visited , int node){
    visited[node] = true;
    cout << node << " ";
    for(auto& v : adj[node]){
        if(!visited[v]){
            dfs(adj, visited, v);

        }

    }
}
int main(){

    vector<vector<int>> adj;
    adj.push_back({2, 3, 1});
    adj.push_back({0});
    adj.push_back({0, 4});
    adj.push_back({0});
    adj.push_back({2});
    bfs(adj,0);
    cout << endl;
    vector<bool> visited(adj.size(), false);
    dfs(adj, visited, 0);
}