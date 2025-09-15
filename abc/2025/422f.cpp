// https://atcoder.jp/contests/abc422/tasks/abc422_f

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> W(n);
    for (int i = 0; i < n; i++) {
        cin >> W[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // dp[i] = map of {weight_sum -> distance_sum}
    vector<unordered_map<ll, ll>> dp(n);

    using T = tuple<ll, int, ll>;
    priority_queue<T, vector<T>, greater<T>> pq;

    dp[0][W[0]] = 0;
    pq.emplace(0, 0, W[0]);

    while (!pq.empty()) {
        auto [d, u, w] = pq.top();
        pq.pop();

        if (dp[u].count(w) && dp[u][w] < d) continue;

        for (int v : adj[u]) {
            ll newDist = d + w;
            ll newWeight = w + W[v];

            bool better = true;
            for (auto& [cw, cd] : dp[v]) {
                if (cw <= newWeight && cd <= newDist) {
                    better = false;
                    break;
                }
            }

            if (better) {
                dp[v][newWeight] = newDist;
                pq.emplace(newDist, v, newWeight);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ll ans = LLONG_MAX;
        for (auto& [cw, cd] : dp[i]) {
            ans = min(ans, cd);
        }
        cout << (ans == LLONG_MAX ? -1 : ans) << "\n";
    }

    return 0;
}