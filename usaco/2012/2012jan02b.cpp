// https://usaco.org/index.php?page=viewproblem2&cpid=104
// USACO 2012 January Contest, Bronze Division
// Problem 2. Haybale Stacking

#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;
int b[N];

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        int l, r;
        cin >> l >> r;
        b[l]++;
        b[r + 1]--;
    }

    for (int i = 1; i <= n; i++) b[i] += b[i - 1];

    sort(b + 1, b + n + 1);

    cout << b[(n + 1) / 2] << endl;

    return 0;
}