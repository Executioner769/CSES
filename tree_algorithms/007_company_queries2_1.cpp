#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> par;
vector<int> levels;

void binary_lifting(int node, int parent, vector<int> tree[]) {
    
    par[node][0] = parent;
    
    for(int j = 1; j < 20; ++j) {
        if(par[node][j-1] != -1) {
            par[node][j] = par[par[node][j-1]][j-1];
        } else par[node][j-1] = -1;
    }
    
    for(auto child: tree[node]) {
        if(child != parent) {
            binary_lifting(child,node,tree);
        }
    }
}

void dfs(int node, int parent, vector<int> tree[], int level) {
    levels[node] = level;
    for(auto child: tree[node]) {
        if(child != parent) {
            dfs(child,node,tree,level+1);
        }
    }
}

int lift_node(int node, int levels) {
    for(int l = 0; l < 20; ++l) {
        if((levels >> l) & 1) {
            node = par[node][l];
            if(node == -1) return -1;
        }
    }
    return node;
}

int lowest_common_boss(int u, int v) {
    if(levels[u] < levels[v]) {
        swap(u,v);
    }
    
    u = lift_node(u, levels[u] - levels[v]);
    
    int low = 0, high = levels[u];
    while(low < high) {
        int mid = (low + high)/2;
        int boss1 = lift_node(u,mid);
        int boss2 = lift_node(v,mid);
        if(boss1 == boss2) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return lift_node(u,low);
}

int main() {
	
	int n,q;
	cin >> n >> q;

	vector<int> tree[n+1];
	
    // Store the tree in an adjacency list
	int v;
	for(int u = 2; u <= n; ++u) {
	    cin >> v;
	    tree[u].push_back(v);
	    tree[v].push_back(u);
	}

    levels.resize(n+1);
    
    dfs(1,-1,tree,0);
	
	par.resize(n+1 ,vector<int>(20));
	
	binary_lifting(1,-1,tree);
	
	int emp1, emp2;
	for(;q > 0; --q) {
	   cin >> emp1 >> emp2;
	   cout << lowest_common_boss(emp1,emp2) << "\n";
	}
	
	return 0;

}
