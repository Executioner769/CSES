#include <bits/stdc++.h>
using namespace std;


bool canPlaceQueen(int row, int col, vector<string>& board) {
    // As we are placing columns wise
    // We need to check int only three directions
    // Noth-West, West and South-West

    int rows = board.size();
    int cols = board[0].length();

    // North-West
    int drow = row, dcol = col;
    while(drow >= 0 and dcol >= 0) {
        if(board[drow][dcol] == 'Q') return false;
        drow--;
        dcol--;
    }

    // West
    drow = row, dcol = col;
    while(drow >= 0 and dcol >= 0) {
        if(board[drow][dcol] == 'Q') return false;
        dcol--;
    }

    // South-West
    drow = row, dcol = col;
    while(drow < rows and dcol >= 0) {
        if(board[drow][dcol] == 'Q') return false;
        drow++;
        dcol--;
    }

    return true;
}

int placeQueen(int col, vector<string>& board) {

    int rows = board.size();
    int cols = board[0].length();

    if(col == cols) {
        return 1;
    }

    int ways = 0;
    for(int row = 0; row < rows; ++row) {
        if(board[row][col] == '.' && canPlaceQueen(row, col, board)) {
            board[row][col] = 'Q';
            ways += placeQueen(col+1, board);
            board[row][col] = '.';
        }
    }

    return ways;
}

int main(int argc, char const *argv[]) {

    ios::sync_with_stdio(0);
    cin.tie(0);


    int rows = 8, cols = 8;

    vector<string> board;

    string row;
    for(int r = 0; r < rows; ++r) {
        cin >> row;
        board.push_back(row);
    }

    int ways{};
    ways = placeQueen(0, board);

    cout << ways;

    return 0;
}
