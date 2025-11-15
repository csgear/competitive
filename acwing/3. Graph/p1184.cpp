// https://www.acwing.com/problem/content/1186/
// 1184. 欧拉回路

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;

struct Edge {
    int to, nxt;
} edges[M << 1];

int head[N], cnt = -1;
int din[N], dout[N];
bool used[M << 1];
int ans[M], tot;

int type;
int n, m;

void add_edge(int u, int v) {
    edges[++cnt] = {v, head[u]};
    head[u] = cnt;
}

void dfs(int u) {
    for (int& i = head[u]; i != -1;) {
        int eid = i;
        i = edges[i].nxt;  // critical: remove edge from adjacency list
        if (used[eid]) continue;
        used[eid] = true;
        if (type == 1) {
            used[eid ^ 1] = true;
        }

        dfs(edges[eid].to);

        if (type == 1) {
            int k = eid / 2 + 1;
            ans[tot++] = (eid & 1) ? -k : k;
        } else {
            ans[tot++] = eid + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(head, -1, sizeof head);

    cin >> type >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        if (type == 1) {
            add_edge(v, u);
        }
        dout[u]++;
        din[v]++;
    }

    if (type == 1) {
        for (int i = 1; i <= n; i++) {
            if ((din[i] + dout[i]) % 2 != 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (din[i] != dout[i]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (head[i] != -1) {
            dfs(i);
            break;
        }
    }

    if (tot != m) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    for (int i = tot - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}