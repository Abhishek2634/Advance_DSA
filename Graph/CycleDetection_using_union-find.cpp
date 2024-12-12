#include <bits/stdc++.h>
using namespace std;

// Function to find the root of a set (with path compression)
int find(int node, vector<int>& parent) {
    if (parent[node] != node) {
        parent[node] = find(parent[node], parent); // Path compression
    }
    return parent[node];
}

// Function to union two sets (union by rank)
bool unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = find(u, parent);
    int rootV = find(v, parent);

    // If they have the same root, a cycle is detected
    if (rootU == rootV) {
        return true;
    }

    // Union by rank
    if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
    } else if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    } else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }

    return false; // No cycle
}

// Function to detect a cycle in an undirected graph
bool isCycle(int V, vector<pair<int, int>>& edges) {
    vector<int> parent(V);
    vector<int> rank(V, 0);

    // Initialize each node's parent to itself
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    // Process each edge
    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;

        // If unionSets returns true, a cycle is detected
        if (unionSets(u, v, parent, rank)) {
            return true;
        }
    }

    return false; // No cycle detected
}

int main() {
    int V = 5; // Number of vertices
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}};

    if (isCycle(V, edges)) {
        cout << "Cycle detected in the graph.\n";
    } else {
        cout << "No cycle detected in the graph.\n";
    }

    return 0;
}
