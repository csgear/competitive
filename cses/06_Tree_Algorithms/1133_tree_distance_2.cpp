// https://cses.fi/problemset/task/1133

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
const int MAXM = 4e5 + 5;

struct Edge {
    int to, next;
} edges[MAXM];

int head[MAXN], tot = 0;
ll cnt[MAXN], res[MAXN];
int n;

void add_edge(int u, int v) {
    edges[++tot] = {v, head[u]};
    head[u] = tot;
}

void postOrrder(int u, int p) {
    cnt[u] = 1;
    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (v == p) continue;
        postOrrder(v, u);
        cnt[u] += cnt[v];
        res[u] += res[v] + cnt[v];
    }
}

void preOrder(int u, int p) {
    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (v == p) continue;
        res[v] = res[u] - cnt[v] + (n - cnt[v]);
        preOrder(v, u);
    }
}

int main() {
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }

    postOrrder(1, 0);
    preOrder(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}