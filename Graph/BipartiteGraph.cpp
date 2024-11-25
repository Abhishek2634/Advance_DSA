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

// A graph is bipartite if we can separate its nodes into two disjoint sets such that no two nodes in the same set are adjacent. The sizes of the sets do not determine whether the graph is bipartite.
//To determine if a graph is bipartite, we use 2-coloring (via BFS or DFS). During this process, if two adjacent nodes are found to have the same color, the graph is not bipartite.

void addNode(vector<vector<Edge>>& graph, int src, int dest, int wt){
        graph[src].push_back(Edge(src, dest,wt));
}

bool isBipartite(vector<vector<Edge>>& graph) {
    vector<int>colour(graph.size(),-1);  // taking bool vector to check if the node val is present already or not;
    queue<int>q;

    for(int i = 0; i < graph.size(); i++){
        if(colour[i] == -1){       // bfs
            q.push(i);
            colour[i] = 0;// yellow
            while(!q.empty()){
                int x = q.front();
                q.pop();
                for(int i = 0; i < graph[x].size(); i++){
                    Edge e = graph[x][i];
                    if(colour[e.dest] == -1){
                        int nextCol = colour[x] == 0 ? 1 : 0;  // 1 == blue, for reference
                        colour[e.dest] = nextCol;
                        q.push(e.dest);
                    }else if(colour[e.dest] == colour[x]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    int s = 5;
    vector<vector<Edge>>graph(s, vector<Edge>());
    addNode(graph, 0, 1, 1);  // no use of taking weight right now, just taking for good practice.
    addNode(graph, 0, 2, 1);
    addNode(graph, 1, 0, 1);
    addNode(graph, 1, 3, 1);
    addNode(graph, 2, 4, 1);
    addNode(graph, 2, 0, 1);
    addNode(graph, 3, 4, 1);
    addNode(graph, 3, 1, 1);
    addNode(graph, 4, 3, 1);
    addNode(graph, 4, 2, 1);

    // some points to remember:   if a graph is Acyclic then it is always bipartite. if it has even cycle then bipartite, if it has odd
    // cycle then it is not bipartite....
    
    if(isBipartite(graph)){
        cout << "graph is Bipartite";
    }else{
        cout << "graph is not Bipartite";
    }
    return 0;
}