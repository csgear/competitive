// https://atcoder.jp/contests/abc405/tasks/abc405_d

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const char dc[4] = {'v', '>', '^', '<'};

const int N = 1005;

int n, m;
char mp[N][N];

struct Node {
    int x, y, d;
};

queue<Node> q;

int dist[N][N];

void solve() {
    cin >> n >> m;
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'E') {
                q.push({i, j, 0});
                dist[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        auto [x, y, d] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            int d1 = d + 1;
            if (x1 < 1 || x1 > n || y1 < 1 || y1 > m) continue;
            if (mp[x1][y1] == '#') continue;
            if (dist[x1][y1] > d1) {
                dist[x1][y1] = d1;
                q.push({x1, y1, d1});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == '.') {
                for (int k = 0; k < 4; k++) {
                    int x1 = i + dx[k];
                    int y1 = j + dy[k];
                    if (x1 < 1 || x1 > n || y1 < 1 || y1 > m) continue;
                    if (dist[x1][y1] == dist[i][j] - 1) {
                        mp[i][j] = dc[k];
                        break;
                    }
                }
            }
            cout << mp[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}