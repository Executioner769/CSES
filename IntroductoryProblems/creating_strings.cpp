#include <bits/stdc++.h>
using namespace std;

void generate(int i, string s, vector<string>& pms) {
    if(i == s.length()-1) {
        pms.push_back(s);
        return;
    }
    for(int k = i; k < s.length(); ++k) {
        if(k != i && s[i] == s[k]) continue;
        swap(s[i],s[k]);
        generate(i+1,s,pms);
    }
}

int main() {
	string s;
	cin>>s;
	
	sort(begin(s),end(s));
	vector<string> pms;
	generate(0,s,pms);
	cout<<pms.size()<<"\n";
	for(auto pm: pms) {
	    cout<<pm<<"\n";
	}
	return 0;
}
