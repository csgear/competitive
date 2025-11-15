// https://www.acwing.com/problem/content/1144/
// 1142. 繁忙的都市

#include <bits/stdc++.h>
using namespace std;

const int N = 310, M = 8010;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const { return w < other.w; }
} edges[M];

int parent[N];
int res = 0;

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
            res = w;
            cnt++;
            if (cnt == n - 1) break;
        }
    }
    return cnt == n - 1 ? mst : -1;
}

int main() {
    int n, k;
    cin >> n >> k;

    int tot = 0;
    for (int i = 1; i <= k; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        tot += edges[i].w;
    }

    cout << n - 1 << " " << res << endl;
    return 0;
}
