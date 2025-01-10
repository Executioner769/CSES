#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string a, b;
    cin >> a >> b;
    
    int n = a.length(), m = b.length();
    
    vector<int> dp(m+1, 0), cur(m+1, 0);
    
    for(int j = 0; j <= m; ++j) {
        dp[j] = j;
    }
    
    for(int i = 1; i <= n; ++i) {
        cur[0] = i;
        for(int j = 1; j <= m; ++j) {
            if(a[i-1] == b[j-1]) {
                cur[j] = dp[j-1];
            } else {
                cur[j] = 1 + min({dp[j], cur[j-1], dp[j-1]});
            }
        }
        dp = cur;
    }
    
    cout << dp[m];
    
    return 0;
}
