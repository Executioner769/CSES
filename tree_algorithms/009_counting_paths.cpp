#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> par;

// levels/depths from root node
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

// Time Complexity: O(logN)
int lowest_common_ancestor(int u, int v) {
    if(levels[u] < levels[v]) {
        swap(u,v);
    }
    
    u = lift_node(u, levels[u] - levels[v]);
    
    if(u == v) {
        return u;
    }
    
    for(int j = 19; j >= 0; --j) {
        if(par[u][j] != par[v][j]) {
            u = par[u][j];
            v = par[v][j];
        }
    }
    
    return lift_node(u,1);
}

void dfs2(int node, int parent, vector<int> tree[], vector<int>& diff_array) {
    for(auto child: tree[node]) {
        if(child != parent) {
            dfs2(child,node,tree,diff_array);
            diff_array[node] += diff_array[child];
        }
    }
}
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n,q;
	cin >> n >> q;
 
	vector<int> tree[n+1];
	int u, v;
	for(int i = 1; i <= n-1; i++) {
	    cin >> u >> v;
	    tree[u].push_back(v);
	    tree[v].push_back(u);
	}
 
    levels.resize(n+1);
    
    // rooting the tree at node 1
    dfs(1,-1,tree,0);
	
	par.resize(n+1 ,vector<int>(20));
	
	binary_lifting(1,-1,tree);
	
	int lca, par_lca;
	
	vector<int> diff_array(n+1);
	
	for(;q > 0; --q) {
	    cin >> u >> v;
	    lca = lowest_common_ancestor(u,v);
	    
	    diff_array[u] += 1;
	    diff_array[v] += 1;
	    diff_array[lca] -= 1;
	    par_lca = par[lca][0];
	    if(par_lca != -1) {
	        diff_array[par_lca] -= 1;
	    }
	}
	
	dfs2(1,-1,tree,diff_array);
	
	for(int node = 1; node <= n; ++node) {
	    cout << diff_array[node] << " ";
	}
	
	return 0;
 
}