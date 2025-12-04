// https://www.acwing.com/problem/content/1077/
// 1075. 数字转换

#include <bits/stdc++.h>
using namespace std;

const int N = 50010;

struct Edge {
    int to, next;
} edge[N];

int head[N], idx = -1;
bool st[N];
int ans, n, s[N], f[N];

void add(int u, int v) {
    edge[++idx] = {v, head[u]};
    head[u] = idx;
}

int dfs(int u) {
    int d1 = 0, d2 = 0;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        int d = dfs(v) + 1;
        if (d >= d1) {
            d2 = d1;
            d1 = d;
        } else if (d > d2) {
            d2 = d;
        }
    }
    ans = max(ans, d1 + d2);
    return d1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = i * 2; j <= n; j += i) s[j] += i;

    memset(head, -1, sizeof head);

    for (int i = 2; i <= n; i++) {
        if (s[i] < i) {
            st[i] = true;
            add(s[i], i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!st[i]) dfs(i);
    }

    cout << ans << endl;

    return 0;
}
