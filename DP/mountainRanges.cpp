#include <bits/stdc++.h>
using namespace std;

int tabulation(int num) { // t.c == n*n;
    vector<int>dp(num+1, 0);
    dp[0] = dp[1] = 1;

    for(int i = 2; i <= num; i++) {
        for(int j = 0; j < i; j++) {
            int inside = dp[j];
            int outside = dp[i-j-1];
            dp[i] += inside * outside;
        }
    }
    return dp[num];
}

int main() {
    // in this question we have (num) no. of up stroke and (num) no. of down stroke of mountains to build them.
    int num = 5;
    // for n == 3, we can take c0 * c2 + c1 * c1 + c2 * c0.
    cout << tabulation(num);
}