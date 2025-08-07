// https://cses.fi/problemset/task/2164

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int child(int n, int k, int p) {
    int r = (n + p) / 2;
    if (k <= r) return k * 2 - p;
    int u = n % 2 == 0 ? p : 1 - p;
    return child(n - r, k - r, u) * 2 - 1 + p;
}

int find_kth_removed(int n, int k) {
    if (n == 1) return 1;
    // if k will be removed in current round,
    // if k in first half, return 2 * k
    // if k in second half, return 2 * k - n + 1, aka 2 * k % n
    if (k <= (n + 1) / 2) {
        if (2 * k > n)
            return 2 * k % n;
        else
            return 2 * k;
    }
    // if k will be removed in next round,
    // if n is even, return 2 * c - 1
    // if n is odd, return 2 * c + 1
    int c = find_kth_removed(n >> 1, k - (n + 1) / 2);
    if (n & 1)
        return 2 * c + 1;
    else
        return 2 * c - 1;
}

int main() {
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        ll n, k;
        cin >> n >> k;
        cout << find_kth_removed(n, k) << endl;
    }
    return 0;
}