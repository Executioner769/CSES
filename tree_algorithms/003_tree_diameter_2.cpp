#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

int solve(int node, int parent, vector<int> tree[], int& diameter) {
    
    int maxChildHeight = 0;
    for(auto child: tree[node]) {
        if(child != parent) {
            int childDiameter = solve(child,node,tree,diameter);
            diameter = max(diameter, maxChildHeight + childDiameter + 1);
            maxChildHeight = max(maxChildHeight, childDiameter + 1);
        }
    }
    return maxChildHeight;
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
        
        int diameter = 0;
        
        // node, parent
        solve(1, 0, tree, diameter);
        
        cout << diameter;
    }
    
    return 0;

}