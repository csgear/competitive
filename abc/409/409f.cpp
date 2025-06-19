// https://atcoder.jp/contests/abc409/tasks/abc409_f

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3000 + 5;

struct Node {
    int u, v, w;
    bool operator<(const Node &a) const { return w > a.w; }
};

priority_queue<Node> pq;
int x[MAXN], y[MAXN];
int fa[MAXN];

int find(int u) {
    if (fa[u] == u) return u;
    return fa[u] = find(fa[u]);
}

void merge(int u, int v) {
    int fx = find(u);
    int fy = find(v);
    if (fx != fy) {
        fa[fx] = fy;
    }
}

int d(int i, int j) { return abs(x[i] - x[j]) + abs(y[i] - y[j]); }

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            pq.push({i, j, d(i, j)});
        }
    }
    int op;
    for (int i = 1; i <= q; i++) {
        cin >> op;
        if (op == 1) {
            n++;
            cin >> x[n] >> y[n];
            for (int j = 1; j <= n - 1; j++) {
                pq.push({j, n, d(j, n)});
            }
            fa[n] = n;
        } else if (op == 2) {
            while (!pq.empty() && find(pq.top().u) == find(pq.top().v)) {
                pq.pop();
            }
            if (pq.empty()) {
                cout << "-1" << endl;
                continue;
            }
            int k = pq.top().w;
            cout << k << endl;
            while (!pq.empty() && pq.top().w == k) {
                merge(pq.top().u, pq.top().v);
                pq.pop();
            }
        } else if (op == 3) {
            int u, v;
            cin >> u >> v;
            if (find(u) == find(v)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
