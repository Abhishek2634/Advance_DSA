#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>>& images, int sr, int sc, int col, vector<vector<bool>>& vis, int originalcol){
    if(sc < 0 || sr < 0 || sr >= images.size()|| sc >= images[0].size() || vis[sr][sc] || images[sr][sc] != originalcol){
        return;
    }
    images[sr][sc] = col;
    vis[sr][sc] = true;
    helper(images, sr-1, sc, col, vis, originalcol);
    helper(images, sr, sc-1, col, vis, originalcol);
    helper(images, sr+1, sc, col, vis, originalcol);
    helper(images, sr, sc+1, col, vis, originalcol);
}

vector<vector<int>> flood_fill(vector<vector<int>>images, int sr, int sc, int col){
    int n = images.size(); 
    int m = images[0].size();
    vector<vector<bool>>vis(n, vector<bool>(m, false));
    helper(images, sr, sc, col, vis, images[sr][sc]);
    return images;
}



int main(){
    vector<vector<int>>images{{1,1,1}, {1,1,0}, {1,0,1}};
    int col = 2; // color we need to fill;
    int sr = 1; // starting row;
    int sc = 1; // starting col
    vector<vector<int>> res = flood_fill(images, sr, sc, col);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[0].size(); j++){
            cout << res[i][j] << ' ';
        }
        cout << "\n";
    }
}