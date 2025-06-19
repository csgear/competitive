// 树上问题专题4-树的直径
// 所有直径的公共部分
// 给定一棵树，边权都为正
// 打印直径长度、所有直径的公共部分有几条边
// 测试链接 : https://www.luogu.com.cn/problem/P3304

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n;
// 链式前向星
struct Edge {
    int to, next, w;
} edges[MAXN << 1];

int head[MAXN], cnt;

// 数的直径
long dist[MAXN];
int last[MAXN];
long diameter;
int st, ed;
bool diameterPath[MAXN];
int commonEdges;

void build() {
    fill(head, head + n + 1, 0);
    fill(diameterPath, diameterPath + n + 1, false);
    cnt = 1;
}

void add(int u, int v, int w) {
    edges[cnt].to = v;
    edges[cnt].next = head[u];
    edges[cnt].w = w;
    head[u] = cnt++;
}

void dfs(int u, int fa, long c) {
    last[u] = fa;
    dist[u] = c;
    for (int e = head[u]; e != 0; e = edges[e].next) {
        int v = edges[e].to;
        int w = edges[e].w;
        if (v != fa) {
            dfs(v, u, c + w);
        }
    }
}

void treeDiameter() {
    dfs(1, 0, 0);
    st = 1;
    for (int i = 2; i <= n; i++) {
        if (dist[i] > dist[st]) {
            st = i;
        }
    }
    dfs(st, 0, 0);
    ed = 1;
    for (int i = 2; i <= n; i++) {
        if (dist[i] > dist[ed]) {
            ed = i;
        }
    }
    diameter = dist[ed];
}

long maxDistanceExceptDiameter(int u, int fa, long c) {
    long ans = c;
    for (int e = head[u]; e != 0; e = edges[e].next) {
        int v = edges[e].to;
        int w = edges[e].w;
        if (v != fa && !diameterPath[v]) {
            ans = max(ans, maxDistanceExceptDiameter(v, u, c + w));
        }
    }
    return ans;
}

void commonPath() {
    treeDiameter();
    for (int i = ed; i != 0; i = last[i]) {
        diameterPath[i] = true;
    }
    int l = st;
    int r = ed;
    long maxDist = 0;
    for (int i = last[ed]; i != 0; i = last[i]) {
        maxDist = maxDistanceExceptDiameter(i, 0, 0);
        if (maxDist == diameter - dist[i]) {
            r = i;
        }
        if (maxDist == dist[i] && l == st) {
            l = i;
        }
    }
    if (l == r) {
        commonEdges = 0;
    } else {
        commonEdges = 1;
        for (int i = last[r]; i != l; i = last[i]) {
            commonEdges++;
        }
    }
}

int main() {
    cin >> n;
    build();
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    commonPath();

    // treeDiameter();

    cout << diameter << endl;
    cout << commonEdges << endl;
    return 0;
}