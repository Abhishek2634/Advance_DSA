#include <bits/stdc++.h>
using namespace std;

int lcs(vector<int>& arr, vector<int>& copy) {
    int n = arr.size(); int m = copy.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int one = arr[i];
            int two = copy[j];

            if(one == two) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int lis(vector<int>& arr){  // longest inc. subsequence
    set<int>st(arr.begin(), arr.end());
    vector<int>copy(st.begin(), st.end());
    return lcs(arr,copy);    // longest common subsequence
}

int main() {
    vector<int>arr{50, 3, 10, 7, 40, 80};
    cout << lis(arr);
}

