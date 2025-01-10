#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for(auto& num: nums) {
        cin >> num;
    }
    
    vector<int> dp(n+1, 1);
    
    int lis = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(nums[j] < nums[i]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        lis = max(lis, dp[i]);
    }
    
    cout << lis;
    
    return 0;
}
