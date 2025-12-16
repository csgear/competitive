// https://www.acwing.com/problem/content/1127/
// 1125. 牛的旅行

#include <bits/stdc++.h>
using namespace std;

const int N = 200;
const double INF = 1e20;

struct Point {
    int x, y;
} pts[N];

char graph[N][N];
double dist[N][N], max_dist[N];
int n;

double get_distance(Point& a, Point& b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
            if (i == j)
                dist[i][j] = 0;
            else if (graph[i][j] == '1')
                dist[i][j] = get_distance(pts[i], pts[j]);
            else
                dist[i][j] = INF;
        }
    }

    floyd();

    for (int i = 1; i <= n; i++) {
        max_dist[i] = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] < INF) {
                max_dist[i] = max(max_dist[i], dist[i][j]);
            }
        }
    }

    double res1 = 0;
    for (int i = 1; i <= n; i++) {
        res1 = max(res1, max_dist[i]);
    }

    double res2 = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] >= INF) {
                double d = get_distance(pts[i], pts[j]);
                res2 = min(res2, max_dist[i] + max_dist[j] + d);
            }
        }
    }

    printf("%.6f\n", max(res1, res2));

    return 0;
}
