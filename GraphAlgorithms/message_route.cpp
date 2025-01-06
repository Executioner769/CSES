#include<bits/stdc++.h>
using namespace std;


int findShortestPath(int start, int end, vector<int> adj[], int n, vector<int>& parent) {
    
    parent[start] = -1;
    vector<int> dis(n+1,1e8);
    
    queue<int> q;
    dis[start] = 1;
    
    q.push(start);
    
    while(!q.empty()) {
        int comp = q.front(); q.pop();
        
        if(comp == end) break;
        
        for(auto next_comp: adj[comp]) {
            if(dis[next_comp] > dis[comp] + 1) {
                dis[next_comp] = dis[comp] + 1;
                parent[next_comp] = comp;
                q.push(next_comp);
            }
        }
    }
    
    // Immposible
    if(dis[end] == 1e8) {
        return -1;
    }
    
    int distance = dis[end];
    return distance;
}

int main() {

    int n, m;
    cin >> n >> m;
    
    int u, v;
    
    vector<int> adj[n+1];
    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
    int start = 1, end = n;
    vector<int> parent(n+1);
    
    int distance = findShortestPath(start, end, adj, n, parent);
    
    if(distance == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    vector<int> path;
    int node = end;
    
    while(node != -1) {
        path.push_back(node);
        node = parent[node];
    }
    
    reverse(path.begin(), path.end());
    
    cout << distance << "\n";
    for(auto comp: path) {
        cout << comp << " ";
    }

    return 0;
}