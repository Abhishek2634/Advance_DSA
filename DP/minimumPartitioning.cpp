#include <bits/stdc++.h>
using namespace std;


int tabulation(vector<int>nums) { // n*sum
    int n = nums.size();    
    int w = accumulate(nums.begin(), nums.end(), 0);
    int sum = w/2;
    vector<vector<int>>dp(n+1, vector<int>(sum+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(nums[i-1] <= j) { // valid
                dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]], dp[i-1][j]);
            }else{// invalid as req. sum j is smaller than the element in nums.
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int sum1 =  dp[n][sum];
    int sum2 =  w-sum1;
    return abs(sum1-sum2);
}

int main() {
    vector<int>nums{1, 6, 11, 5}; // variation of 0-1 knapsack.
    cout << tabulation(nums);
}