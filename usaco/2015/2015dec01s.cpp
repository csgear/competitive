// https://usaco.org/index.php?page=viewproblem2&cpid=570
// USACO 2015 December Contest, Silver
// Problem 1. Switching on the Lights

#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
int ans = 1;
bool vis[N][N];
bool light[N][N];
// faster than map
vector<pair<int, int>> switches[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool checkConnected(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX <= 0 || newY <= 0 || newX > n || newY > n) {
            continue;
        }

        if (vis[newX][newY]) {
            return true;
        }
    }
    return false;
}

void floodfill(int x, int y) {
    if (x <= 0 || y <= 0 || x > n || y > n || vis[x][y] || !light[x][y]) {
        return;
    }

    if (!checkConnected(x, y) && !(x == 1 && y == 1)) {
        return;
    }

    vis[x][y] = true;

    for (int i = 0; i < 4; i++) {
        floodfill(x + dx[i], y + dy[i]);
    }

    for (int i = 0; i < switches[x][y].size(); i++) {
        int newX = switches[x][y][i].first;
        int newY = switches[x][y][i].second;

        if (!light[newX][newY]) {
            ans++;
        }

        light[newX][newY] = true;

        floodfill(newX, newY);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        switches[x][y].push_back({a, b});
    }

    light[1][1] = true;

    floodfill(1, 1);

    cout << ans << endl;

    return 0;
}