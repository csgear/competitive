#include <bits/stdc++.h>
using namespace std;

// Knight's move directions
const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int board[8][8];

bool isValid(int x, int y) { return x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == 0; }

int countMoves(int x, int y) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny)) {
            count++;
        }
    }
    return count;
}

// Backtracking with Warnsdorff's heuristic
bool solve(int x, int y, int move) {
    board[x][y] = move;

    // Base case: all squares visited
    if (move == 64) {
        return true;
    }

    vector<pair<int, pair<int, int>>> nextMoves;

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isValid(nx, ny)) {
            int accessibility = countMoves(nx, ny);
            nextMoves.push_back({accessibility, {nx, ny}});
        }
    }

    // Sort by accessibility (Warnsdorff's rule - visit squares with fewer onward moves first)
    sort(nextMoves.begin(), nextMoves.end());

    // Try each move
    for (auto& moveOption : nextMoves) {
        int nx = moveOption.second.first;
        int ny = moveOption.second.second;

        if (solve(nx, ny, move + 1)) {
            return true;
        }
    }

    board[x][y] = 0;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> y >> x;

    x--;
    y--;

    memset(board, 0, sizeof(board));

    if (solve(x, y, 1)) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << board[i][j];
                if (j < 7) cout << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}