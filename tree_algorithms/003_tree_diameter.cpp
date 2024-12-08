#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

int solve(int node, int parent, vector<int> tree[], int& diameter) {
    vector<int> childDiameters;
    bool isLeaf = true;
    
    for(auto child: tree[node]) {
        int childDiameter;
        if(child != parent) {
            isLeaf = false;
            childDiameter = solve(child,node,tree,diameter);
            childDiameters.push_back(childDiameter);
        }
    }
    
    // Return depth including itself
    if(isLeaf) return 1;
    
    sort(childDiameters.begin(), childDiameters.end());
    int size = childDiameters.size();
    
    // first max diameter among children
    int max1 = size >= 1 ? childDiameters[size-1] : 0;
    
    // second max diameter among children
    int max2 = size >= 2 ? childDiameters[size-2] : 0;
    
    // if the diameter is passing through the node
    diameter = max(diameter, max1 + max2);
    
    // Return max depth to the parent
    return max1 + 1;
    
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