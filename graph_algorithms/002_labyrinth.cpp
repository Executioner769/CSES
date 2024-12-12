#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int main() {

    int n,m;
    scanf("%d %d", &n, &m);
    vector<vector<char>> grid(n , vector<char>(m));
    
    char ch;
    pii start, end;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            scanf(" %c", &ch);
            if(ch == 'A') {
                start = make_pair(i,j);
            } else if(ch == 'B') {
                end = make_pair(i,j);
            }
            grid[i][j] = ch;
        }
    }
    
    // Move UP, LEFT, RIGHT, DOWN
    int drow[] = {-1, 0, 0, 1};
    int dcol[] = {0, -1, 1, 0};
    
    vector<vector<int>> vis(n, vector<int>(m,0));
    
    vector<vector<char>> reach(n, vector<char>(m,'#'));
    vector<vector<int>> distance(n, vector<int>(m,0));
    
    auto [s_row,s_col] = start;
    auto [e_row,e_col] = end;
    
    queue<pii> q;
    q.push(start);
    vis[s_row][s_col] = 1;
    
    while(!q.empty()) {
        auto [row,col] = q.front(); q.pop();
        
        if(e_row == row && e_col == col) {
            break;
        }
        
        for(int dir = 0; dir < 4; ++dir) {
            int nrow = row + drow[dir];
            int ncol = col + dcol[dir];
            
            
            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0) {
                if(!vis[nrow][ncol] && grid[nrow][ncol] != '#') {
                    vis[nrow][ncol] = 1;
                    
                    if(dir == 0) {
                        reach[nrow][ncol] = 'U';
                    } else if(dir == 1) {
                        reach[nrow][ncol] = 'L';
                    } else if(dir == 2) {
                        reach[nrow][ncol] = 'R';
                    } else if(dir == 3){
                        reach[nrow][ncol] = 'D';
                    }
                    
                    distance[nrow][ncol] = 1 + distance[row][col];
                    
                    q.push({nrow,ncol});
                }
            }
        }
    }
    
    
    if(!vis[e_row][e_col]) {
        printf("NO\n");
        return 0;
    }
    
    int dis = distance[e_row][e_col];
    printf("YES\n%d\n",dis);
    
    string path;
    auto [r,c] = end;
    
    while(dis > 0) {
        path += reach[r][c];
        
        // Toogle the direction while traversing back from end to start
        // U ==> row-1, col+0
        // R ==> row+0, col-1
        // D ==> row-1, col+0
        // L ==> row+0, col+1
        if(reach[r][c] == 'U') r += 1;
        else if(reach[r][c] == 'R') c -= 1;
        else if(reach[r][c] == 'D') r -= 1;
        else if(reach[r][c] == 'L') c += 1;
        
        dis -= 1;
    }
    
    reverse(path.begin(),path.end());
    cout << path;
    
    // printf("\n");
    return 0;

}
