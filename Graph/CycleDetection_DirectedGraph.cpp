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

bool detectCycleUtil(vector<vector<Edge>>& graph, vector<bool>& vis, int curr, vector<bool>& stack){
    vis[curr] = true;
    stack[curr] = true;
    
    for(int i = 0; i < graph[curr].size(); i++){
        Edge e = graph[curr][i];
        if(stack[e.dest]){ // cycle.
            return true;
        }
        if(!vis[e.dest] && detectCycleUtil(graph, vis, e.dest, stack)){
            return true;
        }
    }
    stack[curr] = false;
    return false;
}

bool detectCycle(vector<vector<Edge>>& graph) {
    vector<bool>vis(graph.size(), false);  // taking bool vector to check if the node val is present already or not;
    vector<bool>stack(graph.size(), false);

    for(int i = 0; i < graph.size(); i++){
        if(!vis[i]){   
            if(detectCycleUtil(graph,vis,i,stack)){
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
    addNode(graph, 1, 3, 1);
    addNode(graph, 2, 3, 1);

    if(detectCycle(graph)){
        cout << "cycle is present in directed graph (uni_directional)";
    }else{
        cout << "cycle is not present in directed graph";
    }
    return 0;
}