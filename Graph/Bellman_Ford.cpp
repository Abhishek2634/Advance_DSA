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

void Bellman_Ford(vector<vector<Edge>>& graph, int src) {        // T.c = O(V * E) 
    int n = graph.size();
    vector<int>dis(n, INT_MAX);
    dis[0] = 0;

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < graph.size(); j++){
            for(int k = 0; k < graph[j].size(); k++){
                Edge e = graph[j][k];
                int u = e.src;
                int v = e.dest;
                int wt = e.wt;
                if(dis[u] != INT_MAX  and dis[u] + wt < dis[v]){
                    dis[v] = wt + dis[u];
                }
            }

        }
    }
    for(int i = 0; i < dis.size(); i++){
        cout << dis[i] << " ";
    }
}

int main(){
    int s = 5;
    vector<vector<Edge>>graph(s, vector<Edge>());
    addNode(graph, 0, 1, 2);  
    addNode(graph, 0, 2, 4);
    addNode(graph, 1, 2, -4);
    addNode(graph, 2, 3, 2);
    addNode(graph, 3, 4, 4);
    addNode(graph, 4, 1, -1);

    int src = 0; // taking source as 0 and finding min distance from src to all possible destinations
    Bellman_Ford(graph, src);

    return 0;
}