#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj , int u , vector<int>&finish , vector<bool>& visited , int& time){

    time = time + 1;
    visited[u] = true;
    for(auto& v : adj[u]){
        if(!visited[v]){
            
            dfs(adj, v, finish, visited, time);

        }
    }

    time = time + 1;
    finish.push_back(time);
}

void print(vector<int>& vec){
    for(auto& it : vec){
        cout << it << " ";
    }
    cout << endl; 
}
int main(){

    vector<vector<int>> adj{{ 1, 2, 3 },{ 0, 2 },{ 0, 1, 3 },{ 0, 2 }};

    vector<int> finish;
    vector<bool> visited(adj.size(), false);
    int time = 0;
    dfs(adj, 0, finish, visited, time);
    print(finish);
}