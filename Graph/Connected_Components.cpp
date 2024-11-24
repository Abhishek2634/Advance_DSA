#include <bits/stdc++.h>
using namespace std;
// here we will learn how to traverse connected components in graph;

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

void dfs(vector<vector<Edge>>& graph, int node, vector<bool>& vis) {
    if (!vis[node]) {
        vis[node] = true;
        cout << node << ' '; 
        for (int j = 0; j < graph[node].size(); j++) {
            Edge e = graph[node][j];
            if (!vis[e.dest]) {
                dfs(graph, e.dest, vis);
            }
        }
    }
}

void dfsUtil(vector<vector<Edge>>& graph ,int node, vector<bool>& vis){
    if(graph[node].size() == 0)return;
    vis[node] = true;
    cout << node << ' ';
    for(int i = 0; i < graph[node].size(); i++){
        Edge e = graph[node][i];
        if(!vis[e.dest])dfsUtil(graph, e.dest, vis);
    }
}

void dfs(vector<vector<Edge>>graph){
    vector<bool>vis(graph.size(), false); 
    for(int i = 0; i < graph.size(); i++){
        if(!vis[i])dfsUtil(graph, i, vis); 
    } 
}

void bfsUtil(vector<vector<Edge>>& graph ,int node, vector<bool>& vis){
    if(graph[node].size() == 0)return;
    vis[node] = true;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int x = q.front(); q.pop();
        cout << x << ' ';
        for(int i = 0; i < graph[x].size(); i++){
            Edge e = graph[x][i];
            if(!vis[e.dest]){
                vis[e.dest] = true;
                q.push(e.dest);
            }
        }
    }
}

void bfs(vector<vector<Edge>>graph){
    vector<bool>vis(graph.size(),false);
    for(int i = 0; i < graph.size(); i++){
        if(!vis[i]){
            bfsUtil(graph, i, vis);
        }
    }
}
int main(){
    int s = 20;
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
    addNode(graph, 4, 2, 1);
    addNode(graph, 4, 3, 1);
    addNode(graph, 4, 5, 1);
    addNode(graph, 5, 3, 1);
    addNode(graph, 5, 4, 1);
    addNode(graph, 5, 6, 1);
    addNode(graph, 6, 5, 1);

    addNode(graph, 9, 10, 1);       // they are different components in 
    addNode(graph,10, 9, 1);       // itself                                           
    
    cout << "DFS Work on connected components : ";  dfs(graph); // print using dfs
    cout << "\n";
    cout << "BFS Work on connected components : "; bfs(graph); // print using bfs;
    return 0;
}