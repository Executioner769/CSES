#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

#define ll long long

int ops(int n, int m, string& a, string& b, vector<vector<int>>& dp) {
    if(n == 0 && m == 0) return 0;
    if(n == 0) return m;
    if(m == 0) return n;
    
    if(dp[n][m] != -1) return dp[n][m];
    
    if(a[n-1] == b[m-1]) {
        return ops(n-1, m-1, a, b, dp);
    }
    
    int addChar = ops(n, m-1, a, b, dp);
    int removeChar = ops(n-1, m, a, b, dp);
    int replaceChar = ops(n-1, m-1, a, b, dp);
    
    return dp[n][m] = 1 + min({addChar, removeChar, replaceChar});
}

int main() {
    
    string a, b;
    cin >> a >> b;
    
    int n = a.length(), m = b.length();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    cout << ops(n, m, a, b, dp);
    
    return 0;
}
