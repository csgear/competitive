// https://www.acwing.com/problem/content/175/

#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int g[N][N];
int d[N][N];

int n, m;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs() {
    memset(d, -1, sizeof d);
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 1) {
                q.push({i, j});
                d[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (d[nx][ny] == -1) {
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            g[i][j] = c - '0';
        }
    }

    bfs();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}