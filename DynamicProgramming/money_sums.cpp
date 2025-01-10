#include <bits/stdc++.h>
using namespace std;

void solve(int maxSum, vector<int>& nums) {

    int n = nums.size();
    
    vector<vector<int>> dp(n+1, vector<int>(maxSum+1, 0));
    dp[0][0] = 1;
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= maxSum; ++j) {
            dp[i][j] = dp[i-1][j];
            if(j >= nums[i-1] && dp[i-1][j-nums[i-1]]) {
                dp[i][j] = 1;
            }
        }
    }
    
    vector<int> sums;
    for(int sum = 1; sum <= maxSum; ++sum) {
        if(dp[n][sum]) {
            sums.push_back(sum);
        }
    }
    
    cout << sums.size() << "\n";
    for(auto& sum : sums) {
        cout << sum << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    int sum = 0;
    
    for(auto& num: nums) {
        cin >> num;
        sum += num;
    }
    
    solve(sum, nums);
    return 0;
}
