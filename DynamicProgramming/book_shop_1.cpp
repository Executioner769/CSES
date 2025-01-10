#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int solve(int amount, vector<int>& prices, vector<int>& pages) {
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
    
    for(int b = 1; b <= n; ++b) {
        for(int p = 0; p <= amount; ++p) {
            if(p >= prices[b-1]) {
                dp[b][p] = max(pages[b-1] + dp[b-1][p - prices[b-1]], dp[b-1][p]);
            } else {
                dp[b][p] = dp[b-1][p];
            }
        }
    }
    
    return dp[n][amount];
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
    
    cout << solve(amount, prices, pages);
}
