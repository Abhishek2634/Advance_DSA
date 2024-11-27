#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int src;
        int dest;
        int wt;

        Edge(int s, int d, int w){
            src = s;
            dest = d;
            wt = w;
        }
};

void addNode(vector<vector<Edge>>& graph, int src, int dest, int wt){
        graph[src].push_back(Edge(src, dest,wt));
}

void dijkstra(vector<vector<Edge>>& graph, int src) {         // T.c = O((V+E)logV); logV for inserting nodes in pq;
    vector<int>dist(graph.size(), INT_MAX);  // dist[i] = src to i;
    dist[src] = 0;
    vector<bool>vis(graph.size(),false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        if(!vis[x.second]){
            vis[x.second] = true;
            for(int i = 0; i < graph[x.second].size(); i++){
                Edge e = graph[x.second][i];
                int u = e.src;
                int v = e.dest;
                int wt = e.wt;
                
                if(dist[x.second] + wt < dist[v]){
                    dist[v] = dist[x.second] + wt;
                    pq.push({dist[v],v});
                }
            }
        }
    }
    for(int i = 0;  i < dist.size(); i++){
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main(){
    int s = 6;
    vector<vector<Edge>>graph(s, vector<Edge>());
    addNode(graph, 0, 1, 2);  
    addNode(graph, 0, 2, 4);
    addNode(graph, 1, 2, 1);
    addNode(graph, 1, 3, 7);
    addNode(graph, 2, 4, 3);
    addNode(graph, 3, 5, 1);
    addNode(graph, 4, 3, 2);
    addNode(graph, 4, 5, 5);

    int src = 0; // taking source as 0 and finding min distance from src to all possible destinations
    dijkstra(graph, src);

    return 0;
}