// https://cses.fi/problemset/task/1751

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int len[MAXN] = {0};
int nxt[MAXN];
bool vis[MAXN];
vector<int> path;

void dfs(int s) {
    path.push_back(s);
    vis[s] = true;
    int x = nxt[s];

    while (!vis[x]) {
        vis[x] = true;
        path.push_back(x);
        x = nxt[x];
    }

    int cycle_start_dist;
    if (len[x] != 0) {
        cycle_start_dist = len[x];
    } else {
        int cycle_len = 0;
        vector<int> cycle_nodes;

        while (true) {
            int node = path.back();
            path.pop_back();
            cycle_nodes.push_back(node);
            cycle_len++;
            if (node == x) {
                for (int cycle_node : cycle_nodes) {
                    len[cycle_node] = cycle_len;
                }
                break;
            }
        }
        cycle_start_dist = cycle_len;
    }

    while (!path.empty()) {
        cycle_start_dist++;
        int node = path.back();
        path.pop_back();
        len[node] = cycle_start_dist;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> nxt[i];
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << len[i];
        if (i < n) cout << " ";
    }
    cout << "\n";

    return 0;
}