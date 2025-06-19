// https://cses.fi/problemset/task/1193

#include <bits/stdc++.h>
using namespace std;

vector<char> path;

// UDLR
const int dr[] = {-1, 1, 0, 0};  // up, down, left, right
const int dc[] = {0, 0, -1, 1};  // up, down, left, right

bool bfs(int sr, int sc, vector<vector<char>> &grid, vector<vector<char>> &dirs,
         vector<vector<bool>> &visited) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (grid[r][c] == 'B') {
            while (1) {
                path.push_back(dirs[r][c]);
                r += (path.back() == 'U') - (path.back() == 'D');
                c += (path.back() == 'L') - (path.back() == 'R');
                if (r == sr && c == sc) break;
            }
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] != '#') {
                q.push({nr, nc});
                visited[nr][nc] = true;
                dirs[nr][nc] = "UDLR"[i];
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<char>> dirs(n, vector<char>(m));

    int sr, sc;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                sr = i;
                sc = j;
            }
        }
    }

    if (bfs(sr, sc, grid, dirs, visited)) {
        cout << "YES" << endl;
        cout << path.size() << endl;
        for (int i = path.size() - 1; i >= 0; i--) cout << path[i];
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}