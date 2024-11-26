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

void topSortUtil(vector<vector<Edge>>& graph, vector<bool>& vis, int curr, stack<int>& stack){
    vis[curr] = true;

    for(int i = 0; i < graph[curr].size(); i++){
        Edge e = graph[curr][i];
        if(!vis[e.dest]){
            topSortUtil(graph,vis,e.dest,stack);
        }
    }

    stack.push(curr);
}

void topSort(vector<vector<Edge>>& graph) {
    vector<bool>vis(graph.size(), false);  // taking bool vector to check if the node val is present already or not;
    stack<int>stack;

    for(int i = 0; i < graph.size(); i++){
        if(!vis[i]){   
            topSortUtil(graph,vis,i,stack); // modified dfs.
        }
    }

    while(!stack.empty()){
        cout << stack.top() << " ";
        stack.pop();
    }
}

int main(){
    // Topological sorting works only For DAG means (directed Acyclic Graphs) means graph with no cycle and unidirected.
    // it is a linear order of vertices such that every directed edge u -> v, the vertex u comes before v in order.

    int s = 6;
    vector<vector<Edge>>graph(s, vector<Edge>());
    addNode(graph, 2, 3, 1);  // no use of taking weight right now, just taking for good practice.
    addNode(graph, 3, 1, 1);
    addNode(graph, 4, 0, 1);
    addNode(graph, 4, 1, 1);
    addNode(graph, 5, 0, 1);
    addNode(graph, 5, 2, 1);

    topSort(graph);
    return 0;
}