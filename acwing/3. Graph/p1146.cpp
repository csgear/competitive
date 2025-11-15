
// https://www.acwing.com/problem/content/1148/
// 1146. 新的开始

#include <bits/stdc++.h>
using namespace std;

const int N = 310, INF = 1e9;

int g[N][N];
int dist[N];
bool st[N];
int n;

int prim() {
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    int res = 0;

    for (int i = 0; i <= n; i++) {
        int t = -1;
        for (int j = 0; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
        }
        st[t] = true;
        res += dist[t];

        for (int j = 0; j <= n; j++) {
            dist[j] = min(dist[j], g[t][j]);
        }
    }
    return res;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> g[0][i];
        g[i][0] = g[0][i];
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> g[i][j];

    cout << prim() << endl;

    return 0;
}
