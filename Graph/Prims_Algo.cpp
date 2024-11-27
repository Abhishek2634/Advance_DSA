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

void PrimAlgo(vector<vector<Edge>>& graph, int src) {         // T.c = O((V+E)logV); logV for inserting nodes in pq;
    vector<bool>vis(graph.size(),false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0, src});
    int finalCost = 0; // MST Cost or total min weight;

    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();

        int cost = x.first;
        int vertex = x.second;

        if (!vis[vertex]) {
            vis[vertex] = true;
            finalCost += cost;

            for (auto& e : graph[vertex]) {
                if (!vis[e.dest]) {
                    pq.push({e.wt, e.dest});
                }
            }
        }
    }
    cout << "min cost of MST : " <<  finalCost;
}

int main(){
    int s = 5;
    vector<vector<Edge>>graph(s, vector<Edge>());
    addNode(graph, 0, 1, 10);  
    addNode(graph, 0, 2, 15);
    addNode(graph, 0, 3, 30);
    addNode(graph, 1, 0, 10);
    addNode(graph, 1, 3, 40);
    addNode(graph, 2, 0, 15);
    addNode(graph, 2, 3, 50);
    addNode(graph, 3, 1, 40);
    addNode(graph, 3, 2, 50);

    int src = 0; // taking source as 0 and finding min spanning tree
    PrimAlgo(graph, src);

    return 0;
}