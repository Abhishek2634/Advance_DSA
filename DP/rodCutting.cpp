#include <bits/stdc++.h>
using namespace std;


int tabulation(vector<int>price, int rodLength, vector<int>length) {
    int n = price.size();
    vector<vector<int>>dp(n+1, vector<int>(rodLength+1,0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= rodLength; j++) {
            // i - items and j - target sum.
            int v = price[i-1];
            int w = length[i-1];

            // include.
            if(w <= j){
                dp[i][j] = max(v+dp[i][j-w], dp[i-1][j]);
            }else { // exclude.
                dp[i][j] = dp[i-1][j];
            }
        }
    }

     for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= rodLength; j++) {
            cout << dp[i][j] << " ";
        }   
        cout << '\n';
    }

    return dp[n][rodLength];
}


int main() {
    vector<int> length{1, 2, 3, 4, 5, 6, 7, 8};
    int rodLength = 8;
    vector<int>price{1, 5, 8, 9, 10, 17, 17, 20};
    cout << tabulation(price, rodLength, length);
}

