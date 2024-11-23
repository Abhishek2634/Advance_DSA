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

void bfs(vector<vector<Edge>>& graph){
    queue<int>q;
    q.push(0);  // taking source as 0;
    vector<bool>vis(graph.size(), false);  // taking bool vector to check if the node is present already or not;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(!vis[x]){
            vis[x] = true;
            cout << x << " ";
        }
        for(int i = 0; i < graph[x].size(); i++){
            Edge e = graph[x][i];
            if(!vis[e.dest])q.push(e.dest);
        }
    }
}

int main(){
    int s = 7;
    vector<vector<Edge>>graph(s, vector<Edge>());
    addNode(graph, 0, 1, 1);  // no use of taking weight right now, just taking for good practice.
    addNode(graph, 0, 2, 1);
    addNode(graph, 1, 0, 1);
    addNode(graph, 1, 3, 1);
    addNode(graph, 2, 0, 1);
    addNode(graph, 2, 4, 1);
    addNode(graph, 3, 1, 1);
    addNode(graph, 3, 4, 1);
    addNode(graph, 3, 5, 1);
    addNode(graph, 5, 3, 1);
    addNode(graph, 5, 4, 1);
    addNode(graph, 5, 6, 1);
    addNode(graph, 6, 5, 1);

    bfs(graph);
    return 0;
}