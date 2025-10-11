// https://www.acwing.com/problem/content/1099/
// Union-Find solution

#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m;
char mp[N][N];
int parent[N * N];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void merge(int x, int y) {
    int px = find(x), py = find(y);
    if (px != py) parent[px] = py;
}

int getId(int x, int y) { return (x - 1) * m + (y - 1); }

int main() {
    cin >> n >> m;

    for (int i = 0; i < n * m; i++) parent[i] = i;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) cin >> mp[i][j];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (mp[i][j] == 'W') {
                for (int k = 0; k < 8; ++k) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] == 'W') {
                        merge(getId(i, j), getId(nx, ny));
                    }
                }
            }
        }
    }

    set<int> ponds;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (mp[i][j] == 'W') {
                ponds.insert(find(getId(i, j)));
            }
        }
    }

    cout << ponds.size() << endl;
    return 0;
}