#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
	   // Count on Knights that can be placed on I X I chess board;
	   // Ways of placing first knight any where on the board is I^2
	   // Ways of placing second knight any where on the board is I^2 - 1 (One place is occupied by first knight)
	   
	   // Total Number Ways = I^2 * (I^2 - 1) if the knights were different.
	   // Total Number Ways placing similar 2 knights = (I^2 * (I^2 - 1) / 2)
	   ll totalWays = (1ll * i * i * (i * i - 1)) / 2;
	   
	   // There are two ways knights attack in 2 X 3 board
	   // Simillary 2 ways in 3 X 2 board
	   
	   // Now we find how many 2 X 3 sub boards can be placed in I x I board.
	   // 0 -> i - 1 = (I - 1) ways vertically 
	   // 0 -> i - 2 = (I - 2) ways horizontally
	   
	   // Simlilary for 3 X 2 sub boards (I - 1)(I - 2)
	   
	   // Total Attack positions = 2 * (2 * (I - 1) * (I - 2))
	   ll attackWays = (1ll * 4 * max(0,(i-1)) * max(0,(i-2)));
	   
	   cout << totalWays - attackWays << endl;
	}
    return 0;
}
