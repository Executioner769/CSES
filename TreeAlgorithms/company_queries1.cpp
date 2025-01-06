#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> par;

// void binary_lifting(int node, int parent, vector<int> tree[]) {
    
//     par[node][0] = parent;
    
//     for(int j = 1; j < 20; ++j) {
//         if(par[node][j-1] != -1) {
//             par[node][j] = par[par[node][j-1]][j-1];
//         } else par[node][j-1] = -1;
//     }
    
//     for(auto child: tree[node]) {
//         if(child != parent) {
//             binary_lifting(child,node,tree);
//         }
//     }
// }

void binary_lifting(int n, vector<int>& boss) {
    
    for(int emp = 1; emp <= n; ++emp) {
        par[emp][0] = boss[emp];
    }
    
    for(int j = 1; j < 20; ++j) {
        for(int emp = 1; emp <= n; ++emp) {
            if(par[emp][j-1] == -1) {
                par[emp][j] = -1;
            } else {
                par[emp][j] = par[par[emp][j-1]][j-1];
            }
        }
    }
}

int getKthBoss(int emp, int k) {
    for(int i = 0; i < 20; ++i) {
        if((k >> i) & 1) {
            emp = par[emp][i];
            if(emp == -1) return -1;
        }
    }
    return emp;
}

// int query(int node, int jumps) {
//     // base case
//     // reached parent of root (i.e -1) or reache the destination node (i.e jumps == 0)
//     if(node == -1 || jumps == 0) {
//         return node;
//     }
    
//     for(int i = 19; i >= 0; --i) {
//         if(jumps >= (1 << i)) {
//             return query(par[node][i],jumps - (1 << i));
//         }
//     }
// }

int main() {
	
	int n,q;
	cin >> n >> q;

// 	vector<int> tree[n+1];
	
    // Store the tree in an adjacency list
// 	int v;
// 	for(int u = 2; u <= n; ++u) {
// 	    cin >> v;
// 	    tree[u].push_back(v);
// 	    tree[v].push_back(u);
// 	}
	
    // Store the immediate boss of an employee
	vector<int> boss(n+1);
	boss[1] = -1;
	int b;
	for(int emp = 2; emp <= n; ++emp) {
	    cin >> b;
	    boss[emp] = b;
	}
	
	par.resize(n+1 ,vector<int>(20));
	
// 	binary_lifting(1,-1,tree);

    binary_lifting(n,boss);
	
	int node, jumps;
	for(;q > 0; --q) {
	    cin >> node >> jumps;
	   // cout << query(node,jumps) << "\n";
	   cout << getKthBoss(node,jumps) << "\n";
	}
	
	return 0;

}
