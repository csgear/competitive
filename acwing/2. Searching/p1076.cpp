// https://www.acwing.com/problem/content/1078/

#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n;
int a[N][N];
bool vis[N][N];

queue<pair<int, int>> q;
pair<int, int> pre[N][N];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vis[n - 1][n - 1] = true;
    q.push({n - 1, n - 1});

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= n || vis[x][y] || a[x][y] == 1) continue;
            vis[x][y] = true;
            pre[x][y] = t;
            q.push({x, y});
        }
    }

    int x = 0, y = 0;

    while (x != n - 1 || y != n - 1) {
        cout << x << " " << y << "\n";
        auto t = pre[x][y];
        x = t.first;
        y = t.second;
    }
    cout << n - 1 << " " << n - 1 << "\n";
    return 0;
}