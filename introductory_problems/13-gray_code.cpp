#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> gc;
	gc.push_back("");
	for(int i = 0; i < n; ++i) {
	    int size = gc.size();
	    // Inserting the strings in reverse order at the back
	    for(int j = size - 1; j >= 0; --j) {
	        gc.push_back(gc[j]);
	    }
	    // Now my gc size is increased by size
	    // First half append '0' and second half append '1'
	    int l = 0, r = 2*size - 1;
	    while(l < r) {
	        gc[l++] += "0";
	        gc[r--] += "1";
	    }
	}
	
	for(auto str: gc) {
	    cout<<str<<"\n";
	}
	return 0;
}
