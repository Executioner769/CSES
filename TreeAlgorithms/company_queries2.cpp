#include <bits/stdc++.h>
using namespace std;


typedef class MinSparseTable {
 private:
    int N, P;
    vector<int> log2_table;
    vector<vector<int>> sparse_table, sparse_index_table;
 public:
    MinSparseTable(vector<int> nums) {
        N = nums.size();
        P = (int)floor(log2(N));
        sparse_table.resize(P+1, vector<int>(N));
        sparse_index_table.resize(P+1, vector<int>(N));
        
        for(int i = 0; i < N; ++i) {
            sparse_table[0][i] = nums[i];
            sparse_index_table[0][i] = i;
        }
        
        log2_table.resize(N+1);
        for(int i = 2; i <= N; ++i) {
            log2_table[i] = log2_table[i/2] + 1;
        }
        
        for(int p = 1; p <= P; ++p) {
            for(int i = 0; i + (1 << p) <= N; ++i) {
                int left_interval = sparse_table[p-1][i];
                int right_interval = sparse_table[p-1][i + (1 << (p-1))];
                
                sparse_table[p][i] = min(left_interval,right_interval);
                
                if(left_interval <= right_interval) {
                    sparse_index_table[p][i] = sparse_index_table[p-1][i];
                } else {
                    sparse_index_table[p][i] = sparse_index_table[p-1][i + (1 << (p-1))];
                }
            }
        }
    }
    
    
    int queryMin(int left, int right) {
        int len = right - left + 1;
        int p = log2_table[len];
        int k = (1 << p);
        return min(sparse_table[p][left], sparse_table[p][right - k + 1]);
    }
    
    int queryMinIndex(int left, int right) {
        int len = right - left + 1;
        int p = log2_table[len];
        int k = (1 << p);
        int left_interval = sparse_table[p][left];
        int right_interval = sparse_table[p][right - k + 1];
        
        if(left_interval <= right_interval) {
            return sparse_index_table[p][left];
        }
        
        return sparse_index_table[p][right-k+1];
    }
}MST;

int tour_index;
vector<int> depths, euler_tour;

// node --> euler_tour_idx
vector<int> inverse_map;

void visit(int node, int depth) {
    euler_tour[tour_index] = node;
    depths[tour_index] = depth;
    inverse_map[node] = tour_index;
    tour_index += 1;
}

void dfs(int node, int parent, int depth, vector<int> tree[]) {
    visit(node,depth);
    for(int child: tree[node]) {
        if(child != parent) {
            dfs(child,node,depth+1,tree);
            visit(node,depth);
        }
    }
}

int lowest_common_boss(int emp1, int emp2, MST& mst) {
    int left_emp_idx = min(inverse_map[emp1], inverse_map[emp2]);
    int right_emp_idx = max(inverse_map[emp1], inverse_map[emp2]);
    
    int euler_idx = mst.queryMinIndex(left_emp_idx, right_emp_idx);
    
    return euler_tour[euler_idx];
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
	
	tour_index = 0;
	
	depths.resize(2*n+1);
	euler_tour.resize(2*n+1);
	
	inverse_map.resize(n+1);
	
	dfs(1,-1,0,tree);
	
	MST mst(depths);
	
	int emp1, emp2;
	for(;q > 0; --q) {
	   cin >> emp1 >> emp2;
	   cout << lowest_common_boss(emp1,emp2,mst) << "\n";
	}
	
	return 0;

}
