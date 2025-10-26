// https://www.acwing.com/problem/content/1026/
// Multiple knapsack with binary optimization
// Each item has limited quantity, optimize with binary grouping
// State: f[i] = max value with capacity i

#include <bits/stdc++.h>
using namespace std;

const int M = 2e4 + 10;
const int N = 50;

int w[N];
int f[M];

int n, m;

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= w[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << m - f[m] << endl;
    return 0;
}