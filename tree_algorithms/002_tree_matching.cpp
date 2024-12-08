#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

void solve(int node, int parent, vector<int> tree[], vector<vector<int>>& dp) {
    vector<int> prefix, suffix;
    dp[node][0] = dp[node][1] = 0;

    bool isLeafNode = true;
    for(auto child: tree[node]) {
        if(child != parent) {
            isLeafNode = false;
            solve(child,node,tree,dp);
        }
    }
    
    if(isLeafNode) return;
    
    for(auto child: tree[node]) {
        if(child != parent) {
            prefix.push_back(max(dp[child][0], dp[child][1]));
            suffix.push_back(max(dp[child][0], dp[child][1]));
        }
    }
    
    for(int i = 1; i < (int)prefix.size(); ++i) {
        prefix[i] += prefix[i-1];
    }
    
    for(int i = (int)suffix.size() - 2; i >= 0; --i) {
        suffix[i] += suffix[i+1];
    }
    
    // dp[node][0] = Sum of all the max(dp[childi][0],dp[child][1])
    dp[node][0] = suffix[0];
    
    int childIdx = 0;
    
    for(auto child: tree[node]) {
        if(child == parent) continue;
        
        int leftChildren = (childIdx == 0) ? 0 : prefix[childIdx-1];
        int rightChildren = (childIdx == (int)suffix.size()-1) ? 0 : suffix[childIdx+1];
        
        dp[node][1] = max(dp[node][1], 1 + leftChildren + dp[child][0] + rightChildren);
        
        childIdx += 1;
    }
    
}


int main() {
    fast_io;

    int t = 1;
    int n;
    // cin >> t
    
    int u, v;
    
    
    while (t--) {
        cin >> n;
        vector<int> tree[n+1];
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        // n-1 edges in a tree
        for(int i = 1; i < n; ++i) {
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        // node, parent
        solve(1, 0, tree, dp);
        
        cout << max(dp[1][0], dp[1][1]);
    }
    
    return 0;

}