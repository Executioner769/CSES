#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dfs(int emp, vector<int> adj[], vector<ll>& count) {
    ll cnt = 1;
    for(auto subEmp: adj[emp]) {
        cnt += dfs(subEmp,adj,count);
    }
    return count[emp] = cnt;
}

int main() {
    int n = 0;
	cin >> n;
	
	vector<int> adj[n+1];
    int mngr = 1;
    
    vector<ll> count(n+1);
    
    // Add directed edge from manager to subordinate
	for(int emp = 2; emp <= n; ++emp) {
	    cin >> mngr;
	    adj[mngr].push_back(emp);
	}
	
	dfs(1,adj,count);
	
	for(int emp = 1; emp <= n; ++emp) {
	    cout << count[emp]-1 << " ";   
	}

}
