#include <bits/stdc++.h>
#include "readinput.cpp"
using namespace std;
/*



Given a connected graph, prints the bfs order traversal.

Parameters:

    vector<vector<int>> adj :- Adjacency List of the Graph.

    int node : Starting node for the bfs.

    vector<bool> visited: Boolean array to keep track of the visited nodes.

Output:

    Prints the nodes of the graph in BFS traversal.








*/
void bfs(vector<vector<int>> &adj, int node, vector<bool> &visited)
{

    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        // For each neighbor of u .
        q.pop();

        for (auto &v : adj[u])
        {

            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }

    cout << endl;
}
/*



Given a connected graph, prints the bfs order traversal.

Parameters:

    vector<vector<int>> adj :- Adjacency List of the Graph.


Output:

    Prints the nodes of the graph in BFS traversal.








*/
void bfsGraph(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(adj, i, visited);
        }
    }
}
/*



Given a adjacency list of connected graph returns whether it is connected or not.

Parameters:

    vector<vector<int>> adj :- Adjacency List of the Graph.

    int node : Starting node for the bfs.

    vector<bool> color: Boolean array to keep track of colors of the visited nodes.

Output:

    Returs a boolean value, denoting whether a graph is twocolorable or not.








*/
bool twocolorabilitybfs(vector<vector<int>> &adj, int node, vector<int> &color)
{

    // -1 not visited.
    // 0 black
    // 1 white
    queue<int> q;

    q.push(node);

    color[node] = 1;

    while (!q.empty())
    {

        int u = q.front();

        q.pop();

        for (auto &v : adj[u])
        {

            if (color[v] == color[u])
            {

                return false;
            }
            if (color[v] == -1)
            {

                color[v] = 1 - color[u];

                q.push(v);
            }
        }
    }
    return true;
}
/*

Given a graph returns whether it is bipartite or not.

*/

bool twoColorabilityCheck(vector<vector<int>> &adj)
{

    int n = adj.size();

    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {

        if (color[i] == -1 && !twocolorabilitybfs(adj, i, color))
        {

            return false;
        }
    }

    return true;
}

int main()
{

    vector<vector<int>> adj = readInputGraph();

    cout << "BFS Traversal of the graph " << endl;

    bfsGraph(adj);

    if (twoColorabilityCheck(adj))
    {
        cout << "Graph is two colorable" << endl;
    }
    else
    {

        cout << "Graph is not two colorable " << endl;
    }
}