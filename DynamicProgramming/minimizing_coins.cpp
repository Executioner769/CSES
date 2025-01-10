#include <bits/stdc++.h>

using namespace std;

int minCoins(int amount, vector < int > & coins) {
    sort(coins.begin(), coins.end());
    vector < vector < int >> dp(coins.size(), vector < int > (amount + 1, -1));
    for (int t = 0; t <= amount; t++)
        if (t % coins[0] == 0)
            dp[0][t] = t / coins[0];
        else
            dp[0][t] = 1e9;

    for (int ind = 1; ind < coins.size(); ind++) {
        for (int amt = 0; amt <= amount; amt++) {
            int not_take = dp[ind - 1][amt];
            int take = 1e9;
            if (coins[ind] <= amt)
                take = 1 + dp[ind][amt - coins[ind]];
            dp[ind][amt] = min(not_take, take);
        }
    }

    int ans = dp[coins.size() - 1][amount];
    if (ans >= 1e9)
        return -1;
    return ans;
}

int main() {
    int n, amount;
    cin >> n >> amount;
    vector < int > coins(n);
    for (auto & coin: coins) {
        cin >> coin;
    }
    cout << minCoins(amount, coins);
}