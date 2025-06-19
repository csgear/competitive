// https://cses.fi/problemset/task/1194
// Multi-source BFS

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

char grid[MAXN][MAXN];
int pre[MAXN][MAXN];

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
char dirc[4] = {'R', 'D', 'L', 'U'};

int main() {
  int n, m;
  cin >> n >> m;

  int sr, sc, er, ec;

  queue<pair<int, int>> q;
  bool escaped = false;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'A') {
        sr = i;
        sc = j;
      }
      if (grid[i][j] == 'M') {
        q.push({i, j});
      }
    }
  }
  q.push({sr, sc});
  memset(pre, -1, sizeof(pre));
  auto is_valid = [&](int x, int y) -> bool {
    return x >= 1 && x <= n && y >= 1 && y <= m && grid[x][y] == '.' &&
           pre[x][y] == -1;
  };

  auto is_edge = [&](int x, int y) -> bool {
    return grid[x][y] == 'A' && (x == 1 || x == n || y == 1 || y == m);
  };

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    if (is_edge(i, j)) {
      escaped = true;
      er = i;
      ec = j;
      break;
    }

    for (int d = 0; d < 4; d++) {
      int ni = i + dx[d], nj = j + dy[d];
      if (is_valid(ni, nj)) {
        pre[ni][nj] = d;
        q.push({ni, nj});
        grid[ni][nj] = grid[i][j];
      }
    }
  }

  if (!escaped) {
    cout << "NO\n";
  } else {
    string path = "";
    cout << "YES\n";
    while (er != sr || ec != sc) {
      int d = pre[er][ec];
      path += dirc[d];
      er -= dx[d];
      ec -= dy[d];
    }
    reverse(path.begin(), path.end());
    cout << path.size() << '\n' << path << '\n';
  }

  return 0;
}
