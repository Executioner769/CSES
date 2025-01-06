#include<bits/stdc++.h>
using namespace std;


class DisjointSet {
    private: 
    vector<int> parent, size;
    
    public: 
    DisjointSet(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n + 1, 1);
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    int unionBySize(int u, int v) {
        int u_par = findParent(u);
        int v_par = findParent(v);

        if (u_par == v_par) return 0;

        if (size[u_par] < size[v_par]) {
            swap(u_par, v_par);
        }
        
        // size[u_par] >= size[v_par]
        parent[v_par] = u_par;
        size[u_par] += size[v_par];
        return 1;
    }
};

int main() {

    int n, m;
    cin >> n >> m;

    DisjointSet ds(n);

    int u, v;
    while (m--) {
        cin >> u >> v;
        ds.unionBySize(u, v);
    }

    int reqRoads = 0;
    vector<pair<int,int>> newRoads;
    
    for (int city = 1; city < n; ++city) {
        
        // Try to add road from city to city+1
        if (ds.unionBySize(city, city + 1)) {
            newRoads.push_back({city,city + 1});
            reqRoads += 1;
        }
    }

    cout << reqRoads << "\n";
    for (auto & [u, v]: newRoads) {
        cout << u << " " << v << "\n";
    }

    return 0;
}