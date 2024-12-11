#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
//https://cses.fi/problemset/task/1138
 
int timer;
vector<int> in_time, out_time;
 
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
 
// Type 2 Euler Tour
void dfs(int node, int parent, vector<int> tree[], vector<int>& euler_tour, vector<int>& values) {
    // Mark the In Time (+val)
    euler_tour[timer] = values[node];
    in_time[node] = timer;
    timer += 1;
    
    for(auto child: tree[node]) {
        if(child != parent) {
            dfs(child,node,tree,euler_tour,values);
        }
    }
    
    // Mark the Out Time (-val)
    euler_tour[timer] = -values[node];
    out_time[node] = timer;
    timer += 1;
}
 
void print(vector<int>& nums) {
    for(size_t i = 0; i < nums.size(); ++i) {
        cout << i << ":" << nums[i] << " ";
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
	
	vector<int> euler_tour(2*n);
	in_time.resize(n+1);
	out_time.resize(n+1);
	
	timer = 0;
	
    // O(N)
	dfs(1,-1,tree,euler_tour,values);
	
    // Build SegmentTree
    SegmentTree st(euler_tour);
    
	int op, s, x;
	ll sum;
	
	// O(Q log N)
	for(;q > 0; --q) {
	    cin >> op;
	    
	    // change value of node s to x
	    if(op == 1) {
	        cin >> s >> x;
	        st.update(in_time[s],x);
	        st.update(out_time[s],-x);
	    }
	    
	    // get sum of values on the path from the root to node s
	    // query from in_time[root] , in_time[s]
	    if(op == 2) {
	        cin >> s;
	        sum = st.query(in_time[1], in_time[s]);
	        cout << sum << "\n";
	    }
	}
	
	return 0;
 
}