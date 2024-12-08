#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);


int getDepth(int node, int parent,vector<int> tree[], vector<int>& depths) {
    int depth = 0;
    for(auto child: tree[node]) {
        if(child != parent) {
            depth = max(depth, 1 + getDepth(child, node, tree, depths));
        }
    }
    return depths[node] = depth;
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

        // n-1 edges in a tree
        for(int i = 1; i < n; ++i) {
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        vector<int> depths(n+1);
        
        // O(N * N) Time Compexity
        for(int node = 1; node <= n; node++) {
            // node, parent
            getDepth(node, 0, tree, depths);
            
            cout<< depths[node] << " ";
        }
    }
    
    return 0;

}