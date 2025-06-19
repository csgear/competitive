// https://cses.fi/problemset/task/1674

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int sub[MAXN];

int dfs(int node) {
    int cnt = 0;
    for (int v : adj[node]) {
        cnt += dfs(v) + 1;
    }
    sub[node] = cnt;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << sub[i] << " ";
    }
    cout << endl;
    return 0;
}