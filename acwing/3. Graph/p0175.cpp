// https://www.acwing.com/problem/content/177/

#include <bits/stdc++.h>
using namespace std;

const int N = 510;
const int M = N * N;

char g[N][N];
int dist[N][N];
bool vis[N][N];
int n, m;

int dx[] = {-1, 1, 1, -1};
int dy[] = {-1, -1, 1, 1};
int ix[] = {-1, 0, 0, -1};
int iy[] = {-1, -1, 0, 0};
char cs[] = {'\\', '/', '\\', '/'};

int bfs() {
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
    deque<pair<int, int>> q;

    dist[0][0] = 0;
    q.push_back({0, 0});

    while (!q.empty()) {
        auto t = q.front();
        q.pop_front();
        int x = t.first, y = t.second;
        if (x == n && y == m) return dist[x][y];
        if (vis[x][y]) continue;
        vis[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx > n || ny < 0 || ny > m) continue;
            // int iix = (dx[i] < 0) ? -1 : 0;
            // int iiy = (dy[i] < 0) ? -1 : 0;
            // int gx = x + iix, gy = y + iiy;
            int gx = x + ix[i], gy = y + iy[i];
            int w = (g[gx][gy] != cs[i]);
            int d = dist[x][y] + w;
            if (d < dist[nx][ny]) {
                dist[nx][ny] = d;
                if (!w) {
                    q.push_front({nx, ny});
                } else {
                    q.push_back({nx, ny});
                }
            }
        }
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> g[i];
        }
        if ((n + m) & 1)
            cout << "NO SOLUTION" << endl;
        else {
            cout << bfs() << endl;
        }
    }
    return 0;
}