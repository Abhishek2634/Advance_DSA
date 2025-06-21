#include <bits/stdc++.h>
using namespace std;


int tabulation(string str1, string str2, int n, int m) {
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
     // Base cases: converting empty string
    for(int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for(int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                int add = dp[i][j-1] + 1;
                int del = dp[i-1][j] + 1;
                int replace = dp[i-1][j-1] + 1;
                dp[i][j] = min({del, add, replace});
            }
        }
    }
    return dp[n][m];
}

int main() {
    string str1 = "intention", str2 = "execution";
    int n = str1.size(), m = str2.size();
    // convert string 1 to string 2 using min operations. you can insert, delete, and replace characters.
    cout << tabulation(str1, str2, n, m);
}

