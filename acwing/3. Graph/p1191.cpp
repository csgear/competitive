// https://www.acwing.com/problem/content/1193/
// 1191. 家谱树

#include <bits/stdc++.h>
using namespace std;

const int N = 110, M = N * N;

struct Edge {
    int to, next;
} edges[M];
int head[N], idx = -1;
int d[N];
int n;

void add_edge(int u, int v) {
    edges[++idx] = {v, head[u]};
    head[u] = idx;
}

void topsort() {
    queue<int> q;
    vector<int> res;

    for (int i = 1; i <= n; i++) {
        if (!d[i]) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            d[v]--;
            if (!d[v]) q.push(v);
        }
    }
    for (auto x : res) cout << x << " ";
    cout << endl;
}

int main() {
    memset(head, -1, sizeof head);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int son;
        while (cin >> son, son) {
            add_edge(i, son);
            d[son]++;
        }
    }

    topsort();
    return 0;
}