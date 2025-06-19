#include <bits/stdc++.h>

using namespace std;

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};  // 8 directions
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int R, C;
vector<string> grid;
string word;

bool inBounds(int x, int y) { return x >= 0 && x < R && y >= 0 && y < C; }

int dfs(int x, int y, int idx, int dir, bool turned) {
    if (grid[x][y] != word[idx]) return 0;
    if (idx == word.size() - 1) {
        cout << idx << " " << dir << endl;
        return 1;
    }

    int count = 0;

    // Continue in same direction
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (inBounds(nx, ny)) count += dfs(nx, ny, idx + 1, dir, turned);

    // Try a turn only if not turned yet
    if (!turned) {
        for (int ndir = 0; ndir < 8; ++ndir) {
            if (ndir != dir && dx[dir] * dx[ndir] + dy[dir] * dy[ndir] == 0) {  // right angle
                int tx = x + dx[ndir];
                int ty = y + dy[ndir];
                if (inBounds(tx, ty)) count += dfs(tx, ty, idx + 1, ndir, true);
            }
        }
    }

    return count;
}

int main() {
    cin >> word;
    cin >> R >> C;
    grid.resize(R);

    cin.ignore();
    for (int i = 0; i < R; ++i) {
        string line;
        getline(cin, line);
        string row;
        for (char ch : line) {
            if (ch != ' ') row += ch;
        }
        grid.push_back(row);
    }

    // for (int i = 0; i < R; ++i) cin >> grid[i];

    int total = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == word[0]) {
                for (int d = 0; d < 8; ++d) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (inBounds(ni, nj)) total += dfs(ni, nj, 1, d, false);
                }
            }
        }
    }

    cout << total << endl;
    return 0;
}
