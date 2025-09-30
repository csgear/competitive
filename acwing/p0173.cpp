// https://www.acwing.com/problem/content/175/

#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    vector<vector<int>> dist(n + 1, vector<int>(m + 1, -1));

    queue<pair<int, int>> q;

    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c;
            if (c == '1') {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dist[i][j] << " \n"[j == m];
        }
    }
    return 0;
}
