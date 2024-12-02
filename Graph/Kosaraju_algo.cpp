#include <bits/stdc++.h>
using namespace std;

void createGraph(vector<vector<pair<int, int>>>& graph) {

    graph[0].push_back({0, 2}); 
    graph[0].push_back({0, 3}); 
    graph[1].push_back({1, 0}); 
    graph[2].push_back({2, 1}); 
    graph[3].push_back({3, 4}); 
}

void topSort(vector<vector<pair<int, int>>>& graph, int curr, vector<bool>& vis, stack<int>& s) {
    vis[curr] = true;
    for (int i = 0; i < graph[curr].size(); i++) {
        auto x = graph[curr][i];
        if (!vis[x.second]) {
            topSort(graph, x.second, vis, s);
        }
    }
    s.push(curr);
}

void dfs(vector<vector<pair<int, int>>>& graph, int curr, vector<bool>& vis) {
    vis[curr] = true;
    cout << curr << " ";
    for (int i = 0; i < graph[curr].size(); i++) {
        auto x = graph[curr][i];
        if (!vis[x.second]) {
            dfs(graph, x.second, vis);
        }
    }
}

void Kosaraju(vector<vector<pair<int, int>>>& graph, int v) {
    stack<int> s;
    vector<bool> vis(v, false);

    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            topSort(graph, i, vis, s);
        }
    }

    vector<vector<pair<int, int>>> transpose(v);
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            auto x = graph[i][j];
            transpose[x.second].push_back({x.second, x.first});
        }
    }

    fill(vis.begin(), vis.end(), false);
    while (!s.empty()) {
        int curr = s.top();
        s.pop();
        if (!vis[curr]) {
            cout << "This is SSC:-  ";
            dfs(transpose, curr, vis); 
            cout << "\n";
        }
    }
}

int main() {
    int v = 5;
    vector<vector<pair<int, int>>> graph(v);
    createGraph(graph);
    Kosaraju(graph, v);

    return 0;
}