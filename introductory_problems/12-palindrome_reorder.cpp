#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin>>s;
	int n = s.length();
    array<int,26> cnt{0};
    for(auto ch: s) 
        cnt[ch-'A'] += 1;
    
    int odds = 0;
    for(int i = 0; i < 26; ++i) {
        if(cnt[i] & 1) {
            odds++;
            if(odds > 1) {
                cout<<"NO SOLUTION\n";
                return 0;
            }
        }
    }
    
    // freq, character
    priority_queue<pair<int,char>> pq;
    for(int i = 0; i < 26; i++) {
        if(cnt[i] > 0) pq.push({cnt[i],i+'A'});
    }
    
    int l = 0, r = n-1;
    while(!pq.empty()) {
        auto pr = pq.top();
        pq.pop();
        
        s[l++] = pr.second;
        s[r--] = pr.second;
        
        pr.first -= 2;
        if(pr.first > 0) pq.push(pr);
    }
    
    cout<<s<<"\n";
    return 0;
}
