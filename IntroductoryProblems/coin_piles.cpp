#include <bits/stdc++.h>
using namespace std;

// 2*X + 1*Y = A
// 1*X + 2*Y = B

// Simplifying the above linear equations. We get
// Y = (2*A - B) / 3
// X = (2*B - A) / 3

int main() {
    int t;
    cin >> t;

    map<int, map<int, bool>> dp;
    long long a, b;
    while (t--) {
        cin >> a >> b;
        if ((2 * a - b) < 0 || (2 * b - a) < 0 || ((2 * a - b) % 3 != 0) ||
            ((2 * a - b) % 3 != 0)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
