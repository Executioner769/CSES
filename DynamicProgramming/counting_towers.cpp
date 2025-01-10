#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

#define ll long long

/*

https://www.youtube.com/watch?v=MxhA0bY31wM

all possible configurations to build a tower of height 2 are 8

*/

int main() {
    
    int t, n;
    cin >> t;
    
    vector<int> heights(t);
    int maxHeight = 1;
    for(auto& height: heights) {
        cin >> height;
        maxHeight = max(maxHeight, height);
    }
    
    vector<vector<ll>> dp(maxHeight+1, vector<ll>(9, 0));
    
    for(int type = 1; type <= 8; ++ type) {
        dp[1][type] = 1;
    }
    
    for(int h = 2; h <= maxHeight; ++h) {
        for(int type = 1; type <= 8; ++ type) {
            // Bottom part is set/connected
            if(type == 1 || type == 3 || type == 4 || type == 5 || type == 6) {
                // Top part of pevious is set/connected
                dp[h][type] = (dp[h-1][1] + dp[h-1][2] + dp[h-1][4] + dp[h-1][5] + dp[h-1][6]) % M;
            } else {
                // Bottom part is not set/connected
                // Top part is not set/connected
                dp[h][type] = (dp[h-1][3] + dp[h-1][7] + dp[h-1][8]) % M;
            }
        }
    }
    
    for(auto& height: heights) {
        cout << (dp[height][3] + dp[height][7]) % M << "\n";
    }
    
    return 0;
}
