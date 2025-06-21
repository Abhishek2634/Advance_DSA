#include <bits/stdc++.h>
using namespace std;

int tab(int sum, vector<int>coins) {
    vector<int>dp(sum+1, 0);
    dp[0] = 1;

    for(int coin : coins) {
        for(int j = coin; j <= sum; j++) {
            dp[j] += dp[j-coin];
        }   
    }
    return dp[sum];
}

int tabulation(int sum, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>>dp(n+1, vector<int>(sum+1, 0));

    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < sum+1; j++) {
            int val = coins[i-1];

            if(val <= j) {
                dp[i][j] = dp[i][j-val] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main() {
    int sum = 10;
    vector<int>coins{2, 5, 3, 6};
    cout << tabulation(sum, coins);  // 1-D array
    cout << "\n";
    cout << tab(sum, coins); // 1-D array.
}