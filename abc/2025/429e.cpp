// https://atcoder.jp/contests/abc429/tasks/abc429_e

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int INF = 1e9;

struct Node {
    int id, d, src;
};

vector<int> g[N];
string str;
queue<Node> q;
int dist1[N], dist2[N], from[N];

int n, m;

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cin >> str;
    str = " " + str;

    fill(dist1, dist1 + N, INF);
    fill(dist2, dist2 + N, INF);
    for (int i = 1; i <= n; i++) {
        if (str[i] == 'S') {
            dist1[i] = 0;
            from[i] = i;
            q.push({i, 0, i});
        }
    }
    while (!q.empty()) {
        Node node = q.front();
        q.pop();
        int u = node.id;
        int d = node.d;
        int src = node.src;
        for (int v : g[u]) {
            if (dist1[v] == INF) {
                dist1[v] = d + 1;
                from[v] = src;
                q.push({v, d + 1, src});
            } else if (from[v] != src && dist2[v] == INF) {
                dist2[v] = d + 1;
                q.push({v, d + 1, src});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (str[i] == 'D') {
            cout << dist1[i] + dist2[i] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
