#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int src;
    int dest;
    int wt;

    Edge(int s, int d, int w) {
        src = s;
        dest = d;
        wt = w;
    }
};

void addNode(vector<vector<Edge>>& graph, vector<vector<int>> flights) {
    for (int i = 0; i < flights.size(); i++) {
        Edge e = Edge(flights[i][0], flights[i][1], flights[i][2]);
        graph[flights[i][0]].push_back(e);
    }
}

void cheapestFlight(int n, vector<vector<int>> flights, int src, int dest, int k) {
    vector<vector<Edge>> graph(n, vector<Edge>());
    addNode(graph, flights);

    vector<int> dis(n, INT_MAX);
    dis[src] = 0;

    queue<tuple<int, int, int>> q; // tuple represent {Node, Cost, Stops}
    q.push({src, 0, 0});           // Start from the source with cost 0 and 0 stops.

    while (!q.empty()) {
        auto [node, cost, stops] = q.front();
        q.pop();

        if (stops > k) continue; // Stop processing if we've exceeded allowed stops.

        for (auto& e : graph[node]) {
            int nextNode = e.dest;
            int nextCost = cost + e.wt;

            if (nextCost < dis[nextNode] && stops <= k) {
                dis[nextNode] = nextCost;
                q.push({nextNode, nextCost, stops + 1});
            }
        }
    }

    if (dis[dest] == INT_MAX)
        cout << "No path within " << k << " stops.\n";
    else
        cout << "Cheapest cost from " << src << " to " << dest << " within " << k << " stops: " << dis[dest] << "\n";
}

int main() {
    int s = 4;
    vector<vector<int>> flights{{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    int src = 0, dest = 3, k = 1;
    cheapestFlight(s, flights, src, dest, k);

    return 0;
}
