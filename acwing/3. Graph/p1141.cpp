// https://www.acwing.com/problem/content/1143/
// 1141. 局域网

#include <bits/stdc++.h>
using namespace std;

const int N = 110, M = 220;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const { return w < other.w; }
} edges[M];

int parent[N];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void merge(int a, int b) { parent[find(a)] = find(b); }

int kruskal(int n, int k) {
    sort(edges + 1, edges + k + 1);

    for (int i = 1; i <= n; i++) parent[i] = i;

    int mst = 0, cnt = 0;
    for (int i = 1; i <= k; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u) != find(v)) {
            merge(u, v);
            mst += w;
            cnt++;
            if (cnt == n - 1) break;
        }
    }
    return mst;
}

int main() {
    int n, k;
    cin >> n >> k;

    int tot = 0;
    for (int i = 1; i <= k; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        tot += edges[i].w;
    }

    int mst = kruskal(n, k);
    cout << tot - mst << endl;
    return 0;
}
