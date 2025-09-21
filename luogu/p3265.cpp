// https://www.luogu.com.cn/problem/P3265

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
const int MAXM = 505;

struct Node {
    double a[MAXM];
    int w;
} nodes[MAXN];
int b[MAXM];
int cnt, cost;

int n, m;

bool insert(int i) {
    for (int j = 1; j <= m; j++) {
        if (abs(nodes[i].a[j]) > 1e-5) {
            if (b[j] == 0) {
                b[j] = i;
                return true;
            } else {
                double t = nodes[i].a[j] / nodes[b[j]].a[j];
                for (int k = j; k <= m; k++) {
                    nodes[i].a[k] -= t * nodes[b[j]].a[k];
                }
            }
        }
    }
    return false;
}

void linear_basis_gauss() {
    for (int i = 1; i <= n; i++) {
        if (insert(i)) {
            cnt++;
            cost += nodes[i].w;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> nodes[i].a[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> nodes[i].w;
    }

    sort(nodes + 1, nodes + n + 1, [](const Node& u, const Node& v) { return u.w <= v.w; });

    linear_basis_gauss();

    cout << cnt << " " << cost << "\n";

    return 0;
}