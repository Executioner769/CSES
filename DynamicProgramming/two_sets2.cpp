#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int M = 1e9+7;

int ways(int n, int sum, vector<int>& nums, vector<vector<int>>& dp) {
    if(sum == 0) return 1;
    
    if(n == 0) return 0;
    
    if(dp[n][sum] != -1) return dp[n][sum];
    
    if(sum >= nums[n-1]) {
        return dp[n][sum] = (ways(n-1, sum - nums[n-1], nums, dp) + ways(n-1, sum, nums, dp)) % M;
    }
    
    return dp[n][sum] = ways(n-1, sum, nums, dp);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 1);

    int sum = (n * (n + 1)) >> 1;
    
    if(sum % 2 == 0) {
        vector<vector<int>> dp(n+1, vector<int>(sum+1,-1));
        cout << ways(n-1,sum/2,nums,dp);
    } else {
        cout << 0;
    }
    
    return 0;
}
