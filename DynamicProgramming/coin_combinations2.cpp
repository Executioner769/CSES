#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

// vector<int> pickedCoins;

// void print() {
//     for(auto& coin: pickedCoins) {
//         cout << coin << " ";
//     }
//     cout << "\n";
// }

int ways(int idx, int amount, vector<int>& coins, vector<vector<int>>& memo) {
    if(amount == 0) {
        // print();
        return 1;
    }
    
    if(idx == (int)coins.size()) {
        return 0;
    }
    
    if(memo[idx][amount] != -1) return memo[idx][amount];
    
    int take = 0;
    if(amount >= coins[idx]) {
        // pickedCoins.push_back(coins[idx]);
        take = ways(idx, amount - coins[idx], coins, memo);
        // pickedCoins.pop_back();
    }
    
    int notTake = ways(idx+1, amount, coins, memo);
    
    return memo[idx][amount] = (take + notTake) % M;
    
}

int main() {
	int n, amount;
	cin >> n >> amount;
	
	vector<vector<int>> memo(n+1, vector<int>(amount+1, -1));
	
	vector<int> coins(n);
	for(auto& coin: coins) {
	    cin >> coin;
	}
	
	cout << ways(0, amount, coins, memo);

}
