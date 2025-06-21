#include <bits/stdc++.h>
using namespace std;


bool tabulation(vector<int>sum, int target) {
    int n = sum.size();
    vector<vector<bool>>dp(n+1, vector<bool>(target+1,false));

    for(int i = 0; i <= n; i++){
        dp[i][0] = true;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= target; j++) {
            // i - items and j - target sum.
            int v = sum[i-1];
            // include.
            if(v <= j && dp[i-1][j-v]){
                dp[i][j] = true;
            }else if(dp[i-1][j]){ // exclude.
                dp[i][j] = true;
            }
        }
    }

     for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= target; j++) {
            cout << dp[i][j] << " ";
        }   
        cout << '\n';
    }

    return dp[n][target];
}

int main() {
    int target = 10;
    vector<int>sum{4,2,7,1,3};
    cout << boolalpha << tabulation(sum,target);
}