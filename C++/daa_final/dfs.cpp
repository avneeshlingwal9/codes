#include <bits/stdc++.h>
#include "readinput.cpp"
using namespace std;
/*

Given a connected graph, prints its DFS traversal.

Parameters:

vector<vector<int>>& adj : Adjacency list of a graph.

int node: Starting node of the dfs.

vector<bool> visited: A visited array.



*/

void dfsPrint(vector<vector<int>> &adj, int node, vector<bool> &visited)
{
    if (visited[node])
    {
        return;
    }
    visited[node] = true;
    cout << node << " ";
    for (auto &v : adj[node])
    {

        if (!visited[node])
        {
            dfsPrint(adj, node, visited);
        }
    }
}
/*

Given a connected graph, checks if it contains a cycle or not.

Parameters:

vector<vector<int>>& adj : Adjacency list of a graph.

int node: Starting node of the dfs

vector<bool> visited: A visited array.

int parent: parent of the current call.



*/
bool dfsCycle(vector<vector<int>> &adj, int node, vector<bool> &visited, int parent)
{

    visited[node] = true;

    for (auto &v : adj[node])
    {

        if (visited[v] && v != parent)
        {

            return true;
        }

        if (!visited[v] && dfsCycle(adj, v, visited, node))
        {

            return true;
        }
    }
    return false;
}

/*

Given a graph, returns whether contains a cycle or not.

Parameters:

vector<vector<int>>& adj : Adjacency list of a graph.



*/
bool cycleDetection(vector<vector<int>> &adj)
{

    vector<bool> visited(adj.size(), false);

    int n = adj.size();

    int parent = 0;

    for (int i = 0; i < n; i++)
    {

        if (!visited[i] && dfsCycle(adj, i, visited, i))
        {

            return true;
        }
    }

    return false;
}

/*

Given a connected graph, traverse the graph in dfs traversal.

Parameters:

vector<vector<int>>& adj : Adjacency list of a graph.



*/

void traverseDfs(vector<vector<int>> &adj)
{

    int n = adj.size();

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {

        if (!visited[i])
        {

            dfsPrint(adj, i, visited);
        }
    }
}



int main()
{

    vector<vector<int>> adj = readInputGraph();

    cout << "DFS Traversal of the graph " << endl;

    traverseDfs(adj);
    cout << endl;

    if (cycleDetection(adj))
    {
        cout << "Graph contains cycle." << endl;
    }
    else
    {

        cout << "Graph does not contains cycle." << endl;
    }
}