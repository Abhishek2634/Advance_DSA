#include <bits/stdc++.h>
using namespace std;

int tabulation(int n) {
    vector<int>dp(n+1, 0);
    dp[0] = 1; // null node.
    dp[1] = 1;
    // dp[2] = 2;

    for(int i = 2; i <= n; i++) {
        int ans = 0;
        for(int j = 0; j < i; j++){
            dp[i] += dp[j] * dp[i-j-1];   // no. of ways in left part * no. of ways in right part.
        }
    }
    return dp[n];
}

int main() {
    int n = 5;  //  how many BST's you can make with 5 nodes of different number. lets say here 20, 30, 10, 40, 50. fix one head node and try differnt cases.

    // this is catalan's no. concept.

    cout << tabulation(n);

}