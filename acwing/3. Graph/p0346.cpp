// https://www.acwing.com/problem/content/348/
// 346. 走廊泼水节

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 6010;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const { return w < other.w; }
} e[N];

int fa[N], sz[N];

int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n - 1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            e[i] = {u, v, w};
        }

        sort(e, e + n - 1);

        for (int i = 1; i <= n; i++) {
            fa[i] = i, sz[i] = 1;
        }

        ll res = 0;
        for (int i = 0; i < n - 1; i++) {
            auto [u, v, w] = e[i];
            u = find(u), v = find(v);
            if (u != v) {
                res += (ll)(sz[u] * sz[v] - 1) * (w + 1);
                fa[u] = v;
                sz[v] += sz[u];
            }
        }
        cout << res << endl;
    }

    return 0;
}