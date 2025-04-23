#include <bits/stdc++.h>
#include "readinput.cpp"
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int source)
{
    int n = adj.size();
    // Priority queue contains the {dist , node}
    vector<int> dist(n, INT_MAX);
    /*     priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int,int>>> pq ; */
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    dist[0] = 0;
    while (!pq.empty())
    {
        auto [dis, u] = pq.top();

        pq.pop();

        for (auto [v, cost] : adj[u])
        {

            if (dis + cost < dist[v])
            {

                dist[v] = dis + cost;

                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
int main(){
    vector<vector<pair<int, int>>> adj = readInputWeightedGraph();
}
