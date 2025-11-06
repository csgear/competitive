// https://www.acwing.com/problem/content/1145/
// 1143. 联络员

#include <bits/stdc++.h>
using namespace std;

const int N = 2010, M = 10010;

int n, m;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const { return w < other.w; }
} e1[M], e2[M];
int cnt;

int fa[N];

int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int u, int v) {
    int fu = find(u), fv = find(v);
    if (fu != fv) fa[fu] = fv;
}

int main() {
    cin >> n >> m;

    int res = 0;

    for (int i = 1; i <= n; i++) fa[i] = i;

    for (int i = 1; i <= m; i++) {
        int type, u, v, w;
        cin >> type >> u >> v >> w;
        if (type == 1) {
            merge(u, v);
            res += w;
        } else {
            e2[++cnt] = {u, v, w};
        }
    }

    sort(e2 + 1, e2 + cnt + 1);

    for (int i = 1; i <= cnt; i++) {
        int u = e2[i].u, v = e2[i].v, w = e2[i].w;
        if (find(u) != find(v)) {
            merge(u, v);
            res += w;
        }
    }

    cout << res << endl;

    return 0;
}