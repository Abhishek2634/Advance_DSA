#include <bits/stdc++.h>
using namespace std;


// this is a question where we need to find whether there exist any path b/w any two nodes/ vertices.
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


bool hasPath(vector<vector<Edge>>& graph, int src, int dest, vector<bool>& vis) {
    if(src == dest)return true; // base case;
    if(!vis[src]){
        vis[src] = true;
        for(int i = 0; i < graph[src].size(); i++){
            Edge e = graph[src][i];
            if(!vis[e.dest] && hasPath(graph, e.dest, dest, vis)){
                return true;
            } 
        }
    }
    return false;
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
    addNode(graph, 4, 2, 1);
    addNode(graph, 4, 3, 1);
    addNode(graph, 4, 5, 1);
    addNode(graph, 5, 3, 1);
    addNode(graph, 5, 4, 1);
    addNode(graph, 5, 6, 1);
    addNode(graph, 6, 5, 1);

    vector<bool>vis(graph.size(), false);  // taking bool vector to check if the node val is present already or not;
    cout << boolalpha << hasPath(graph, 0, 3, vis);
    return 0;
}