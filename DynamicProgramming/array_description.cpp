#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

#define ll long long

int solve(int m, vector<int>& nums) {
    
    int n = nums.size();
    vector<vector<ll>> dp(n+1, vector<ll>(m+2, 0));
    
    if(nums[0] == 0) {
        for(int i = 1; i <= m; ++i) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][nums[0]] = 1;
    }
    
    for(int i = 1; i < n; ++i) {
        if(nums[i] == 0) {
            for(int j = 1; j <= m; ++j) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % M;
            }
        } else {
            dp[i][nums[i]] = (dp[i-1][nums[i]-1] + dp[i-1][nums[i]] + dp[i-1][nums[i]+1]) % M;
        }
    }
    
    int total = 0;
    for(int j = 1; j <= m; ++j) {
        total = (total + (int)dp[n-1][j]) % M;
    }
    
    return total;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> nums(n);
    for(int& num: nums) {
        cin >> num;
    }
    
    cout << solve(m, nums);
}
