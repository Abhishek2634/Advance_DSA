#include <bits/stdc++.h>
using namespace std;

void createGraph(vector<tuple<int,int,int>>& edges){
    edges.push_back({0, 1, 10});
    edges.push_back({0, 2, 15});
    edges.push_back({0, 3, 30});
    edges.push_back({1, 3, 40});
    edges.push_back({2, 3, 50});
}
int n = 4;
vector<int> parent(n);
vector<int> ranks(n, 0);

void init(){
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
}

int find(int x){
    if(x == parent[x]){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unionSets(int a, int b){
    int parA = find(a);
    int parB = find(b);

    if(ranks[parA] == ranks[parB]){
        parent[parB] = parA;
        ranks[parA]++;
    }else if(ranks[parA] < ranks[parB]){
        parent[parA] = parB;
    }else{
        parent[parB] = parA;
    }
}
// t.c = O(v + ElogE)
int KruskalsMst(vector<tuple<int,int,int>>edges, int v){
    init();
    sort(edges.begin(), edges.end()); // O(ElogE)
    int mstCost = 0;
    int cnt = 0;

    for(int i = 0; cnt < v-1; i++){// O(v);
        auto [src, dest, wt] = edges[i];

        int parA = find(src);
        int parB = find(dest);

        if(parA != parB){
            unionSets(src, dest);
            mstCost += wt;
            cnt++;
        }
    }
    return mstCost;
}
int main(){
    int v = 4;
    vector<tuple<int,int,int>>edges(v);
    createGraph(edges);
    cout << "cost of MST is : " << KruskalsMst(edges, v);
    return 0;
}