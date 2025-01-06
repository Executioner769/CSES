#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char left, char middle, char right) {
    if(n == 0) return;
    towerOfHanoi(n-1,left,right,middle);
    cout<<left<<" "<<right<<"\n";
    towerOfHanoi(n-1,middle,left,right);
}

int main() {
	int n;
	cin >> n;
	cout<<(1<<n)-1<<"\n";
	towerOfHanoi(n,'1','2','3');
}
