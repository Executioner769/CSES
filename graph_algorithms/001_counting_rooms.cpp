#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<char>>& building) {
    int n = building.size();
    int m = building[0].size();
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << building[i][j] << " ";
        }
        cout << "\n";
    }
}

void dfs(int row, int col, vector<vector<char>>& building, vector<vector<int>>& visitied) {
    visitied[row][col] = 1;
    
    int rows = building.size();
    int cols = building[0].size();
    
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    
    for(int dir = 0; dir < 4; ++dir) {
        int new_row = row + drow[dir];
        int new_col = col + dcol[dir];
        
        // In Bounds
        if(new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols) {
            // Vist a new floor
            if(!visitied[new_row][new_col] && building[new_row][new_col] == '.') {
                dfs(new_row, new_col, building, visitied);
            }
        }
    }
}

int getRooms(vector<vector<char>>& building) {
    int rooms = 0;
    
    int rows = building.size();
    int cols = building[0].size();
    
    vector<vector<int>> visitied(rows, vector<int>(cols, 0));
    
    for(int r = 0; r < rows; ++r) {
        for(int c = 0; c < cols; ++c) {
            if(!visitied[r][c] && building[r][c] == '.') {
                dfs(r,c,building,visitied);
                rooms += 1;
            }
        }
    }
    
    return rooms;
}

int main() {

    int n,m;
    scanf("%d %d", &n, &m);
    vector<vector<char>> building(n , vector<char>(m));
    
    char ch;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            // This techniques used to escape white-space characters
            // https://stackoverflow.com/questions/20306659/the-program-doesnt-stop-on-scanfc-ch-line-why
            scanf(" %c", &ch);
            building[i][j] = ch;
        }
    }
    
    cout << getRooms(building);
    
    return 0;

}
