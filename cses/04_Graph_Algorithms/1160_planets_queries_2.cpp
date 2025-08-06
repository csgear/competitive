// https://cses.fi/problemset/task/1160

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    const int MAXLOG = 20;
    vector<vector<int>> lift(MAXLOG, vector<int>(n + 1));
    vector<int> dist(n + 1, 0);
    vector<bool> vis(n + 1, false);

    for (int i = 1; i <= n; i++) {
        cin >> lift[0][i];
    }

    for (int i = 1; i < MAXLOG; i++) {
        for (int j = 1; j <= n; j++) {
            lift[i][j] = lift[i - 1][lift[i - 1][j]];
        }
    }

    // Function to jump k steps from node x
    auto jump = [&](int x, int k) {
        for (int bit = 0; bit < MAXLOG && k > 0; bit++) {
            if (k & (1 << bit)) {
                x = lift[bit][x];
                k ^= (1 << bit);
            }
        }
        return x;
    };

    // DFS to compute distance to cycle for each node
    function<void(int)> dfs = [&](int s) {
        if (vis[s]) return;
        vis[s] = true;
        dfs(lift[0][s]);
        dist[s] = dist[lift[0][s]] + 1;
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        if (a == b) {
            cout << "0\n";
            continue;
        }

        // Case 1: b is on the path from a to cycle
        if (dist[a] >= dist[b] && jump(a, dist[a] - dist[b]) == b) {
            cout << dist[a] - dist[b] << "\n";
        }
        // Case 2: both eventually reach the same cycle
        else {
            int cycle_a = jump(a, dist[a]);  // a's position in cycle
            if (dist[cycle_a] >= dist[b] && jump(cycle_a, dist[cycle_a] - dist[b]) == b) {
                cout << dist[a] + dist[cycle_a] - dist[b] << "\n";
            } else {
                cout << "-1" << "\n";
            }
        }
    }

    return 0;
}
