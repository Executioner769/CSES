#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

int minSteps(int n) {
    vector<int> dp(n+1, 1e9);
    dp[0] = 0;
    for(int num = 1; num <= n; ++num) {
        int m = num;
        while(m > 0) {
            int d = m % 10;
            dp[num] = min (dp[num], 1 + dp[num - d]);
            m /= 10;
        }
    }
    return dp[n];
}

int main() {
	int n;
	cin >> n;
	cout << minSteps(n);
    return 0;
}
