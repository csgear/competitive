// https://www.acwing.com/activity/content/problem/content/1482/

#include <bits/stdc++.h>
using namespace std;

const int N = 10;

bool vis[N][N];
int n, m, sx, sy;

int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int dfs(int x, int y, int step = 1) {
    int res = 0;

    if (step == n * m) return 1;

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || vis[nx][ny]) continue;
        vis[nx][ny] = true;
        res += dfs(nx, ny, step + 1);
        vis[nx][ny] = false;
    }

    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> sx >> sy;
        memset(vis, 0, sizeof vis);
        vis[sx][sy] = true;
        int ans = dfs(sx, sy);
        cout << ans << endl;
    }
    return 0;
}