#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, num = 0, val;
  cin >> n;
  
  for(int i = 1; i < n; i++) {
    cin >> val;
    num = num ^ i ^ val;
  }
  
  cout << (num ^ n) << endl;
  return 0;
}