#include <bits/stdc++.h>
using namespace std;


int recursion(string str1, string str2, int n, int m) {  // t.c == O(2^(n+m))
    if(n < 0 || m < 0){
        return 0;
    }

    if(str1[n] == str2[m]) {
        return 1 + recursion(str1, str2, n-1, m-1);
    }else return max(recursion(str1, str2, n-1, m), recursion(str1, str2, n, m-1));
}

int memoisation(string str1, string str2, int n, int m, vector<vector<int>> &dp) {
    if(n == 0 || m == 0)return 0;
    
    if(dp[n][m] != -1) return dp[n][m];
    if(str1[n-1] == str2[m-1]) {
        return dp[n][m] = 1 + memoisation(str1, str2, n-1, m-1, dp);
    }else{
        return dp[n][m] = max(memoisation(str1, str2, n, m-1, dp), memoisation(str1, str2, n-1, m, dp));
    }
}

int tabulation(string str1, string str2, int n, int m) {
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    // meaning is str1 of length i and str2 of length j    have some common subsequence.
    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < m+1; j++) {
            char s = str1[i-1]; char x = str2[j-1];
            if(s == x){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{  
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    string str1 = "abcde", str2 = "ace";
    int n = str1.size(), m = str2.size();
    cout << recursion(str1, str2, n-1, m-1);
    cout << "\n";
    vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
    cout << memoisation(str1, str2, n, m, dp);
    cout << '\n';
    cout << tabulation(str1, str2, n, m);
}

