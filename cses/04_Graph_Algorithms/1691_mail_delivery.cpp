// https://cses.fi/problemset/task/1691

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXM = 200005;

struct Edge {
    int to, next;
    bool used;
} edges[MAXM * 2];

int head[MAXN], cnt = 1;
int degree[MAXN];
int cur[MAXN];

void add_edge(int u, int v) {
    edges[cnt] = {v, head[u], false};
    head[u] = cnt++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add_edge(a, b);
        add_edge(b, a);
        degree[a]++;
        degree[b]++;
    }

    for (int i = 1; i <= n; i++) {
        cur[i] = head[i];
    }

    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 != 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    vector<int> circuit;
    stack<int> path;
    path.push(1);

    while (!path.empty()) {
        int v = path.top();
        bool found = false;

        while (cur[v] != 0 && edges[cur[v]].used) {
            cur[v] = edges[cur[v]].next;
        }

        if (cur[v] != 0) {
            int i = cur[v];
            edges[i].used = true;
            if (i % 2 == 1) {
                edges[i + 1].used = true;
            } else {
                edges[i - 1].used = true;
            }
            path.push(edges[i].to);
        } else {
            circuit.push_back(v);
            path.pop();
        }
    }

    if (circuit.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int i = circuit.size() - 1; i >= 0; i--) {
        cout << circuit[i];
        if (i > 0) cout << " ";
    }
    cout << "\n";

    return 0;
}
