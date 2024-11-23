#include <bits/stdc++.h>
using namespace std;

// here i will learn how to create a graph using Adjacency list

struct Edge{
public:
    int src, dest, wt;

    Edge(int s, int d, int w) {
        src = s;
        dest = d;
        wt = w;
    }
};

void add(vector<vector<Edge>>& graph, int src, int dest, int wt) {
    graph[src].push_back(Edge(src, dest, wt)); 
}

int main() {
    int v = 5; 
    vector<vector<Edge>> graph(v); 
    
    add(graph, 0, 1, 5);
    add(graph, 1, 0, 5);
    add(graph, 1, 2, 1);
    add(graph, 1, 3, 3);
    add(graph, 2, 1, 1);
    add(graph, 2, 3, 1);
    add(graph, 2, 4, 2);
    add(graph, 3, 1, 3);
    add(graph, 3, 2, 1);
    add(graph, 4, 2, 2);
    
    for(int i = 0; i < v; i++) {
        cout << "Vertex " << i << " -> ";
        for(auto &edge : graph[i]) {
            cout << "[" << edge.src << "->" << edge.dest << ", wt: " << edge.wt << "] ";
        }
        cout << endl;
    }

    return 0;
}
