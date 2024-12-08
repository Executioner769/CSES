#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 2e5 + 1;

ll bfs(int node, vector<int> tree[]) {
    ll sum = 0;
    queue <pair<int, int >> q;
    q.push({
        node,
        -1
    });

    ll level = 0;
    while (!q.empty()) {
        int len = q.size();
        sum += len * level;
        level += 1;
        while (len) {
            auto[node, parent] = q.front();
            q.pop();

            for (auto child: tree[node]) {
                if (child != parent) {
                    q.push({
                        child,
                        node
                    });
                }
            }
            
            len -= 1;
        }
    }

    return sum;
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

        // O(N * N)
        for (int i = 1; i < n + 1; ++i) {
            cout << bfs(i, tree) << " ";
        }

    }

    return 0;

}