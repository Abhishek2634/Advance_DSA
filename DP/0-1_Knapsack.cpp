#include <bits/stdc++.h>
using namespace std;

// recursion -> T.c : O(2^n)
int knapsack(vector<int>& val, vector<int>& wt, int W, int n){
    if (W == 0 || n == 0) return 0;
    if (wt[n-1] <= W) {
        // include;
        int ans1 = val[n-1] + knapsack(val, wt, W-wt[n-1], n-1);
        // exclude
        int ans2 = knapsack(val, wt, W, n-1);
        return max(ans1, ans2);
    } else { // not valid;
        return knapsack(val, wt, W-wt[n-1], n-1);
    }
}

//T.c : O(n);
int memoisation(vector<int>& val, vector<int>& wt, int W, int n, vector<vector<int>>&dp){
    if(W == 0 || n == 0)return 0;
    if(dp[n][W] != -1)return dp[n][W];

    if (wt[n-1] <= W) {
        int ans1 = val[n-1] + memoisation(val, wt, W-wt[n-1], n-1, dp);
        int ans2 = memoisation(val, wt, W, n-1, dp);
        return max(ans1, ans2);
    } else {
        return memoisation(val, wt, W, n-1, dp);
    }
}

int tabulation(vector<int>& val, vector<int>& wt, int W, int n){
    vector<vector<int>>dp(n+1, vector<int>(W+1,0));
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < W+1; j++){
            int v = val[i-1];
            int w = wt[i-1];
            if(w <= j){ // valid
                int include = v + dp[i-1][j-w];
                int exclude = dp[i-1][j];
                dp[i][j] = max(include,exclude);
            }else{ // invalid
                int exclude = dp[i-1][j];
                dp[i][j] = exclude;
            }
        }
    }
    return dp[n][W];
}

int main(){
    vector<int>val = {15, 14, 10, 45, 30};
    vector<int>wt = {2, 5 ,1, 3, 4};
    int W = 7;
    int n = val.size();
    cout <<  knapsack(val, wt, W, n) << '\n'; // recursion
    vector<vector<int>>dp(n+1, vector<int>(W+1, -1));
    cout << memoisation(val, wt, W, n,dp) << '\n';// memoisation
    cout << tabulation(val, wt, W, n) << '\n'; // tabulation
}