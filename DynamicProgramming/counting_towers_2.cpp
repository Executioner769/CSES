#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

#define ll long long

int main() {
    
    int t;
    cin >> t;
    
    vector<int> heights(t);
    int maxHeight = 1;
    for(auto& height: heights) {
        cin >> height;
        maxHeight = max(maxHeight, height);
    }

    vector<ll> dp(maxHeight+1);
    
    dp[1] = 2; 
    dp[2] = 8;
    
    for(int h = 3; h <= maxHeight; ++h) {
        dp[h] = ((6*dp[h-1] - 7*dp[h-2]) % M + M) % M;
    }
    
    for(auto& height: heights) {
        cout << dp[height] << "\n";
    }
    
    return 0;
}
