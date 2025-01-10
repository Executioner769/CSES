#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for(auto& num: nums) {
        cin >> num;
    }
    
    vector<int> tails(n+1, 1);
    
    int lis = 0;
    
    for(auto& num: nums) {
        int l = 0, r = lis;
        // Calculate the Lower Bound
        while(l < r) {
            int m = l + (r - l) / 2;
            if(tails[m] < num) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        tails[l] = num;
        if(l == lis) lis++;
    }
    
    cout << lis;
    
    return 0;
}
