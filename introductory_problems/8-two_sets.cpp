#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	
	ll totalSum = (1ll * n * (1ll* n + 1)) / 2;
    // Total sum of all natural numbers up to n
    // if it is odd then it is impossible to divide into 2 equal sub sets
	if(totalSum & 1) {
	    cout << "NO\n";
	    return 0;
	}
	
    // totalSum / 2
	ll sum_req = totalSum >> 1;
	
    vector<int> s1, s2;
    vector<int> vis(n+1,0);
    
    // We start elem with max number then decrement interatively
    ll elem = n, s1_sum = 0;
    while(s1_sum < sum_req) {
        ll sum_rem = sum_req - s1_sum;
        if(elem < sum_rem) {
            s1.push_back(elem);
            s1_sum += elem;
            vis[elem] = 1;
            elem -= 1;
        } else {
            s1.push_back(sum_rem);
            s1_sum += sum_rem;
            vis[sum_rem] = 1;
        }
    }
    
    // Now fill set2 with remaining elements
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) s2.push_back(i);
        vis[i] = 1;
    }
    
    cout<<"YES\n";
    if(s1.size() < s2.size()) swap(s1,s2);
    cout<<s1.size()<<"\n";
    for(auto num: s1) cout<<num<<" ";
    cout<<"\n";
    cout<<s2.size()<<"\n";
    for(auto num: s2) cout<<num<<" ";
    cout<<"\n";
	
    return 0;
}
