// https://www.acwing.com/problem/content/1147/
// 1145. 北极通讯网络

#include <bits/stdc++.h>
using namespace std;

const int N = 510;
const double INF = 1e9;

struct Point {
    int x, y;
} pt[N];

double get_dist(int i, int j) {
    double dx = pt[i].x - pt[j].x;
    double dy = pt[i].y - pt[j].y;
    return sqrt(dx * dx + dy * dy);
}

int n, k;
double g[N][N];
double dist[N];
bool st[N];
double edges[N];

void prim() {
    fill(dist, dist + n + 1, INF);
    memset(st, 0, sizeof st);
    int edge_cnt = 0;

    dist[1] = 0;
    for (int i = 1; i <= n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
        }

        if (i > 1) edges[edge_cnt++] = dist[t];
        st[t] = true;

        for (int j = 1; j <= n; j++) {
            if (!st[j] && g[t][j] < dist[j]) {
                dist[j] = g[t][j];
            }
        }
    }

    sort(edges, edges + edge_cnt);
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> pt[i].x >> pt[i].y;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = get_dist(i, j);
        }
    }

    prim();

    if (n == 1) {
        cout << "0.00" << endl;
    } else if (k >= n) {
        cout << "0.00" << endl;
    } else {
        if (k == 0) {
            cout << fixed << setprecision(2) << edges[n - k - 1] << endl;
        } else {
            cout << fixed << setprecision(2) << edges[n - k - 1] << endl;
        }
    }

    return 0;
}