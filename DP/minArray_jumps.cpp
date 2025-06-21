#include <bits/stdc++.h>
using namespace std;


int tabulation(vector<int>nums) { // n*sum
    int n = nums.size();
    vector<int>dp(n, -1);
    dp[n-1] = 0;

    for(int i = n-2; i>=0; i--) { 
        int steps = nums[i];
        int ans = INT_MAX;
        for(int j = i+1; j <= i+steps && j < n; j++){
            if(dp[j] != -1) {
                ans = min(ans, dp[j]+1);
            }
        }
        if(ans != INT_MAX) {
            dp[i] = ans;
        }
    }
    return dp[0];
}

int main() {
    vector<int>nums{2, 3, 1, 1, 4};

    // min no. of jumps to reach at the end of the nums.
    cout << tabulation(nums);
}