#include <bits/stdc++.h>
using namespace std;

int pow_mod(int x, int n, int M) {
	if(n == 0) return 1;
	int p = 1;
	if(n & 1) {
		p = pow_mod(x , (n-1)/2, M);
		p = (1ll * p * p) % M;
		return (1ll * x * p) % M;
	}
	p = pow_mod(x, n/2, M);
	return (1ll * p * p) % M;
}

int main() {
	int n;
	cin >> n;
	cout<< pow_mod(2,n,1e9+7);
	return 0;
}
