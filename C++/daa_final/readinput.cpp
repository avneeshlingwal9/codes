#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*

Reads an undirected graph and returns an adjacency list as output.

The input of file is as such:

First line contains number of vertices.

Second line contains number of edges.

After that the edges (u,v)


*/
vector<vector<int>> readInputGraph()
{

    int vertices = 0, edges = 0;

    cout << "Enter the number of vertices: " << endl;

    cin >> vertices;

    vector<vector<int>> adj(vertices);

    cout << "Enter the number of edges: " << endl;

    cin >> edges;

    for (int i = 0; i < edges; i++)
    {

        int u, v;

        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return adj;
}

vector<int> readInput()
{

    int n = 0;

    cout << "Enter the number of elements: " << endl;

    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    return arr;
}

vector<vector<pair<int,int>>> readInputWeightedGraph()
{

    int vertices = 0, edges = 0;

    cout << "Enter the number of vertices: " << endl;

    cin >> vertices;

    vector<vector<pair<int,int>>> adj(vertices);

    cout << "Enter the number of edges: " << endl;

    cin >> edges;

    for (int i = 0; i < edges; i++)
    {

        int u, v , d;

        cin >> u >> v >> d;

        adj[u].push_back({v , d});
        adj[v].push_back({u, d});
    }

    return adj;
}

void print(const vector<int>& arr){

    for(auto& i : arr){
        cout << i << " ";
    }
    cout << endl;
}