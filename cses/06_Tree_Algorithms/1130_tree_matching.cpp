// https://cses.fi/problemset/task/1130

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
int dp[N][2];

void dfs(int u, int parent) {
    dp[u][0] = 0;
    dp[u][1] = 0;

    vector<int> children;
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        children.push_back(v);
    }

    for (int v : children) {
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }

    for (int v : children) {
        int candidate = dp[u][0] - max(dp[v][0], dp[v][1]) + dp[v][0] + 1;
        dp[u][1] = max(dp[u][1], candidate);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);

    cout << max(dp[1][0], dp[1][1]) << endl;
    return 0;
}