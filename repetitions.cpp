#include <bits/stdc++.h>
using namespace std;

int main() {
  string dna;
  getline(cin,dna);

  int n = dna.length();
  int l = 0, r = l;
  int maxLen = 0;

  while(r < n) {
    l = r;
    while(r < n && dna[r] == dna[l]) {
      r++;
    }
    maxLen = max(maxLen, r - l);
  }

  maxLen = max(maxLen, r - l);

  cout << maxLen << endl;
  
  return 0;
}