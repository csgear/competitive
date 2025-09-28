// https://www.acwing.com/problem/content/209/

#include <bits/stdc++.h>
using namespace std;

double a[20][20], b[20], c[20][20];
int n;

int gauss() {
    int rank = 0;
    for (int i = 1; i <= n; i++) {
        int t = 0;
        for (int j = rank + 1; j <= n; j++) {
            if (fabs(c[j][i]) > 1e-9) {
                if (t == 0 || fabs(c[j][i]) > fabs(c[t][i])) {
                    t = j;
                }
            }
        }

        if (t == 0) continue;
        rank++;
        if (t != rank) {
            for (int k = 1; k <= n; k++) {
                swap(c[rank][k], c[t][k]);
            }
            swap(b[rank], b[t]);
        }

        for (int k = 1; k <= n; k++) {
            if (rank != k && fabs(c[k][i]) > 1e-9) {
                double ratio = c[k][i] / c[rank][i];
                for (int j = 1; j <= n; j++) {
                    c[k][j] -= ratio * c[rank][j];
                }
                b[k] -= ratio * b[rank];
            }
        }
    }
    return rank;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j] = 2 * (a[i][j] - a[i + 1][j]);
            b[i] += a[i][j] * a[i][j] - a[i + 1][j] * a[i + 1][j];
        }
    }

    int rank = gauss();

    for (int i = 1; i <= rank; i++) {
        double result = b[i] / c[i][i];
        if (fabs(result) < 1e-9) {
            result = 0.0;
        }
        cout << fixed << setprecision(3) << result << " ";
    }
    cout << endl;
}