#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

int ways(int amount, vector<int>& coins) {
    
    int n = coins.size();
    vector<int> dp(amount+1, 0);
    
    dp[0]= 1;
    
    for(int sum = 1; sum < amount+1; ++sum) {
        for(auto& coin: coins) {
            if(sum >= coin) {
                dp[sum] = (dp[sum] + dp[sum - coin]) % M;
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
