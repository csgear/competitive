// https://www.acwing.com/problem/content/345/
// 343. 排序

#include <bits/stdc++.h>
using namespace std;

const int N = 26;

bool g[N][N], d[N][N];
bool st[N];

int n, m;

void floyd() {
    memcpy(d, g, sizeof g);
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = d[i][j] || (d[i][k] && d[k][j]);
            }
        }
    }
}

int check() {
    for (int i = 0; i < n; i++) {
        if (d[i][i]) return 2;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (!d[i][j] && !d[j][i]) return 0;
        }
    }
    return 1;
}

char get_min() {
    for (int i = 0; i < n; i++)
        if (!st[i]) {
            bool flag = true;
            for (int j = 0; j < n; j++)
                if (!st[j] && d[j][i]) {
                    flag = false;
                    break;
                }
            if (flag) {
                st[i] = true;
                return 'A' + i;
            }
        }
}

int main() {
    while (cin >> n >> m, n || m) {
        memset(g, 0, sizeof g);
        int type = 0, t;
        for (int i = 1; i <= m; i++) {
            char str[5];
            cin >> str;
            int a = str[0] - 'A', b = str[2] - 'A';
            if (!type) {
                g[a][b] = true;
                floyd();
                type = check();
                if (type) t = i;
            }
        }
        if (type == 0) {
            cout << "Sorted sequence cannot be determined." << endl;
        } else if (type == 2) {
            cout << "Inconsistency found after " << t << " relations." << endl;
        } else {
            memset(st, 0, sizeof st);
            cout << "Sorted sequence determined after " << t << " relations: ";
            for (int i = 0; i < n; i++) {
                cout << get_min();
            }
            cout << "." << endl;
        }
    }
    return 0;
}