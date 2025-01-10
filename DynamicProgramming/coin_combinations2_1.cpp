#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

int ways(int amount, vector<int>& coins) {
    
    int n = coins.size();
    vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
    
    dp[0][0] = 1;
    
    for(int c = 1; c <= n; ++c) {
        dp[c][0] = 1;
        
        for(int s = 1; s <= amount; ++s) {
            dp[c][s] = dp[c-1][s];
            if(s >= coins[c-1]) {
                dp[c][s] = (dp[c][s] + dp[c][s-coins[c-1]]) % M;
            }
        }
    }
    
    return dp[n][amount];
}

int main() {
	int n, amount;
	cin >> n >> amount;

	vector<int> coins(n);
	for(auto& coin: coins) {
	    cin >> coin;
	}
	
	cout << ways(amount, coins);

}
