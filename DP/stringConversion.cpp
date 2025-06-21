#include <bits/stdc++.h>
using namespace std;


int tabulation(string str1, string str2, int n, int m) {
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
     // Base cases: converting empty string

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                int add = dp[i][j-1];
                int del = dp[i-1][j];
                dp[i][j] = max({del, add});
            }
        }
    }
    return dp[n][m];
}

int main() {
    string str1 = "abcdef", str2 = "aceg";
    int n = str1.size(), m = str2.size();
    // convert string 1 to string 2 using min operations. you can insert, delete. print no. of insertions and deletions.
    int lcs =  tabulation(str1, str2, n, m); // calc. longest common subsequence.

    int del = n - lcs;
    int ins = m - lcs;

    cout <<"no. of chars to insert is : "<<  ins <<  "  and no. of chars to del is : "<< del << "\n";
}

