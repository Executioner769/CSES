#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int solve(int idx, int amount, vector<int>& prices, vector<int>& pages, vector<vector<int>>& dp) {
    if(idx == prices.size()) {
        return 0;
    }
    
    if(dp[idx][amount] != -1) return dp[idx][amount];
    
    if(prices[idx] <= amount) {
        return dp[idx][amount] = max(pages[idx] + solve(idx+1, amount - prices[idx], prices, pages, dp), solve(idx+1, amount, prices, pages, dp));
    }
    
    return dp[idx][amount] = solve(idx+1, amount, prices, pages, dp);
}

int main() {
    int n, amount;
    cin >> n >> amount;
    
    vector<int> prices(n);
    for(auto& price: prices) {
        cin >> price;
    }
    
    vector<int> pages(n);
    for(auto& pgs: pages) {
        cin >> pgs;
    }
    
    vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    
    cout << solve(0, amount, prices, pages, dp);
}
