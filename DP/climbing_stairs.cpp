#include <bits/stdc++.h>
using namespace std;
// find ways to reach nth stair. the person can climb either 1 stair or 2 stair at a time.

int recursion(int n){
    if(n == 1 || n == 2)return n;
    return recursion(n-1) + recursion(n-2);
}

int memo(int n, vector<int>& dp) {
    if(n == 1 || n == 2) return n;
    if(dp[n] != -1)return dp[n];
    return dp[n] = memo(n-1, dp) + memo(n-2, dp);
}

int tabulation(int n, vector<int>dp){
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3 ; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {
    int n = 5;
    cout << recursion(n) << '\n';
    vector<int> dp(n+3, -1);
    cout << memo(n, dp) << '\n';
    dp.resize(n+3);
    cout << tabulation(n, dp);
}