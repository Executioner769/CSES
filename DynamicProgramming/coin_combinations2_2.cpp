#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

int ways(int amount, vector<int>& coins) {
    
    int n = coins.size();
    vector<int> dp(amount+1, 0);
    
    dp[0]= 1;
    
    for(int c = 0; c < n; ++c) {
        for(int s = 1; s < amount+1; ++s) {
            if(s >= coins[c]) {
                dp[s] = (dp[s] + dp[s-coins[c]]) % M;
            }
        }
    }
    
    return dp[amount];
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
