// https://www.acwing.com/problem/content/1142/
// 1140. 最短网络

#include <bits/stdc++.h>
using namespace std;

const int N = 110, INF = 1e9;

int g[N][N];
int dist[N];
bool st[N];
int n;

int prim() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    int res = 0;

    for (int i = 1; i <= n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
        }
        st[t] = true;
        res += dist[t];

        for (int j = 1; j <= n; j++) {
            if (!st[j]) dist[j] = min(dist[j], g[t][j]);
        }
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> g[i][j];

    cout << prim() << endl;

    return 0;
}
