#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    ll r,c;
    ll base = 1;
    while (t--) {
        cin >> r >> c;
        if(r <= c) {
            if(c & 1) {
                // c is odd
                base = c * c;
                base -= (r - 1);
            } else {
                base = (c-1) * (c-1);
                base += r;
            }
            
        } else {
            if(r & 1) {
                // r is odd
                base = (r-1) * (r-1);
                base += c;
            } else {
                base = r * r;
                base -= (c - 1);
            }
        }
        
        cout << base << endl;
    }

    return 0;
}