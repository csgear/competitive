// https://www.acwing.com/problem/content/1142/
// 1140. 最短网络

#include <bits/stdc++.h>
using namespace std;

const int N = 110, M = N * N;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const { return w < other.w; }
};

Edge edges[M];
int father[N];
int n, m = 0;

int find(int x) {
    if (x != father[x]) father[x] = find(father[x]);
    return father[x];
}

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) father[fx] = fy;
}

int kruskal() {
    sort(edges, edges + m);
    iota(father + 1, father + n + 1, 1);

    int res = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u) != find(v)) {
            merge(u, v);
            res += w;
        }
    }

    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w;
            cin >> w;
            if (i < j) {
                edges[m++] = {i, j, w};
            }
        }
    }

    cout << kruskal() << endl;

    return 0;
}