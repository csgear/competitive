// https://cses.fi/problemset/task/1684

#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200005], reverse_graph[200005];
vector<int> order;
bool vis[200005];
int scc_count = 0;
int component[200005];
bool assignment[200005];

void dfs1(int s) {
    if (vis[s]) return;
    vis[s] = true;
    for (auto i : graph[s]) dfs1(i);
    order.push_back(s);
}

void dfs2(int s) {
    if (vis[s]) return;
    vis[s] = true;
    component[s] = scc_count;
    for (auto i : reverse_graph[s]) dfs2(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        char x, y;
        int a, b;
        cin >> x >> a >> y >> b;

        if (x == '-') a = 2 * m - a + 1;
        if (y == '-') b = 2 * m - b + 1;

        graph[2 * m - a + 1].push_back(b);
        graph[2 * m - b + 1].push_back(a);
        reverse_graph[b].push_back(2 * m - a + 1);
        reverse_graph[a].push_back(2 * m - b + 1);
    }

    // Kosaraju's algorithm
    for (int i = 1; i <= 2 * m; i++) {
        if (!vis[i]) dfs1(i);
    }

    memset(vis, 0, sizeof vis);
    for (auto it = order.rbegin(); it != order.rend(); it++) {
        int x = *it;
        if (!vis[x]) {
            dfs2(x);
            scc_count++;
        }
    }

    for (int i = 1; i <= m; i++) {
        if (component[i] == component[2 * m - i + 1]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        assignment[i] = (component[i] > component[2 * m - i + 1]);
    }

    for (int i = 1; i <= m; i++) {
        cout << (assignment[i] ? '+' : '-');
    }
    cout << "\n";

    return 0;
}