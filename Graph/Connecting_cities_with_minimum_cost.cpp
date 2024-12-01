#include <bits/stdc++.h>
using namespace std;

int connectCities(vector<vector<int>>& cities, int n) {
    vector<bool> vis(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start from node 0
    pq.push({0, 0}); // {cost, node}
    int finalCost = 0;

    while (!pq.empty()) {
        auto [currentCost, currentNode] = pq.top();
        pq.pop();

        if (vis[currentNode]) continue;

        vis[currentNode] = true;
        finalCost += currentCost;

        // Push neighbors into the priority queue
        for (int i = 0; i < n; i++) {
            if (cities[currentNode][i] != 0 && !vis[i]) {
                pq.push({cities[currentNode][i], i}); 
            }
        }
    }

    return finalCost;
}


int main() {
    int s = 5;
    vector<vector<int>> cities{
        {0, 1, 2, 3, 4},
        {1, 0, 5, 0, 7},
        {2, 5, 0, 6, 0},
        {3, 0, 6, 0, 0},
        {4, 7, 0, 0, 0}
    };

    int ans = connectCities(cities, s);
    cout << "Minimum cost to connect all cities: " << ans << endl;

    return 0;
}
