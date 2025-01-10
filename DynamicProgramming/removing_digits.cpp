#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

int minSteps(int n) {
    if(n == 0) return 0;
    
    vector<int> steps(n+1, 1e9);
    steps[n] = 0;
    
    queue<int> q;
    
    q.push(n);
    
    while(!q.empty()) {
        int m = q.front(); q.pop();
        
        if(m == 0) break;
        
        int num = m;
        
        // Get Digits
        while(num > 0) {
            int digit = num % 10;
            num /= 10;
            
            if(steps[m - digit] > steps[m] + 1) {
                steps[m - digit] = steps[m] + 1;
                q.push(m - digit);
            }
        }
    }
    
    return steps[0];
}

int main() {
	int n;
	cin >> n;
	
	cout << minSteps(n);

}
