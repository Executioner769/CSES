#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int main() {
    int n;
    cin >> n;
	
	vector<string> grid(n);
	for(auto& row: grid) {
	    cin >> row;
	}
	
	vector<vector<int>> dp(n, vector<int>(n, 0));
	
	for(int r = 0; r < n; ++r) {
	    if(grid[r][0] == '.') dp[r][0] = 1;
	    else break;
	}
	
	for(int c = 0; c < n; ++c) {
	    if(grid[0][c] == '.') dp[0][c] = 1;
	    else break;
	}
	
	for(int r = 1; r < n; ++r) {
	    for(int c = 1; c < n; ++c) {
	        if(grid[r][c] == '.') {
	            dp[r][c] = (dp[r-1][c] + dp[r][c-1]) % M;
	        } else {
	            dp[r][c] = 0;
	        }
	    }
	}
    
    cout << dp[n-1][n-1];
}
