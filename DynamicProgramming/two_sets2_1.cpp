#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int M = 1e9+7;

int ways(int n) {

    int sum = n*(n+1)/2;
    
    if(sum&1) return 0;
    
    sum /= 2;
    
    vector<vector<int>> dp(n, vector<int>(sum+1, 0));
    dp[0][0] = 1;
    
    // Do not include the last number 
    // We are considering the subsets that do not contain the last number
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j <= sum; ++j) {
            dp[i][j] = dp[i-1][j];
            if(j >= i) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % M;
            }
        }
    }
    return dp[n-1][sum];
}

int main() {
    int n;
    cin >> n;
    cout << ways(n);
    
    return 0;
}
