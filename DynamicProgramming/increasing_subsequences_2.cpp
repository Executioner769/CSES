#include <bits/stdc++.h>
using namespace std;

// Crazy Solution

int main() {
    int n;
    cin >> n;
    
    vector<int> dp;
    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        auto it = lower_bound(dp.begin(), dp.end(), num);
        if(it == dp.end()) {
            dp.push_back(num);
        } else {
            *it = num;
        }
    }
    cout << dp.size();
    
    return 0;
}
