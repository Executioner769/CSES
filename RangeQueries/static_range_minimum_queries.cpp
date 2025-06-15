#include <bits/stdc++.h>
using namespace std;

class SparseTable {
private:
    int N, LOG;
    vector<vector<int>> mat; // mat[i][j] is min in the range i to (1 << j) - 1
    vector<int> binLog; // binLog[i] is the exponent of largest power of 2 that is less than i
public:
    // O(NLogN)
    SparseTable(vector<int>& nums) {
        N = nums.size();
        LOG = log2(N)+1;
        
        // Build Bin Log Array
        binLog.resize(N);
        binLog[1] = 0;
        for(int i = 2; i < N; ++i) {
            binLog[i] = binLog[i/2] + 1;
        }
        
        // Build SparseTable
        mat.resize(N, vector<int>(LOG));
        for(int i = 0; i < N; ++i) {
            mat[i][0] = nums[i];
        }
        
        for(int j = 1; j < LOG; ++j) {
            for(int i = 0; i + (1 << j) - 1 < N; ++i) {
                mat[i][j] = min(mat[i][j-1], mat[i + (1 << (j-1))][j-1]);
            }
        }
    }
    
    // O(1)
    int query(int l, int r) {
        int len = r - l + 1;
        int pow2 = binLog[len];
        return min(mat[l][pow2], mat[r - (1 << pow2) + 1][pow2]);
    }
};

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> nums(n);
	for(auto& num: nums) {
	    cin >> num;
	}
	SparseTable st(nums);
	int l, r;
	while(q--) {
	    cin >> l >> r;
	    cout << st.query(l-1,r-1) << "\n";
	}
	return 0;
}
