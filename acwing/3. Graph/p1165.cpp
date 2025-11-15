// https://www.acwing.com/problem/content/1167/
// 1165. 单词环

#include <bits/stdc++.h>
using namespace std;

const int N = 700;
const int M = 1e5 + 10;

struct Edge {
    int to, nxt, w;
} edges[M];

int head[N], cnt_edge = -1;
int n;
double dist[N];
int cnt[N];
bool inq[N];

void add_edge(int u, int v, int w) {
    edges[++cnt_edge] = {v, head[u], w};
    head[u] = cnt_edge;
}

bool check(double mid) {
    queue<int> q;

    memset(dist, 0, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(inq, 0, sizeof inq);

    for (int i = 0; i < 676; i++) {
        q.push(i);
        inq[i] = true;
    }

    int total_ops = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;

        for (int i = head[u]; ~i; i = edges[i].nxt) {
            int v = edges[i].to;
            double w = (double)edges[i].w - mid;
            if (dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if (++total_ops > 100000) return true;
                if (cnt[v] >= N) return true;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n, n) {
        memset(head, -1, sizeof head);
        cnt_edge = -1;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            if ((int)s.size() < 2) continue;
            int u = (s[0] - 'a') * 26 + (s[1] - 'a');
            int v = (s[s.size() - 2] - 'a') * 26 + (s[s.size() - 1] - 'a');
            add_edge(u, v, s.size());
        }
        if (!check(0)) {
            cout << "No solution" << endl;
        } else {
            double l = 0, r = 1000;
            while (r - l > 1e-4) {
                double mid = (l + r) / 2.0;
                if (check(mid)) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            cout << fixed << setprecision(2) << l << endl;
        }
    }

    return 0;
}