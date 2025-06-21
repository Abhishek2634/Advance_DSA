#include <bits/stdc++.h>
using namespace std;

int catalan_num(int num) {
    if(num == 1 || num == 0) return 1;
    int ans = 0;
    for(int i = 0; i < num; i++) {
        ans += catalan_num(i) * catalan_num(num-i-1);
    } 
    return ans;
}

int memo(int num, vector<int>& dp) { // time complexity is n*n
    if(num == 0 || num == 1) return 1;
    if(dp[num] != -1) return dp[num];
    
    int ans = 0;
    for(int i = 0; i < num; i++) {
        ans += memo(i, dp) * memo(num-i-1, dp);
    }
    return dp[num] = ans;
}

int tabulation(int num) { // t.c == n*n;
    vector<int>dp(num+1, 0);
    dp[0] = dp[1] = 1;

    for(int i = 2; i <= num; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[num];
}

int main() {
    int num = 5;
    cout << catalan_num(num) << "\n";
    vector<int>dp(num+1, -1);
    cout << memo(num, dp) << '\n';
    cout << tabulation(num);
}