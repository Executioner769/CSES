#include <bits/stdc++.h>

using namespace std;

int minCoins(int amount, vector < int > & coins) {
    sort(coins.begin(), coins.end());
    vector < int > prev(amount + 1);
    for (int t = 0; t <= amount; t++)
        if (t % coins[0] == 0)
            prev[t] = t / coins[0];
        else
            prev[t] = 1e9;

    for (int ind = 1; ind < coins.size(); ind++) {
        vector < int > curr(amount + 1);
        for (int amt = 0; amt <= amount; amt++) {
            int not_take = prev[amt];
            int take = 1e9;
            if (coins[ind] <= amt)
                take = 1 + curr[amt - coins[ind]];
            curr[amt] = min(not_take, take);
        }
        prev = curr;
    }

    int ans = prev[amount];
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