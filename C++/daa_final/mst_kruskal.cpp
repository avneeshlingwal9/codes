#include <bits/stdc++.h>
#include "readinput.cpp"
using namespace std;
class DSU{

    vector<int> rank;
    vector<int> parent;

    DSU(int n){

        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0; 
        }

    }

    void Union(int a , int b){
        int parent_a = find(a);
        int parent_b = find(b);
        if(rank[parent_a] > rank[parent_b]){

            parent[parent_b] = parent_a;

        }
        else{

            parent[parent_a] = parent_b;
        }
    }
    int find(int a){
        if(parent[a] == a){
            return a;

        }
        return parent[a] = find(parent[a]);
    }



};

int kruskal(vector<vector<pair<int,int>>>& adj){

    // Convert into edges.
    DSU dsu(adj.size());

    auto comp = [](vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    };

    sort(edges.begin(), edges.end() , comp);

    int mincost = 0; 
    for(auto& it : edges){

        int u = it[0];
        int v = it[1];
        int d = it[2];
        int parent_u = dsu.find(u);
        int parent_v = dsu.find(v);
        if(parent_u != parent_v){

            mincost += d;
            dsu.Union(u, v);
        }

    }
    return mincost;
}
int main(){

    vector<vector<pair<int,int>>> adj = readInputGraph();

    int mincost = kruskal(adj);
}