// https://atcoder.jp/contests/abc420/tasks/abc420_d

#include <bits/stdc++.h>

using namespace std;

const int N = 505;
using LL = long long;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
char s[N][N];
int vis[N][N][2];

struct Point {
    int x, y, state, depth;
};

int main() {
    cin >> n >> m;
    queue<Point> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
            if (s[i][j] == 'S') {
                q.push({i, j, 0, 0});
                vis[i][j][0] = 1;
            }
        }
    }
    while (!q.empty()) {
        Point now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            Point nxt = {now.x + dx[i], now.y + dy[i], now.state, now.depth + 1};

            if (nxt.x < 1 || nxt.x > n || nxt.y < 1 || nxt.y > m) {
                continue;
            }
            if (s[nxt.x][nxt.y] == '#') {
                continue;
            } else if (s[nxt.x][nxt.y] == 'G') {
                cout << nxt.depth << endl;
                return 0;
            } else if (s[nxt.x][nxt.y] == 'o' && nxt.state == 1) {
                continue;
            } else if (s[nxt.x][nxt.y] == 'x' && nxt.state == 0) {
                continue;
            } else if (s[nxt.x][nxt.y] == '?') {
                nxt.state = !nxt.state;
            }

            if (vis[nxt.x][nxt.y][nxt.state]) {
                continue;
            }
            vis[nxt.x][nxt.y][nxt.state] = 1;
            q.push(nxt);
        }
    }
    cout << -1 << endl;
    return 0;
}