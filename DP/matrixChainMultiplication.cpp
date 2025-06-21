#include <bits/stdc++.h>
using namespace std;

int recursion_mcm(vector<int> mat, int i, int j) { // t.c == n*n;
    if(i == j) return 0;

    int ans = INT_MAX;
    for(int k = i; k <= j-1; k++) {
        int cost1 = recursion_mcm(mat, i, k);
        int cost2 = recursion_mcm(mat, k+1, j);
        int cost3 = mat[i-1] * mat[k] * mat[j];
        int finalCost = cost1+cost2+cost3;    // multiply matrix of cost1 and cost2.
        ans = min(ans, finalCost);
    }
    return ans;
}

int memo(vector<vector<int>>& dp,vector<int> mat, int i, int j) {
    if(i == j)return 0;

    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;

    for(int k = i; k <= j-1; k++) {
        int cost1 = memo(dp, mat, i, k);
        int cost2 = memo(dp, mat, k+1, j);
        int cost3 = mat[i-1] * mat[k] * mat[j];
        int finalCost = cost1+cost2+cost3;    // multiply matrix of cost1 and cost2.
        ans = min(ans, finalCost);
    }
    return dp[i][j] = ans;
}

int tabulation(vector<int>mat) {
    int n = mat.size();
    vector<vector<int>>dp(n, vector<int>(n, -1));

    for(int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    // bottom up fill
    for(int len = 2; len <= n-1; len++){
        for(int i = 1; i <= n-len; i++) {
            int j = i+len-1;//col
            dp[i][j] = INT_MAX;

            for(int k = i; k <= j-1; k++) {
                int cost1 = dp[i][k];
                int cost2 = dp[k+1][j];
                int cost3 = mat[i-1] * mat[j] * mat[k];
                dp[i][j] = min(dp[i][j], cost1+cost2+cost3);
            }
        }
    }
    return dp[1][n-1];
}

int main() {
    vector<int>mat{1, 2, 3, 4, 3};
    int n = mat.size();

    cout << recursion_mcm(mat, 1, n-1) << '\n';
    vector<vector<int>>dp(n, vector<int>(n, -1));
    cout << memo(dp, mat, 1, n-1) << "\n";
    cout << tabulation(mat);
}