#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n;
	cin >> n;
	
	ll count = 0;
	for(ll div = 5; n / div >= 1; div *= 5) {
	    count += n / div;
	}
    cout << count;
    
    return 0;
}
