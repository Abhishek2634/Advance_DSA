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

bool detectCycleUtil(vector<vector<Edge>>& graph, vector<bool>& vis, int curr, int parent){
    vis[curr] = true;
    for(int i = 0; i < graph[curr].size(); i++){
        Edge e = graph[curr][i];
        if(!vis[e.dest]){
            if(detectCycleUtil(graph, vis, e.dest, curr)) return true;
        }else if(vis[e.dest] && e.dest != parent){
            return true;
        }
    }
    return false;
}

bool detectCycle(vector<vector<Edge>>& graph) {
    vector<bool>vis(graph.size(), false);  // taking bool vector to check if the node val is present already or not;
    for(int i = 0; i < graph.size(); i++){
        if(!vis[i]){   
            if(detectCycleUtil(graph,vis,i,-1)){
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
    addNode(graph, 0, 3, 1);
    addNode(graph, 1, 0, 1);
    addNode(graph, 1, 2, 1);
    addNode(graph, 2, 1, 1);
    addNode(graph, 2, 0, 1);
    addNode(graph, 3, 4, 1);
    addNode(graph, 3, 0, 1);
    addNode(graph, 4, 3, 1);


    if(detectCycle(graph)){
        cout << "cycle is present in graph";
    }else{
        cout << "cycle is not present in graph";
    }
    return 0;
}