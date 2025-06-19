// https://atcoder.jp/contests/abc409/tasks/abc409_e

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

// 链式前向星
struct Edge {
    int to, next, w;
} edges[MAXN << 1];

int head[MAXN], cnt;

int n;
long long ans = 0;
int sm[MAXN], x[MAXN];

void build() {
    fill(head, head + n + 1, 0);
    cnt = 1;
}

void add(int u, int v, int w) {
    edges[cnt].to = v;
    edges[cnt].next = head[u];
    edges[cnt].w = w;
    head[u] = cnt++;
}

void dfs(int u, int fa) {
    sm[u] = x[u];
    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (v == fa) continue;
        dfs(v, u);
        int c = abs(sm[v]);
        ans += 1ll * c * edges[i].w;
        sm[u] += sm[v];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    build();
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}