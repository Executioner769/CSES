#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

int ways(int n) {
    vector<int> dp(n+1);
    dp[0] = 1;
    
    for(int value = 1; value <= n; ++value) {
        for(int dice = 1; dice <= 6; ++dice) {
            if(value - dice >= 0) {
                dp[value] = (dp[value] + dp[value - dice]) % M;
            }
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    cout << ways(n);
}
