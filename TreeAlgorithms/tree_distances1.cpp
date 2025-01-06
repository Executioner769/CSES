#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 2e5+1;
int depths[N];
int dis[N];

void getDepths(int node, int parent, vector<int> tree[]) {
    int depth = 0;
    for(auto child: tree[node]) {
        if(child != parent) {
            getDepths(child, node, tree);
            depth = max(depth, 1 + depths[child]);
        }
    }
    depths[node] = depth;
}

void solve(int node, int parent, int parent_dis, vector<int> tree[]) {
    vector<int> prefixMax, suffixMax;
    for(auto child: tree[node]) {
        if(child != parent) {
            prefixMax.push_back(depths[child]);
            suffixMax.push_back(depths[child]);
        }
    }
    
    for(int i = 1; i < (int)prefixMax.size(); ++i) {
        prefixMax[i] = max(prefixMax[i], prefixMax[i-1]);
    }
    
    for(int i = (int)suffixMax.size()-2; i >= 0; --i) {
        suffixMax[i] = max(suffixMax[i], suffixMax[i+1]);
    }
    
    int childIdx = 0;
    for(auto child: tree[node]) {
        if(child != parent) {
            int letfChildren = (childIdx == 0) ? INT_MIN : prefixMax[childIdx-1];
            int rightChildren = (childIdx == (int)suffixMax.size()-1) ? INT_MIN : suffixMax[childIdx+1];
            
            int partial_dis = 1 + max(parent_dis, max(letfChildren, rightChildren));
            
            solve(child, node, partial_dis, tree);
            childIdx += 1;
        }
    }
    
    dis[node] = 1 + max(parent_dis, (prefixMax.empty() ? -1 : prefixMax.back() ));
}

int main() {
    fast_io;

    int t = 1;
    int n;
    
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
        
        // node = 1
        getDepths(1, 0, tree);
        
        solve(1, 0, -1, tree);
        
        for(int i = 1; i <= n; ++i) {
            cout << dis[i] << " ";
        }
        
    }
    
    return 0;

}
