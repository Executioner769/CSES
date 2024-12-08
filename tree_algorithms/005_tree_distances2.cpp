#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 2e5 + 1;

// https://www.youtube.com/watch?v=DA7MNlDY4gk

void getCount(int node, int parent, vector<int> tree[], vector<int>& count, vector<ll>& sum) {
    for(auto child: tree[node]) {
        if(child != parent) {
            getCount(child,node,tree,count,sum);
            count[node] += count[child];
            sum[node] += sum[child] + count[child];
        }
    }
    count[node] += 1;
}

void getSum(int node, int parent, int nodes, vector<int> tree[], vector<int>& count, vector<ll>& sum) {
    // Nodes Count = tree.size() - 1
    for(auto child: tree[node]) {
        if(child != parent) {
            sum[child] = sum[node] + (nodes - count[child]) - count[child];
            getSum(child, node, nodes, tree, count, sum);
        }
    }
}

int main() {
    fast_io;

    int t = 1;
    int n;

    int u, v;


    while (t--) {
        cin >> n;
        vector < int > tree[n + 1];

        // n-1 edges in a tree
        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        vector<int> count(n+1);
        vector<ll> sum(n+1);
        
        // get count of nodes at every sub tree
        getCount(1,0,tree,count,sum);
        
        getSum(1,0,n,tree,count,sum);
        
        for(int i = 1; i < n+1; i++) {
            cout << sum[i] << " ";
        }
    }

    return 0;

}