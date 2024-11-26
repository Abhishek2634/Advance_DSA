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

// T.C = O(V^V) in the worst case; exponential time complexity arises when the graph is highly connected, 
// and we are exploring all possible paths between the source and destination nodes.

void dfs(vector<vector<Edge>>& graph,int src, int dest, string path) {
    path+=to_string(src);
    if(src == dest){
        for(int i = 0; i < path.size(); i++){
            if(i > 0)cout << " --> ";
            cout << path[i];
        }
        cout << "\n";
    }
    for(int i = 0; i < graph[src].size(); i++){
        Edge e = graph[src][i];
        dfs(graph, e.dest, dest, path);
    }
   
}

int main(){
    // print all paths from src to target in a directed graph.
    int s = 6;
    vector<vector<Edge>>graph(s, vector<Edge>());
    addNode(graph, 0, 3, 1);
    addNode(graph, 2, 3, 1);  // no use of taking weight right now, just taking for good practice.
    addNode(graph, 3, 1, 1);
    addNode(graph, 4, 0, 1);
    addNode(graph, 4, 1, 1);
    addNode(graph, 5, 0, 1);
    addNode(graph, 5, 2, 1);

    dfs(graph, 5, 1, "");
    return 0;
}



