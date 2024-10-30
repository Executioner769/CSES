#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  int n, num, maxi = 0;
  cin >> n;
  ll steps = 0;
  while(n--) {
    cin >> num;
    maxi = max(maxi,num);
    steps += (maxi - num);
  }

  cout<<steps<<endl;
  
  return 0;
}