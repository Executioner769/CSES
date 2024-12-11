#include <bits/stdc++.h>
using namespace std;

#define ll long long

int timer;

#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
	vector<ll> st;
	int n;
	
	void build_SegmentTree(vector<int>& a,int i, int tl, int tr) {
		if(tl == tr) {
			st[i] = a[tl];
		} else {
			int tm = tl + (tr - tl) / 2;
			build_SegmentTree(a, 2*i, tl, tm);
			build_SegmentTree(a, 2*i+1, tm+1, tr);
			st[i] = st[2*i] + st[2*i+1];
		}
	}
	
	void update(int i, int tl, int tr, int pos, int value) {
		if(tl == tr) {
			st[i] = value;
		} else {
			int tm = tl + (tr - tl) / 2;
			if(pos <= tm) {
				update(i*2, tl, tm, pos, value);
			} else {
				update(i*2+1, tm+1, tr, pos, value);
			}
			st[i] = st[2*i] + st[2*i+1];
		}
	}
	
	ll query(int i, int tl, int tr, int l, int r) {
		if(l > r) {
			return 0;
		}
		
		if(l == tl && r == tr) {
			return st[i];
		}
		
		int tm = tl + (tr - tl) / 2;
		return query(2*i, tl, tm, l, min(tm,r)) + query(2*i+1, tm+1, tr, max(l,tm+1), r);
	}
	
public:
	SegmentTree(vector<int>& a) {
		int n = a.size();
		this->n = n;
		st.assign(4*n,0);
		build_SegmentTree(a,1,0,n-1);
	}
	
	void update(int pos, int value) {
		update(1,0,n-1,pos,value);
	}
	
	ll query(int l, int r) {
		return query(1,0,n-1,l,r);
	}
	
	void print() {
	    for(auto num: st) {
	        cout << num << " ";
	    }
	    cout << "\n";
	}
};

void dfs(int node, int parent, vector<int> tree[], vector<int>& euler_tour, vector<int>& order_values, vector<int>& values, vector<int>& subtree_count) {
    
    euler_tour[node] = timer++;
    order_values[euler_tour[node]] = values[node];
    
    for(auto child: tree[node]) {
        if(child != parent) {
            dfs(child,node,tree,euler_tour,order_values,values,subtree_count);
            subtree_count[node] += subtree_count[child];
        }
    }
}

void print(vector<int>& nums) {
    for(auto num: nums) {
        cout << num << " ";
    }
    cout << "\n";
}
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n,q;
	cin >> n >> q;
 
	vector<int> tree[n+1];
	vector<int> values(n+1);
	
	for(int i = 1; i <= n; ++i) {
	    cin >> values[i];
	}
	
	int u, v;
	for(int i = 1; i <= n-1; i++) {
	    cin >> u >> v;
	    tree[u].push_back(v);
	    tree[v].push_back(u);
	}
	
	vector<int> subtree_count(n+1,1);
	vector<int> euler_tour(n+1);
	vector<int> order_values(n);
	
	timer = 0;
	
    // O(N)
	dfs(1,-1,tree,euler_tour,order_values,values,subtree_count);
	
    // Build SegmentTree
    SegmentTree st(order_values);
    
	int op, s, x;
	ll sum;
	
	// O(Q log N)
	for(;q > 0; --q) {
	    cin >> op;
	    
	    // change value of node s to x
	    if(op == 1) {
	        cin >> s >> x;
	        st.update(euler_tour[s],x);
	        order_values[euler_tour[s]] = x;
	    }
	    
	    // get sum of node values in subtree rooted at s
	    if(op == 2) {
	        cin >> s;
	        sum = st.query(euler_tour[s], euler_tour[s] + subtree_count[s] - 1);
	        cout << sum << "\n";
	    }
	}
	
	return 0;
 
}