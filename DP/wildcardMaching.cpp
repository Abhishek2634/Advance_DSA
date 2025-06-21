#include <bits/stdc++.h>
using namespace std;

bool tabulation(string txt, string pattern){
    int n = txt.size(); int m = pattern.size();

    vector<vector<bool>>dp(n+1, vector<bool>(m+1, false));
    dp[0][0] = true;

    for(int i = 1; i < n+1; i++) {
        dp[i][0] = false;
    } // imp;

    for(int j = 1; j < m+1; j++){
        if(pattern[j-1] == '*') {
            dp[0][j] = dp[0][j-1];
        }else{
            dp[0][j] = false;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(txt[i-1] == pattern[j-1] || pattern[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }else if(pattern[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }else{
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}


int main(){
    string txt = "baaabab";
    string pattern = "*****ba*****ab";

    // "?"  matches any single character.  and "*" matches  any sequence of characters.

    cout << boolalpha << tabulation(txt, pattern);
}