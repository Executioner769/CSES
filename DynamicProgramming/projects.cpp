#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9;


int main() {
    int n;
    cin >> n;
    
    vector<int> projects[n];
    
    for(int i = 0; i < n; ++i) {
        int l, r, p;
        cin >> l >> r >> p;
        projects[i] = vector<int>{l,r,p};
    }
    sort(projects, projects+n);
    
    ll dp[n+1];
    for(int i = n; i >= 0; --i) {
        if(i == n) {
            dp[i] = 0;
        } else {
            // don't take
            dp[i] = dp[i+1];
            // take
            int end = projects[i][1];
            int it = upper_bound(projects, projects+n, vector<int>{end,INF,INF}) - projects;
            dp[i] = max(dp[i], projects[i][2] + dp[it]);
        }
    }
    cout << dp[0];
    
    return 0;
}
