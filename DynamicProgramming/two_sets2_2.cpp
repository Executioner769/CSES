#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int M = 1e9+7;

int ways(int n) {

    int sum = n*(n+1)/2;
    
    if(sum&1) return 0;
    
    sum /= 2;
    
    vector<int> dp(sum+1, 0), cur(sum+1, 0);
    dp[0] = 1;
    
    // Do not include the last number 
    // We are considering the subsets that do not contain the last number
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j <= sum; ++j) {
            cur[j] = dp[j];
            if(j >= i) {
                cur[j] = (cur[j] + dp[j-i]) % M;
            }
        }
        dp = cur;
    }
    return dp[sum];
}

int main() {
    int n;
    cin >> n;
    cout << ways(n);
    
    return 0;
}
