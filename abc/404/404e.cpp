// https://atcoder.jp/contests/abc404/tasks/abc404_e

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000 + 5;

int n;
int C[MAXN], A[MAXN];
int f[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        cin >> C[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        cin >> A[i];
    }

    f[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        f[i] = 1e9;
        int cnt = 0;
        for (int j = i + 1; j <= n - 1; j++) {
            if (j - C[j] <= i) {
                f[i] = min(f[i], f[j] + cnt + (A[j] > 0 || f[j] > 0));
            }
            if (A[j] && (j - C[j]) > i) break;
            if (A[j]) cnt++;
        }
    }

    cout << f[0] << endl;

    return 0;
}