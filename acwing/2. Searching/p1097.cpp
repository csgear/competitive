// https://www.acwing.com/problem/content/1099/
// DFS solution

#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m, ans = 0;
char mp[N][N];

void dfs(int x, int y) {
    mp[x][y] = '.';
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] == 'W') {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) cin >> mp[i][j];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (mp[i][j] == 'W') dfs(i, j), ans++;
    cout << ans << endl;
    return 0;
}
