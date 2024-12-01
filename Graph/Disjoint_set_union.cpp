#include <bits/stdc++.h>
using namespace std;

int n = 7;
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

int main(){
    init();
    unionSets(1, 3);
    cout << find(3) << "\n";
    unionSets(2, 4);
    unionSets(3, 6);
    unionSets(1, 4);
    cout << find(3) << "\n";
    cout << find(4) << "\n";
    unionSets(1, 5);
    return 0;
}