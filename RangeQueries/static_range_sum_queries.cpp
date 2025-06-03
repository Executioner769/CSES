#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector<long long> prefix(n+1);
	for(int i = 1; i <= n; ++i) {
	    cin >> prefix[i];
	    prefix[i] += prefix[i-1];
	}
	
	int l, r;
	while(q--) {
	    cin >> l >> r;
	    cout << (prefix[r] - prefix[l-1]) << "\n";
	}
	return 0;
}
