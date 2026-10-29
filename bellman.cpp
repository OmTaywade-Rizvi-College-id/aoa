#include <iostream>
#include <vector>
using namespace std;

class Edge
{
public:
    int v, wt;
    Edge(int v, int wt)
    {
        this->v = v;
        this->wt = wt;
    }
};

void bellmanFord(int V, int src, vector<vector<Edge>> &g)
{
    vector<int> d(V, INT_MAX);
    d[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (int u = 0; u < V; u++)
        {
            for (Edge e : g[u])
            {
                if(d[u] != INT_MAX && d[e.v] > d[u] + e.wt){
                    d[e.v] = d[u] + e.wt;
                }
            }
        }
    }

    for (int i = 0; i < V; i++){
        if(d[i] == INT_MAX){
            cout << src << "-> " << i << " = INF"<<endl;
        }else{
            cout << src << "-> " << i << " = " << d[i]<<endl;
        }
    }
}

int main(){
    int V = 6;

    vector<vector<Edge>> g(V);
    g[0].push_back(Edge(1, 1));
    g[0].push_back(Edge(3, 1));
    g[1].push_back(Edge(2, 1));
    g[3].push_back(Edge(2, -3));
    bellmanFord(V, 0, g);
    return 0;
}