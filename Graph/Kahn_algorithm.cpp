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

void calcInd(vector<vector<Edge>>& graph, vector<int>& indegree){
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            Edge e = graph[i][j];
            indegree[e.dest]++;
        }
    }
}
void topSort(vector<vector<Edge>>& graph) {
    vector<int>indegree(graph.size(),0);
    calcInd(graph,indegree);

    queue<int>q;

    for(int i = 0; i < graph.size(); i++){
        if(indegree[i] == 0)q.push(i);
    }

    while(!q.empty()){          // bfs
        int x = q.front();
        cout << x << " ";
        q.pop();

        for(int i = 0; i < graph[x].size(); i++){
            Edge e = graph[x][i];
            indegree[e.dest]--;
            if(indegree[e.dest] == 0)q.push(e.dest);
        }
    }
}

int main(){
    // Topological sort using Bfs is also known as Kahn's algo where we need to calculate Indegree of each node. node which have least indegree comes first in order, means which is not dependent on any other node.

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