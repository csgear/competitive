// https://www.acwing.com/problem/content/239/

#include <bits/stdc++.h>
using namespace std;

int fa[200010];

int find(int u) {
    if (u == fa[u]) return u;
    return fa[u] = find(fa[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) fa[u] = v;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> eq;
    vector<pair<int, int>> neq;
    vector<int> num;

    for (int i = 1; i <= 2 * n; i++) fa[i] = i;
    for (int i = 1; i <= n; i++) {
        int u, v, e;
        cin >> u >> v >> e;
        num.push_back(u);
        num.push_back(v);
        if (e == 1) {
            eq.emplace_back(u, v);
        } else {
            neq.emplace_back(u, v);
        }
    }

    // discretization
    vector<int> disc(num);
    sort(disc.begin(), disc.end());
    disc.erase(unique(disc.begin(), disc.end()), disc.end());

    auto query = [&](int x) { return lower_bound(disc.begin(), disc.end(), x) - disc.begin() + 1; };

    for (auto& [u, v] : eq) {
        merge(query(u), query(v));
    }

    for (auto& [u, v] : neq) {
        if (find(query(u)) == find(query(v))) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}