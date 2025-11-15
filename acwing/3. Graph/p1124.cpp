// https://www.acwing.com/problem/content/1126/
// 1124. 骑马修栅栏

#include <bits/stdc++.h>
using namespace std;

const int N = 510;

int n = 500, m;

int g[N][N];
int d[N];
int path[N], cnt;

void dfs(int u) {
    for (int i = 1; i <= n; i++) {
        if (g[u][i]) {
            g[u][i]--, g[i][u]--;
            dfs(i);
        }
    }
    path[cnt++] = u;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u][v]++, g[v][u]++;
        d[u]++, d[v]++;
    }

    int start = 1;

    while (d[start] == 0) start++;

    for (int i = 1; i <= n; i++) {
        if (d[i] & 1) {
            start = i;
            break;
        }
    }

    dfs(start);

    for (int i = cnt - 1; i >= 0; i--) {
        cout << path[i] << endl;
    }

    return 0;
}