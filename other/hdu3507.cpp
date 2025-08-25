// https://acm.hdu.edu.cn/showproblem.php?pid=3507

#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 500010;

int n, m, q[N];
LL s[N], f[N];

LL dy(int i, int j) { return f[i] + (s[i] - s[j]) * (s[i] - s[j]); }

LL dx(int i, int j) { return (s[i] - s[j]); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            s[i] += s[i - 1];
        }

        int h = 1, t = 0;

        f[0] = 0;

        // add point 0 ~ n -1 to the convex hull
        for (int i = 1; i <= n; i++) {
            while (h < t &&
                   dy(i - 1, q[t]) * dx(q[t], q[t - 1]) <= dy(q[t], q[t - 1]) * dx(i - 1, q[t]))
                t--;

            q[++t] = i - 1;

            while (h < t && dy(q[h + 1], q[h]) <= 2 * s[i] * dx(q[h + 1], q[h])) h++;

            int j = q[h];

            f[i] = f[j] + (s[i] - s[j]) * (s[i] - s[j]) + m;
        }
        cout << f[n] << endl;
    }

    return 0;
}