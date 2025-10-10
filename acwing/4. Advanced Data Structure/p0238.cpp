// https://www.acwing.com/problem/content/240/

#include <bits/stdc++.h>
using namespace std;

const int N = 30010;

int fa[N], sz[N], depth[N];

int find(int u) {
    if (u != fa[u]) {
        int root = find(fa[u]);
        depth[u] += depth[fa[u]];
        fa[u] = root;
    }
    return fa[u];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < N; i++) {
        fa[i] = i;
        sz[i] = 1;
        depth[i] = 0;
    }
    int t;
    cin >> t;

    while (t--) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == 'M') {
            int pa = find(a), pb = find(b);
            if (pa != pb) {
                fa[pa] = pb;
                depth[pa] = sz[pb];
                sz[pb] += sz[pa];
            }
        } else {
            if (find(a) != find(b)) {
                cout << -1 << '\n';
            } else {
                cout << max(0, abs(depth[a] - depth[b]) - 1) << '\n';
            }
        }
    }

    return 0;
}