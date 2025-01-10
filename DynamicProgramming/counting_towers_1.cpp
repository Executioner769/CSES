#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

#define ll long long

int main() {
    
    int t;
    cin >> t;
    
    vector<int> heights(t);
    int maxHeight = 1;
    for(auto& height: heights) {
        cin >> height;
        maxHeight = max(maxHeight, height);
    }

    vector<ll> twoBlocks(maxHeight+1), oneBlock(maxHeight+1);
    twoBlocks[1] = 1;
    oneBlock[1] = 1;
    
    for(int h = 2; h <= maxHeight; ++h) {
        oneBlock[h] = (oneBlock[h-1] * 2 + twoBlocks[h-1]) % M;
        twoBlocks[h] = (oneBlock[h-1] + twoBlocks[h-1] * 4) % M;
    }
    
    for(auto& height: heights) {
        cout << (oneBlock[height] + twoBlocks[height]) % M << "\n";
    }
    
    return 0;
}
