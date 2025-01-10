#include <bits/stdc++.h>
using namespace std;

#define ll long long

// https://www.youtube.com/watch?v=DMkXbGm4g6o

int main() {
    int n;
    cin >> n;
    
    vector<ll> nums(n);
    
    // store max diff between first player score - second player score in the interval i and j inclusive.
    vector<vector<ll>> dp(n, vector<ll>(n));
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
        sum += nums[i];
        dp[i][i] = nums[i];
    }

    for(int left = n-1; left >= 0; --left) {
        for(int right = left+1; right < n; ++right) {
            ll lscore = nums[left] - dp[left+1][right];
            ll rscore = nums[right] - dp[left][right-1];
            dp[left][right] = max(lscore, rscore);
        }
    }
    
    // S1 + S2 = S
    // S1 - S2 = dp[0][n-1]
    
    // S1 = (S + dp[0][n-1]) / 2
    
    cout << (sum + dp[0][n-1]) / 2;
    
    return 0;
}
