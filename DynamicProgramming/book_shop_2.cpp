#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int solve(int amount, vector<int>& prices, vector<int>& pages) {
    int n = prices.size();
    vector<int> dp(amount+1), prev(amount+1);
    
    for(int b = 1; b <= n; ++b) {
        for(int p = 0; p <= amount; ++p) {
            if(p >= prices[b-1]) {
                dp[p] = max(pages[b-1] + prev[p - prices[b-1]], prev[p]);
            } else {
                dp[p] = prev[p];
            }
        }
        prev = dp;
    }
    
    return dp[amount];
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
