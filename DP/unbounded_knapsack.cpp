#include <bits/stdc++.h>
using namespace std;

int tabulation(vector<int>& val, vector<int>& wt, int W, int n){
    vector<vector<int>>dp(n+1, vector<int>(W+1,0));

    for(int i = 1; i < n+1; i++) {
        int v = val[i-1];
        int w = wt[i-1];
        for(int j = 1; j < W+1; j++) {      // i == no. of items       and       j == size of knapsack.
            if(w <= j) {
                int inc = v+dp[i][j-w];
                int exe = dp[i-1][j];
                dp[i][j] = max(inc, exe);
            }else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < W+1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "\n";
    return dp[n][W];
}


int main(){
    vector<int>val = {15, 14, 10, 45, 30};
    vector<int>wt = {2, 5 ,1, 3, 4};
    int W = 7;
    int n = val.size();
    // cout <<  knapsack(val, wt, W, n) << '\n'; // recursion
    // vector<vector<int>>dp(n+1, vector<int>(W+1, -1));
    // cout << memoisation(val, wt, W, n,dp) << '\n';// memoisation
    cout << tabulation(val, wt, W, n) << '\n'; // tabulation
}