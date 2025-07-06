// https://cses.fi/problemset/task/1624

#include <bits/stdc++.h>
using namespace std;

vector<string> board(8);
int cnt = 0;

// Check if a queen can be placed at position (row, col)
bool canPlace(int row, int col) {
    // Check if the square is reserved
    if (board[row][col] == '*') return false;

    // Check row
    for (int j = 0; j < 8; j++) {
        if (j != col && board[row][j] == 'Q') return false;
    }

    // Check column
    for (int i = 0; i < 8; i++) {
        if (i != row && board[i][col] == 'Q') return false;
    }

    // Check diagonal (top-left to bottom-right)
    for (int i = 0; i < 8; i++) {
        int j = col - (row - i);
        if (j >= 0 && j < 8 && i != row && board[i][j] == 'Q') return false;
    }

    // Check diagonal (top-right to bottom-left)
    for (int i = 0; i < 8; i++) {
        int j = col + (row - i);
        if (j >= 0 && j < 8 && i != row && board[i][j] == 'Q') return false;
    }

    return true;
}

// Backtracking function to place queens
void solve(int row) {
    if (row == 8) {
        cnt++;
        return;
    }

    for (int col = 0; col < 8; col++) {
        if (canPlace(row, col)) {
            board[row][col] = 'Q';
            solve(row + 1);
            board[row][col] = '.';
        }
    }
}

int main() {
    // Read the chessboard
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }

    solve(0);
    cout << cnt << endl;

    return 0;
}
