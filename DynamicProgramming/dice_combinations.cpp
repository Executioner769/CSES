#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

int ways(int n, vector<int>& dp) {
    if(n == 0) return 1;
    
    if(dp[n] != -1) return dp[n];
    
    int count = 0;
    for(int dice = 1; dice <= 6; ++dice) {
        if(n - dice >= 0) {
            count = (count + ways(n-dice, dp)) % M;
        }
    }
    return dp[n] = count;
}

int main() {
	
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    cout << ways(n, dp);
}
